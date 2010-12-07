#include <stdio.h>
#include <stdlib.h>
#include "block.h"
#include "link_operation.h"

#define HASH_SIZE 70
#define STUDENT_NUM 1000
#define RAND_SCORE 1000
#define RAND_NAME 26

struct gdlist hash_tab[HASH_SIZE];
void init_hash_tab(struct gdlist *ptr_hash, int size)
{
	int i=0;
	for(i=0; i<size; i++)
	{
		ptr_hash[i].next = &(ptr_hash[i]);	
		ptr_hash[i].prev = &(ptr_hash[i]);
	}
}

struct student
{
	int score;
	char name;
	struct gdlist list;	
};

void ins_hash_tab(struct student *stu)
{
	int index = 0;
	index = (stu->score)%HASH_SIZE;
	ins_gdlist_head(&(hash_tab[index]), &(stu->list));
}

void gen_score_name(struct student *stu, int num)
{
	FILE *p;
	p = fopen("student.txt", "w+");
	int i = 0;
	for(i=0; i<num; i++)
	{
		stu[i].score = rand()%RAND_SCORE;
		stu[i].name = rand()%RAND_NAME + 'A';
		fprintf(p, "student %d: score=%d,name=%c\n", i+1, stu[i].score, stu[i].name);
		ins_hash_tab(&stu[i]);
	}
}

void hash_search(int score)
{
	int key=score%HASH_SIZE;
	struct student *pstu = NULL;
	struct gdlist *pgdlist = NULL;	
	pgdlist = get_glist_head(&(hash_tab[key]));
	for(; pgdlist != &(hash_tab[key]); pgdlist = get_glist_next(pgdlist))
	{
		pstu = (struct student *)container_of(struct student, list, (size_t)pgdlist);
		if(pstu->score == score)
		{
			printf("now find it score=%d,name=%c\n", pstu->score, pstu->name);	
		}
	}
	if(pgdlist == &(hash_tab[key]))
	{
		printf("search end.\n");	
	}
}

int main()
{
	int search = 0;
	struct student stu[STUDENT_NUM];

	init_hash_tab(hash_tab, HASH_SIZE);
	gen_score_name(stu, STUDENT_NUM);	
	do
	{
		printf("input score to search. : ");
		scanf("%d", &search);
		hash_search(search);
	}while(1);

	return 0;	
}

