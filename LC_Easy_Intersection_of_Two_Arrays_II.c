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
 #include<math.h>

//Struct defined to be used in HashTable chaining (collision resolution)
//value stores the unique array element, count stores its occurence count in the array
typedef struct
{
    int value;
    int count;
    struct MyList* next;
}MyList;

//Function prototypes declared
void insert(MyList**, int, int*, int);
int* search(MyList**, int, int*, int, int*, int*);
int* intersect(int*, int, int*, int, int*);

//HashTable insert function
void insert(MyList **HashTable, int table_size, int *nums, int numsSize)
{
    MyList *temp = NULL;
    int found = 0;
    for(int i = 0; i < numsSize; i++)
    {
        found = 0;
        temp = HashTable[abs(nums[i]) % table_size];
        while(temp != NULL)
        {
            if(temp -> value == nums[i])
            {
                temp -> count += 1;
                found = 1;
                break;
            }
            temp = temp -> next;
        }
        if(found == 0)
        {
            temp = (MyList*)malloc(sizeof(MyList));
            temp -> value = nums[i];
            temp -> count = 1;
            temp -> next = HashTable[abs(nums[i]) % table_size];
            HashTable[abs(nums[i]) % table_size] = temp;
        }
    }
}

//Search function to search for one array's elements in the other array stored in the HashTable
int* search(MyList **HashTable, int table_size, int *nums, int numsSize, int *ret_array, int* returnSize)
{
    MyList *temp = NULL;
    for(int i = 0; i < numsSize; i++)
    {
        temp = HashTable[abs(nums[i]) % table_size];
        while(temp != NULL)
        {
            if(temp -> value == nums[i] && temp -> count > 0)
            {
                temp -> count -= 1;
                ret_array = (int*)realloc(ret_array, ++(*returnSize) * sizeof(int));
                ret_array[*returnSize - 1] = nums[i];
                break;
            }
            temp = temp -> next;
        }
    }
    return ret_array;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ret_array = (int*)malloc(sizeof(int)), table_size = 100;
    MyList **HashTable = (MyList**)calloc(table_size,sizeof(MyList*));
    *returnSize = 0;
    if(nums1Size > nums2Size)
    {
        insert(HashTable, table_size, nums1, nums1Size);
        ret_array = search(HashTable, table_size, nums2, nums2Size, ret_array, returnSize);
    }
    else
    {
        insert(HashTable, table_size, nums2, nums2Size);
        ret_array = search(HashTable, table_size, nums1, nums1Size, ret_array, returnSize);
    }
    return ret_array;
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
