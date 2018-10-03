//From LeetCode
//Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//Given nums = [0,0,1,1,1,2,2,3,3,4],
//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
//It doesn't matter what values are set beyond the returned length.

#include<stdio.h>

int removeDuplicates(int*, int);

int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 1;
    for(;i,j < numsSize;)
    {
        if(nums[i] == nums[j]) j++;
        else nums[++i] = nums[j];
    }
    return (numsSize == 0 ? 0 : i + 1);
}

void main()
{
  int array[10] = {0,0,1,1,1,2,2,3,3,4};
  int length = removeDuplicates(array,10);
  printf("Array with duplicates removed is:\n");
  for(int i = 0; i < length; i++) printf("%d\t", array[i]);
}
