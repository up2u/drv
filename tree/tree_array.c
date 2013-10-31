#include <stdio.h>

#define NUM 10
#define ARRAY_TREE_SIZE NUM
// -----------------------------------
// array a[10], tree as below
//          1
//     2         3
//  4    5    6    7
// 8 9 10
// -----------------------------------

// pre recursion
void preorder(int a[], int n)  // n start from 1, for index of tree (2n, 2n+1)
{
  if (n <= ARRAY_TREE_SIZE)
  {
    printf("pre order : %d\n", a[n - 1]);
    preorder(a, 2 * n);
    preorder(a, 2 * n + 1);
  }
}
// pre, not recursion
int s[10];
void preorder2(int a[], int array_size)
{
  int i = 1;
  int j = -1;  // empty stack
  while (i <= array_size)  // the use array_size or tree node num to judge,
                           // so must 完全二叉树
  {
    printf("not recursion preorder %d\n", a[i - 1]);
    s[++j] = i;
    i *= 2;
    while (i > array_size && j > -1)  // must use j>-1, not j>=-1
    {
      i = s[j--];
      i = 2 * i + 1;
    }
  }
}
// pre not recursion
void preorder3(int a[], int array_size)
{
  int i = 1;
  int j = -1;

  // must i <= , not <, for case 1 2 3, special for 3
  while (i <= array_size || j > -1)
  {
    if (i <= array_size)
    {
      s[++j] = i;
      printf("preorder3 : %d\n", a[i - 1]);
      i *= 2;
    }
    else
    {
      i = s[j--];
      i = 2 * i + 1;
    }
  }
}

void inorder(int a[], int n)
{
  if (n <= ARRAY_TREE_SIZE)
  {
    inorder(a, 2 * n);
    printf("in order : %d\n", a[n - 1]);
    inorder(a, 2 * n + 1);
  }
}
// in, not recursion
void inorder2(int a[], int array_size)
{
  int i = 1;
  int j = -1;

  while (i <= array_size)  // here must <=, not <
  {
    s[++j] = i;
    i *= 2;
    while (i > array_size && j > -1)  // here must j > -1, not >=
    {
      i = s[j--];
      printf("not recursion, in order %d\n", a[i - 1]);
      i = 2 * i + 1;
    }
  }
}
// in, not recursion
void inorder3(int a[], int array_size)
{
  int i = 1;
  int j = -1;

  // use || j > -1 is used to when i > array_size, must not >= -1
  // when 1,2,3 the last one:3 push and pop from stack, j = -1
  while (i <= array_size || j > -1)
  {
    if (i <= array_size)
    {
      s[++j] = i;
      i *= 2;
    }
    else
    {
      i = s[j--];
      printf("in order 3, %d\n", a[i - 1]);
      i = 2 * i + 1;
    }
  }
}

void postorder(int a[], int n)
{
  if (n <= ARRAY_TREE_SIZE)
  {
    postorder(a, 2 * n);
    postorder(a, 2 * n + 1);
    printf("post order : %d\n", a[n - 1]);
  }
}
// post, not recursion
// not get stack elem but not decres the index j, mean still store the
// subroot
void postorder2(int a[], int array_size)
{
  int i = 1;
  int j = -1;
  int flag[2 * NUM + 1] = {0};  // because of index 2*i and 2*i+1 so

  while (i <= array_size || j > -1)  //
  {
    if (i <= array_size && 0 == flag[i - 1])
    {
      s[++j] = i;
      i *= 2;
    }
    else
    { // stakc is empty, 不像pre,in order遍历，post遍历时不是每次都pop的，所以stack empty时
      // 就说明已经是结束了。
      if (j == -1)
        return;

      i = s[j];
      if (flag[i - 1] == 1)
      {
        printf("postorder2 : %d\n", a[i - 1]);
        i = s[j--];  // NOTE, only now decrease stack !
      }

      flag[i - 1] = 1;  // 这是为后面stack返回时设置的flag
      i = 2 * i + 1;
    }
  }
}

int main()
{
  int arr[NUM] = {0}; //1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i = 0;

  for ( ; i < NUM ; i++)
  {
    arr[i] = i + 1;
  }
// recursion
//  puts("-----------------");
//  preorder(arr, 1);
//
//  puts("-----------------");
//  inorder(arr, 1);
//
//  puts("-----------------");
//  postorder(arr, 1);

  // not recursion
  //  preorder2(arr, NUM);
  //  preorder3(arr, NUM);
  //  inorder2(arr, NUM);
  //  inorder3(arr, NUM);
  postorder2(arr, NUM);

  return 0;
}
