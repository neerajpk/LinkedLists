// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Determine if you are able to reach the last index.
//
// Example 1:
//
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
//
// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool canJump(int*, int);

bool canJump(int* nums, int numsSize) {
    int up_bound = numsSize - 1, i = numsSize - 1, found = 0;
    while(i >= 0)
    {
        if(i + nums[i] >= up_bound)
        {
            up_bound = i;
            found = 1;
        }
        else found = 0;
        i--;
    }
    return (found == 0 ? false : true);
}

void main()
{
  int arr_size = 0;
  printf("Enter size of array of non - negative integers:");
  scanf("%d", &arr_size);
  int *array = (int*)calloc(arr_size, sizeof(int));
  printf("Enter array:");
  for(int i = 0; i < arr_size; i++) scanf("%d", &array[i]);
  printf("%s", canJump(array, arr_size) ? "true" : "false");
  free(array);
}
