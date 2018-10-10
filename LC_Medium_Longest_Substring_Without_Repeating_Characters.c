// Given a string, find the length of the longest substring without repeating characters.
//
// Example 1:
//
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLongestSubstring(char*);

int lengthOfLongestSubstring(char* s) {
    int* HT = (int*)malloc(95 * sizeof(int));
    memset(HT, -1, sizeof(int) * 95);
    int ret_len = 0, index1 = 0, index2 = 0;
    while(*(s + index1 + index2) != '\0')
    {
        if(HT[*(s + index1 + index2) - ' '] == -1)
        {
            HT[*(s + index1 + index2) - ' '] = index1 + index2;
            if(++index2 > ret_len) ret_len = index2;
        }
        else
        {
            index1 = HT[*(s + index1 + index2) - ' '] + 1;
            index2 = 0;
            memset(HT, -1, sizeof(int) * 95);
        }
    }
    free(HT);
    return ret_len;
}

void main()
{
  int size = 0;
  printf("Enter size of string:");
  scanf("%d", &size);
  printf("Enter string:");
  char* stringinp = (char*)malloc(size + 1 * sizeof(char));
  scanf("%s", stringinp);
  printf("Length of longest substring is %d", lengthOfLongestSubstring(stringinp));
  free(stringinp);
}
