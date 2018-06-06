/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>

//Function prototypes declared
int* intersect(int*, int, int*, int, int*);

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int arraysize = 0, skipsize = 0, skipflag = 0;
    int *returnarray = (int*)malloc(sizeof(int));
    //If any of nums1 or nums2 is empty, return empty array
    if(nums1Size == 0 || nums2Size == 0) return returnarray;
    //Skiparray stores array indices on array pointed to by *q, for which intersection has already been identified
    int *skiparray = (int*)malloc(sizeof(int));
    //*p points to smaller array between nums1 and nums2, *q points to the larger one
    int *p = (nums1Size < nums2Size) ? nums1 : nums2;
    int *q = (nums1Size < nums2Size) ? nums2 : nums1;
    int p_size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int q_size = (nums1Size < nums2Size) ? nums2Size : nums1Size;
    for(int i = 0; i < p_size; i++)
    {
       for(int j = 0; j < q_size; j++)
       {
           if(skipsize > 0)
           {
               skipflag = 0;
               int k = 0;
               while(k < skipsize)
               {
                   if(j == skiparray[k++])
                   {
                       skipflag = 1;
                       break;
                   }
               }
           }
           // If a unique match is identified between the two arrays, then we write it into the return array
           if(*(p + i) == *(q + j) && skipflag == 0)
           {
               returnarray = (int*)realloc(returnarray, sizeof(int) * ++arraysize);
               skiparray = (int*)realloc(skiparray, sizeof(int) * ++skipsize);
               *(returnarray + arraysize - 1) = *(q + j);
               *(skiparray + skipsize - 1) = j;
               returnSize[0]++;
               break;
           }
       }
    }
    free(skiparray);
    return returnarray;
}

void main()
{
  int nums1[4] = {1, 2, 2, 1};
  int nums2[2] = {2, 2};
  int returnSize = 0;
  int *intersection = intersect(nums1, 4, nums2, 2, &returnSize);
  printf("Intersection of given arrays is:\n");
  for(int i = 0; i < returnSize; i++) printf("%d\t", *(intersection + i));
  free(intersection);
}
