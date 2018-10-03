/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int* plusOne(int*,int,int*);

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1, i = 0, sum = 0;
    *returnSize = digitsSize;
    int *ret_array = (int*)malloc(*returnSize * sizeof(int));
    for(i = digitsSize - 1; i >= 0; i--)
    {
        sum = carry + digits[i];
        ret_array[i] = (sum > 9) ? 0 : sum;
        carry = (sum > 9) ? 1 : 0;
    }
    //If resultant carry is 1, then we first store ret_array into temp_array, increase the size of ret_array by 1,
    //copy temp_array into ret_array starting from index = 1, then place the carry into ret_array[0]
    if(carry == 1)
    {
        int *temp_array = (int*)malloc(*returnSize * sizeof(int));
        memmove(temp_array, ret_array, *returnSize);
        ret_array = (int*)realloc(ret_array, ++(*returnSize) * sizeof(int));
        memmove(&ret_array[1], &temp_array[0], *returnSize - 1);
        ret_array[0] = 1;
        free(temp_array);
    }
    return ret_array;
}

void main()
{
  int digits[4] = {9,9,9,9}, returnSize = 0;
  int *ret_array = (int*)malloc(sizeof(int));
  ret_array = plusOne(digits, 4, &returnSize);
  printf("Array plus One is :\n");
  for(int i = 0; i < 4; i++) printf("%d\t", ret_array[i]);
}
