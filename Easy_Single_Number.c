//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include<stdio.h>

int singleNumber(int*, int);

//If duplicate values have even counts, then XOR of all elements in the array will yield the unique element
int singleNumber(int* nums, int numsSize) {
    int ret_val = 0;
    for(int i = 0; i < numsSize; i++) ret_val ^= nums[i];
    return ret_val;
}

void main()
{
  int array[5] = {4,1,2,1,2};
  printf("Unique value is : %d", singleNumber(array, 5));
}
