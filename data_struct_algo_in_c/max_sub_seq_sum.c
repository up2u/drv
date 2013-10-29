// ----------------------------------------------------------------------------
// max sum of subsequence from array
// <<Data Structures and Algorithm Analysis in C>>
// chapter 2.4.3
// ----------------------------------------------------------------------------

#include <stdio.h>

// T(N) = O(N^3)
int max_sub_seq_sum1(const int a[], int n)
{
  int i, j, k;
  int max_sum = 0;
  int this_sum = 0;

  for (i = 0; i < n; i++)
  {
    for (j = i; j < n; j++)
    {
      this_sum = 0;
      for (k = i; k <= j; k++)
      {
        this_sum += a[k];
      }

      if (this_sum > max_sum)
      {
        max_sum = this_sum;
      }
    }
  }

  return max_sum;
}

// T(N) = O(N^2)
int max_sub_seq_sum2(const int a[], int n)
{
  int i, j, k;
  int this_sum = 0;
  int max_sum = 0;

  for (i = 0; i < n; i++)
  {
    this_sum = 0;
    for (j = i; j < n; j++)
    {
      this_sum += a[j];
      if (this_sum > max_sum)
      {
        max_sum = this_sum;
      }
    }
  }

  return max_sum;
}

// reture max from 3 elem
int max3(int a, int b, int c)
{
  a = a > b ? a : b;

  return a > c ? a : c;
}

// recursion
// T(N) = O(NlogN)
static int max_sub_sum(const int a[], int left, int right)
{
  int max_left_sum, max_right_sum;
  int max_left_board_sum, max_right_board_sum;
  int left_board_sum, right_board_sum;
  int center, i;

  // base case
  if (left == right)
  {
    if (a[left] > 0)
    {
      return a[left];
    }
    else
    {
      return 0;
    }
  }

  center        = (left + right) / 2;
  max_left_sum  = max_sub_sum(a, left, center);
  max_right_sum = max_sub_sum(a, center + 1, right);

  max_left_board_sum = 0;
  left_board_sum     = 0;
  // NOTE here !, the index must descend from center to left,
  // 因为这里递归的是中间连续的部分，如果从left->center, 那么将有可能
  // 靠近center部分有负数，那 max_left_board_sum 将不会加上这些负数
  // 造成了实际上的数字更大，但是结果呢，这些数并不连续
  // for (i = left; i <= center; i++)  // the result is 13 ?
  for (i = center; i >= left; i--) // right result 11
  {
    left_board_sum += a[i];
    if (left_board_sum > max_left_board_sum)
    {
      max_left_board_sum = left_board_sum;
    }
  }

  max_right_board_sum = 0;
  right_board_sum     = 0;
  for (i = center + 1; i <= right; i++)
  {
    right_board_sum += a[i];
    if (right_board_sum > max_right_board_sum)
    {
      max_right_board_sum = right_board_sum;
    }
  }

  return max3(max_left_sum,
              max_right_sum,
              max_left_board_sum + max_right_board_sum);
}

int max_sub_seq_sum3(const int a[], int n)
{
  return max_sub_sum(a, 0, n - 1);
}

// not recursion
// T(N) = O(N)
int max_sub_seq_sum4(const int a[], int n)
{
  int i;
  int this_sum = 0;
  int max_sum = 0;

  for (i = 0; i < n; i++)
  {
    this_sum += a[i];
    if (this_sum > max_sum)
    {
      max_sum = this_sum;
    }
    else if (this_sum < 0) // NOTICE here, condition must be <0, not just else
    {
      this_sum = 0;
    }
  }

  return max_sum;
}

int main()
{
#define NUM 8

  int i = 0;
  int arr[NUM] = {4, -3, 5, -2, -1, 2, 6, -2};
  int get_max = 0;

  // use 1
  //  get_max = max_sub_seq_sum1(arr, NUM);

  // use 2
  //  get_max = max_sub_seq_sum2(arr, NUM);

  // use 3
  get_max = max_sub_seq_sum3(arr, NUM);
  // use 4
  //get_max = max_sub_seq_sum4(arr, NUM);

  puts("the elem of array is : ");
  for ( ; i < NUM; i++ )
  {
    printf("%d ", arr[i]);
  }
  printf("\nthe max seq sum is %d\n", get_max);

#undef NUM
  return 0;
}
