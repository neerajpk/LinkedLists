// Write a function that takes a string as input and returns the string reversed.
//
// Example 1:
//
// Input: "hello"
// Output: "olleh"
// Example 2:
//
// Input: "A man, a plan, a canal: Panama"
// Output: "amanaP :lanac a ,nalp a ,nam A"

#include<stdio.h>
#include<stdlib.h>

char* reverseString(char* s)
{
    int Slength = 0;
    while(*s!='\0')
    {
        Slength++;
        s++;
    }
    char *p = (char*)malloc(Slength * sizeof(char));
    --s;
    int i = 0;
    while(i < Slength)
    {
        *(p+i) = *(s-i);
        i++;
    }
    return p;
}

void main()
{
  char input_string[] = "A man, a plan, a canal: Panama";
  char *outp = reverseString(input_string);
  while(*outp != '\0') printf("%c", *outp++);
}
