// ----------------------------------------------------------------------------
// ex24.8_callback.c
//
// Copyright (c)
//
// ----------------------------------------------------------------------------

#include <stdio.h>

//
typedef int (* comp_t)(void *a, void *b);


// output type, 1st input type:
void * max(void *data[], int num, comp_t cmp)
{
  int i;
  void *temp = data[0];

  for (i = 1; i < num; i++)
  {
    if (cmp(temp, data[i]) < 0) // see NOTE:
      temp = data[i];
  }

  return temp;
}

typedef struct
{
  char *name;
  int scores;
}student;

// input type : void *
int cmp_student(void *a, void *b)
{
  if (((student *)a)->scores > ((student *)b)->scores)
    return 1;
  else if (((student *)a)->scores == ((student *)b)->scores)
    return 0;
  else
    return -1;
}

int main(int argc, char *argv[])
{
  student list[4] = {{"Tom", 68},
                     {"Jerry", 90},
                     {"Mody", 75},
                     {"Kirby", 80}};

  // NOTE: here must use plist, because where 'see NOTE:'
  // type is void, they can't find the correct next element
  //  here will Segment fault when use 'list'
  //  student *get_max = (student *)max((void **)list, 4, cmp_student);
  student *plist[4] = {&list[0], &list[1], &list[2], &list[3]};

  student *get_max = (student *)max((void **)plist, 4, cmp_student);
  printf("get max name : %s, score : %d\n", get_max->name, get_max->scores);
  return 0;
}
