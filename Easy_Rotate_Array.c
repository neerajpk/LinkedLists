//Given an array, rotate the array to the right by k steps, where k is non-negative.
//Example 1:
//Input: [1,2,3,4,5,6,7] and k = 3
//Output: [5,6,7,1,2,3,4]
//Explanation:
//rotate 1 steps to the right: [7,1,2,3,4,5,6]
//rotate 2 steps to the right: [6,7,1,2,3,4,5]
//rotate 3 steps to the right: [5,6,7,1,2,3,4]

#include<stdio.h>

void swap(int*, int*);
void reverse(int*, int*);
void rotate(int*,int,int);

//Swapping two variables using XOR
void swap(int *p, int *q)
{
    *p = *p ^ *q;
    *q = *p ^ *q;
    *p = *p ^ *q;
}

//Reversing an array
void reverse(int *p, int *q)
{
    while(p < q) swap(p++, q--);
}

void rotate(int* nums, int numsSize, int k) {
    //Module calculation for when k > numsSize
    k = k % numsSize;
    //Reverse the entire array
    reverse(&nums[0], &nums[numsSize - 1]);
    //Reverse subarray from 0 to k - 1
    reverse(&nums[0], &nums[k - 1]);
    //Reverse subarray from k to numsSize - 1
    reverse(&nums[k], &nums[numsSize - 1]);
}

void main()
{
  int array[7] = {1,2,3,4,5,6,7}, k = 3;
  rotate(array, 7, 3);
  printf("Rotated array is: ");
  for(int i = 0; i < 7; i++) printf("%d\t", array[i]);
}
