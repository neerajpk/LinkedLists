// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.

#include<stdio.h>
#include<stdlib.h>

char* countAndSay(int);

char* countAndSay(int n) {
    char **ret_str = (char**)calloc(n, sizeof(char*));
    int *col_len = (int*)calloc(n, sizeof(int));
    ret_str[0] = (char*)realloc(ret_str[0], 2 * sizeof(char));
    ret_str[0] = "1\0";
    col_len[0] = 1;
    int col_index = 0, count = 1;
    char temp, *answer;
    for(int i = 1; i < n; i++)
    {
        col_index = 1;
        count = 1;
        temp = ret_str[i - 1][0];
        while(col_index < col_len[i - 1])
        {
            if(ret_str[i - 1][col_index] == temp) count++;
            else
            {
                col_len[i] += 2;
                ret_str[i] = (char*)realloc(ret_str[i], col_len[i] * sizeof(char));
                ret_str[i][col_len[i] - 2] = count + '0';
                ret_str[i][col_len[i] - 1] = temp;
                temp = ret_str[i - 1][col_index];
                count = 1;
            }
            col_index++;
        }
        col_len[i] += 2;
        ret_str[i] = (char*)realloc(ret_str[i], (col_len[i] + 1) * sizeof(char));
        ret_str[i][col_len[i] - 2] = count + '0';
        ret_str[i][col_len[i] - 1] = temp;
        ret_str[i][col_len[i]] = '\0';
    }
    answer = ret_str[n - 1];
    free(ret_str);
    free(col_len);
    return answer;
}

void main()
{
  int i = 0;
  while(i < 10) printf("%d\t:\t%s\n", i, countAndSay(++i));
}
