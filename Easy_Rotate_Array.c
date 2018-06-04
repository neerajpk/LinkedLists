//Given an array, rotate the array to the right by k steps, where k is non-negative.
//Example 1:
//Input: [1,2,3,4,5,6,7] and k = 3
//Output: [5,6,7,1,2,3,4]
//Explanation:
//rotate 1 steps to the right: [7,1,2,3,4,5,6]
//rotate 2 steps to the right: [6,7,1,2,3,4,5]
//rotate 3 steps to the right: [5,6,7,1,2,3,4]

#include<stdio.h>

void rotate(int*,int,int);

void rotate(int* nums, int numsSize, int k) {
    int index = 0;
    while(index < k)
    {
        int swapvar = nums[numsSize-1];
        for(int i = numsSize - 1; i > 0; i--)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = swapvar;
        index++;
    }
}

void main()
{
  int array[7] = {1,2,3,4,5,6,7}, k = 3;
  rotate(array, 7, 3);
  printf("Rotated array is: ");
  for(int i = 0; i < 7; i++) printf("%d\t", array[i]);
}
