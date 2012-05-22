/*******************************************************************
    Copyright (C) 2009 FreakLabs
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.
    4. This software is subject to the additional restrictions placed on the
       Zigbee Specification's Terms of Use.

    THIS SOFTWARE IS PROVIDED BY THE THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.

    Originally written by Christopher Wang aka Akiba.
    Please post support questions to the FreakLabs forum.

*******************************************************************/
/*!
    \file mem_heap.c
    \ingroup misc
    \brief Non fragmenting dynamic memory allocation heap controller

        This is the main file that implements the non-fragmenting dynamic
        memory allocation. Fragmentation is a major issue with embedded systems
        because they tend to leave holes in memory as you do multiple mallocs
        and frees. Eventually, your memory ends up looking like swiss cheeses
        and you will get to a point where you may have the necessary amount
        of free memory but it won't be contiguous. Hence, your malloc will fail
        and your program will crash and burn.

        Non fragmenting dynamic memory allocation uses Contiki's mmem.c managed
        memory library. It actually implements a pointer to a pointer to a memory
        block. A pointer to a pointer is called a handle. Hence the handle will
        always point to the real memory block pointer. However every time a mem
        block is freed, the memory will get compacted and made contiguous, hence
        removing any holes. Since the memory blocks can move around, you will need
        the handle to tell you the real instaneous position of the memory.
*/
/*******************************************************************/
#include "freakz.h"
#include "mmem.h"

/**************************************************************************/
/*!
        The mem pointer pool contains an array of all the memory pointers that
        are available to the stack. Each memory pointer can contain one block
        of memory allocated from the heap. Needless to say, if we run out of
        memory pointers, then that is just as bad as running out of memory.
*/
/**************************************************************************/
static mem_ptr_t mem_ptr_pool[MAX_MEM_PTR_POOL];

/**************************************************************************/
/*!
        Initialize the total memory heap.
*/
/**************************************************************************/
void mem_heap_init()
{
    memset(mem_ptr_pool, 0, MAX_MEM_PTR_POOL * sizeof(mem_ptr_t));
}

/**************************************************************************/
/*!
    Find a free memory pointer. If one is located, then allocate the managed
    memory from the memory heap. If no memory is available, then return NULL.
*/
/**************************************************************************/
mem_ptr_t *mem_heap_alloc(U8 size)
{
    U8 i;

    for (i=0; i<MAX_MEM_PTR_POOL; i++)
    {
        if (!mem_ptr_pool[i].alloc)
        {
            // found a free mem ptr. only mark it used if we can alloc memory to it.
            if (mmem_alloc(&mem_ptr_pool[i].mmem_ptr, size))
            {
                // memory successfully alloc'd. clear the block, mark this sucker used, and return it.
                memset(mem_ptr_pool[i].mmem_ptr.ptr, 0, sizeof(mem_ptr_t));
                mem_ptr_pool[i].alloc = true;
                return &mem_ptr_pool[i];
            }
            else
            {
                // no more memory. don't touch the ptr and return NULL.
                return NULL;
            }
        }
    }
    // couldn't find any free mem pointers. return NULL.
    return NULL;
}

/**************************************************************************/
/*!
    Free the managed memory and then de-allocated the memory pointer.
*/
/**************************************************************************/
void mem_heap_free(mem_ptr_t *mem_ptr)
{
    if (mem_ptr)
    {
        mmem_free(&mem_ptr->mmem_ptr);
        mem_ptr->alloc = false;
    }
}

// management header
struct mgr_header
{
    U8   size;
    int  num;
    U8   *count;
    void *mem;
}memb_heap_hdr[4];

#define CAP_S16 20
#define CAP_S32 20
#define CAP_S64 20
#define CAP_S160 5

#define SIZE_S16 16
#define SIZE_S32 32
#define SIZE_S64 64
#define SIZE_S160 160
// 4 kinds
unsigned char count[CAP_S16+CAP_S32+CAP_S64+CAP_S160];
// total 2500 bytes
unsigned char buff_heap[2500];


void memb_heap_init(struct mgr_header *hdr)
{
// the size of struct
    hdr[0]->size = SIZE_S16;
    hdr[1]->size = SIZE_S32;
    hdr[2]->size = SIZE_S64;
    hdr[3]->size = SIZE_S160;

// init num of struct
    hdr[0]->num = CAP_S16;
    hdr[1]->num = CAP_S32;
    hdr[2]->num = CAP_S64;
    hdr[3]->num = CAP_S160;

// flag address
    hdr[0]->count = &count[0];
    hdr[1]->count = &count[CAP_S32];
    hdr[2]->count = &count[CAP_S16+CAP_S32];
    hdr[3]->count = &count[CAP_S16+CAP_S32+CAP_S64];

//  hdr->mem
    hdr[0]->mem = &buff_heap[0];
    hdr[1]->mem = &buff_heap[SIZE_S16*CAP_S16];
    hdr[2]->mem = &buff_heap[SIZE_S16*CAP_S16 + SIZE_S32*CAP_S32];
    hdr[3]->mem = &buff_heap[SIZE_S16*CAP_S16 + SIZE_S32*CAP_S32 + SIZE_S64*CAP_S64];
}

void *memb_heap_alloc(U8 size)
{
    int size_mode = size>>4;
    switch(size_mode)
    {
    case 0:
        return my_memb_alloc(&memb_heap_hdr[0]);
        break;
    case 1:
        return my_memb_alloc(&memb_heap_hdr[1]);
        break;
    case 2:
    case 3:
        return my_memb_alloc(&memb_heap_hdr[2]);
        break;
    case 4:
    case 5:
        return my_memb_alloc(&memb_heap_hdr[3]);
        break;
    }
}

void *my_memb_alloc(struct mgr_header *hdr)
{
    int i;
    for(i = 0; i < hdr->num; i++){
        if(!hdr->count[i]){
            hdr->count[i] = 1;//marked as used
            return (void *)((char *)hdr->mem + hdr->size*i);
        }
    }
}

// to see how he free use for() or another ???
void *memb_heap_free(void *ptr)
{
    int i;
    struct mgr_header *p_hdr = &memb_heap_hdr[0];
//    for(i = 0; i < p)
    if((char *)ptr < SIZE_S16*CAP_S16+SIZE_S32*CAP_S32){
        if((char *)ptr < SIZE_S16*CAP_S16){
            my_memb_free(&memb_heap_hdr[0], ptr);
        }else{
            my_memb_free(&memb_heap_hdr[1], ptr);
        }
    }else{
        if((char *)ptr > SIZE_S16*CAP_S16+SIZE_S32*CAP_S32+SIZE_S64*CAP_S64){
            my_memb_free(&memb_heap_hdr[3], ptr);
        }else{
            my_memb_free(&memb_heap_hdr[2], ptr);
        }
    }
}


void *my_memb_free(struct mgr_header *p_mgr_hdr, void *ptr)
{
    int i;
    p_mgr_hdr->count[((char *)ptr - (char *)p_mgr_hdr)/p_mgr_hdr->size] = 0;
}
