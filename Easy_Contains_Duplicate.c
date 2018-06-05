//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include<stdio.h>
#include<stdbool.h>

bool containsDuplicate(int*, int);

bool containsDuplicate(int* nums, int numsSize) {
    int returnval = 0;
    if(numsSize>1)
    {
        for(int i = 0; i < numsSize; i++)
        {
            int j = i + 1;
            while(j < numsSize)
            {
                if(nums[i]==nums[j])
                {
                    returnval = 1;
                    break;
                }
                else
                    j++;
            }
        }

    }
    return returnval;
}

void main()
{
  int array[4] = {1,2,3,1};
  printf("%s",(containsDuplicate(array, 4) == 1) ? "TRUE" : "FALSE");
}
