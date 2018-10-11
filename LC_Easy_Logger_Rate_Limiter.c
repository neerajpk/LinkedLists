// Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.
//
// Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.
//
// It is possible that several messages arrive roughly at the same time.
//
// Example:
//
// Logger logger = new Logger();
//
// // logging string "foo" at timestamp 1
// logger.shouldPrintMessage(1, "foo"); returns true;
//
// // logging string "bar" at timestamp 2
// logger.shouldPrintMessage(2,"bar"); returns true;
//
// // logging string "foo" at timestamp 3
// logger.shouldPrintMessage(3,"foo"); returns false;
//
// // logging string "bar" at timestamp 8
// logger.shouldPrintMessage(8,"bar"); returns false;
//
// // logging string "foo" at timestamp 10
// logger.shouldPrintMessage(10,"foo"); returns false;
//
// // logging string "foo" at timestamp 11
// logger.shouldPrintMessage(11,"foo"); returns true;

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    int key;
    int ts;
    struct Node* next;
}Node;

typedef struct {
    int log_size;
    Node** Log;
}Logger;

Logger* loggerCreate();
int key_calc(char*);
bool loggerShouldPrintMessage(Logger*, int, char*);
void loggerFree(Logger*);

/** Initialize your data structure here. */
Logger* loggerCreate() {
    Logger *obj = (Logger*)malloc(sizeof(Logger));
    obj -> log_size = 1000;
    obj -> Log = (Node**)calloc(obj -> log_size, sizeof(Node*));
    return obj;
}

int key_calc(char* m)
{
    int ret_key = 0;
    while(*m != '\0') ret_key += *m++ - '0';
    return ret_key;
}

/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
bool loggerShouldPrintMessage(Logger* obj, int timestamp, char* message) {
    int temp_key = key_calc(message);
    Node* temp_head = obj -> Log[temp_key % obj -> log_size];
    while(temp_head != NULL)
    {
        if(temp_head -> key == temp_key)
        {
            if(timestamp - temp_head -> ts >= 10)
            {
                temp_head -> ts = timestamp;
                return true;
            }
            else return false;
        }
        temp_head = temp_head -> next;
    }
    temp_head = (Node*)malloc(sizeof(Node));
    temp_head -> key = temp_key;
    temp_head -> ts = timestamp;
    temp_head -> next = obj -> Log[temp_key % obj -> log_size];
    obj -> Log[temp_key % obj -> log_size] = temp_head;
    return true;
}

void loggerFree(Logger* obj) {
    free(obj);
}

/**
 * Your Logger struct will be instantiated and called as such:
 * struct Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 * loggerFree(obj);
 */

void main()
{
  struct Logger* obj = loggerCreate();
  printf("%s\n", loggerShouldPrintMessage(obj, 1, "foo") ? "true" : "false");
  printf("%s\n", loggerShouldPrintMessage(obj, 2, "bar") ? "true" : "false");
  printf("%s\n", loggerShouldPrintMessage(obj, 3, "foo") ? "true" : "false");
  printf("%s\n", loggerShouldPrintMessage(obj, 8, "bar") ? "true" : "false");
  printf("%s\n", loggerShouldPrintMessage(obj, 10, "foo") ? "true" : "false");
  printf("%s\n", loggerShouldPrintMessage(obj, 11, "foo") ? "true" : "false");
  loggerFree(obj);
}
