/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]*/

#include<stdio.h>
#include<stdlib.h>

//Structure of Linked List node in HashMap
typedef struct
{
    int value;
    int index;
    struct HashNode* next;
}HashNode;

//Structure of HashMap
typedef struct
{
  HashNode** HashTable;
  int TableSize;
}HashMap;

//Function prototypes declared
HashMap* Init(int);
void insert(HashMap*, int, int);
int search_index(HashMap*, int, int);
int* twoSum(int*, int, int);

//HashMap initialized
HashMap* Init(int size)
{
    HashMap *obj = (HashMap*)malloc(sizeof(HashMap));
    obj -> TableSize = size;
    obj -> HashTable = (HashNode**)calloc(obj -> TableSize, sizeof(HashNode*)) ;
    return obj;
}

//Insert an entry into HashMap
void insert(HashMap* obj, int entry, int entry_index)
{
    HashNode *temp = NULL;
    temp = (HashNode*)malloc(sizeof(HashNode));
    temp -> value = entry;
    temp -> index = entry_index;
    temp -> next = obj -> HashTable[abs(entry) % obj -> TableSize];
    obj -> HashTable[abs(entry) % obj -> TableSize] = temp;
}

//Search for a value in the HashMap
int search_index(HashMap* obj, int lookup, int index_exc)
{
    if(obj -> HashTable[abs(lookup) % obj -> TableSize] != NULL)
    {
        HashNode *temp = obj -> HashTable[abs(lookup) % obj -> TableSize];
        while(temp != NULL)
        {
            if(temp -> value == lookup && temp -> index != index_exc) return temp -> index;
            temp = temp -> next;
        }
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target) {
    int TableSize = 100, ret_ind = 0;
    HashMap *obj = Init(TableSize);
    int *ret_array = (int*)malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++)
    {
        insert(obj, nums[i], i);
        ret_ind = search_index(obj, target - nums[i], i);
        if(ret_ind != -1)
        {
            ret_array[0] = ret_ind;
            ret_array[1] = i;
            break;
        }
    }
    return ret_array;
}

void main()
{
  int nums[4] = {2, 7, 11, 15}, target = 26;
  int *ret_array = (int*)malloc(sizeof(int));
  ret_array = twoSum(nums, 4, target);
  printf("Two Sum is :\n");
  for(int i = 0; i < 2; i++) printf("%d\t", ret_array[i]);
}
