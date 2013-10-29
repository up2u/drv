#include <stdio.h>

// chapter 2.4.4

// done by myself
int binary_search1(const int a[], int x, int n)
{
  int left = 0;
  int right = n - 1;
  int center = (n - 1) / 2;

  while (x != a[center])
  {
    if (x < a[center])
    {
      right = center - 1;
      center = (left + right) / 2;
    }
    else
    {
      left = center + 1;
      center = (left + right) / 2;
    }
  }

  if (x == a[center])
    return center;

  return -1;
}

int binary_search2(const int a[], int x, int n)
{
  int low = 0;
  int high = n - 1;
  int mid = high / 2;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (x < a[mid])
      high = mid - 1;
    else if (x > a[mid])
      low = mid + 1;
    else
      return mid;
  }
}

int main()
{
  int index = 0;
#define NUM 8
  int arr[NUM] = {1, 2, 3, 4, 5, 6, 7, 8};

  // use 1
  //  index = binary_search1(arr, 4, NUM);

  // use 2
  index = binary_search2(arr, 4, NUM);
  printf("the index is %d\n", index);

  return 0;
}
