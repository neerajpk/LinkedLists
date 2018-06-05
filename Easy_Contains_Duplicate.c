//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include<stdio.h>
#include<stdbool.h>

void swap(int*, int*);
void heapify(int*, int, int);
void heapsort(int*, int);
bool containsDuplicate(int*, int);

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void heapify(int* nums, int numsSize, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < numsSize && nums[largest] < nums[left]) largest = left;
    if(right < numsSize && nums[largest] < nums[right]) largest = right;
    if(largest != index)
    {
        swap(&nums[index], &nums[largest]);
        heapify(nums, numsSize, largest);
    }
}

void heapsort(int* nums, int numsSize)
{
    for(int i = (numsSize/2) - 1; i >= 0; i--) heapify(nums, numsSize, i);
    for(int i = numsSize - 1; i >= 0; i--)
    {
        swap(&nums[i], &nums[0]);
        heapify(nums, i, 0);
    }
}

bool containsDuplicate(int* nums, int numsSize) {
    heapsort(nums, numsSize);
    for(int i = 1; i < numsSize; i++) if(nums[i] == nums[i - 1]) return true;
    return false;
}

void main()
{
  int array[4] = {1,2,3,1};
  printf("%s",(containsDuplicate(array, 4) == 1) ? "TRUE" : "FALSE");
}
