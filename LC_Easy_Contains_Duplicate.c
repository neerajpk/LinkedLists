//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//struct MyList is a Linked List node
typedef struct{
    int value;
    struct MyList* next;
}MyList;

//Function prototypes defined
bool insert(MyList**, int, int);
bool containsDuplicate(int*, int);

//search_and_insert function checks if "entry" is present in "HashSet", returns FALSE if it is,
//else uses LinkedList Chaining to resolve collisions and inserts "entry" into "HASHSET"
bool search_and_insert(MyList **HashSet, int Set_Size, int entry)
{
    MyList *temp = HashSet[abs(entry) % Set_Size];
    while(temp != NULL)
    {
        if(temp -> value == entry) return false;
        temp = temp -> next;
    }
    temp = (MyList*)malloc(sizeof(MyList));
    temp -> value = entry;
    temp -> next = HashSet[abs(entry) % Set_Size];
    HashSet[abs(entry) % Set_Size] = temp;
    return true;
}

bool containsDuplicate(int* nums, int numsSize) {
    int Set_Size = 5000, ret_val = 0;
    MyList **HashSet = (MyList**)calloc(Set_Size, sizeof(MyList*));
    for(int i = 0; i < numsSize; i++) if(!search_and_insert(HashSet, Set_Size, nums[i])) ret_val = 1;
    free(HashSet);
    return ret_val;
}

void main()
{
  int array[4] = {1,2,3,-1};
  printf("%s",(containsDuplicate(array, 4) == 1) ? "TRUE" : "FALSE");
}
