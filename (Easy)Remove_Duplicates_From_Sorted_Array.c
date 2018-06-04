//From LeetCode
//Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//Given nums = [0,0,1,1,1,2,2,3,3,4],
//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
//It doesn't matter what values are set beyond the returned length.

#include<stdio.h>

int removeDuplicates(int*, int);

int removeDuplicates(int* nums, int numsSize) {
    // Initialize variable length to be returned
    int length = 1;
    if(numsSize>=1)
    {
        // Loop through each array element
        for(int i = 0; i+1<numsSize; i++)
        {
            if(nums[i]==nums[i+1])
            {
                if(numsSize>2)
                {
                    // For each duplicate found, we loop forward in the array to find the next unique element.
                    // This is a sorted array, so the expectation is to find an element larger than the one at i/i+1
                    int j = i + 2;
                    while(j < numsSize)
                    {
                        if(nums[j]==nums[i+1])
                            j++;
                        else
                        {
                            length++;
                            nums[i+1]=nums[j];
                            break;
                        }
                    }
                }
                // Require atleast 3 elements to proceed
                else
                    break;
            }
            else
                // This part of the code handles special cases, where after a few exchanges, (i + 1)th element is less than ith element
                // However, there still are elements at i + x that are larger than that at i
                // Eg: [1,2,3,6,3,3,6,7,7]
                if(nums[i+1]<nums[i])
                    {
                        int j = i + 2;
                        while(j<numsSize)
                        {
                            if(nums[j]<=nums[i])
                                j++;
                            else
                            {
                                length++;
                                nums[i+1]=nums[j];
                                break;
                            }
                        }
                    // When the desired answer is reached
                    // For the example above : [1,2,3,6,7,3,6,7,7]
                        if(j==numsSize)
                            break;
                    }
            else
            {
                length++;
            }
        }
    }
    else
        length = 0;

    return length;
}

void main()
{
  int array[10] = {0,0,1,1,1,2,2,3,3,4};
  int length = removeDuplicates(array,10);
  printf("Array with duplicates removed is:\n");
  for(int i = 0; i < length; i++) printf("%d\t", array[i]);
}
