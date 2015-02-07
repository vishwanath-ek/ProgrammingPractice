#ifndef LINKEDLISTFUNC_H
#define LINKEDLISTFUNC_H

#define FILE_FULL_PATH "/home/vishwanath/Documents/file.txt"
#define BUFFER_SIZE 50

typedef struct nodeStruct{
    struct nodeStruct *next;
    char file_data[50];
} Node;

extern char *buffer;
extern uint16_t count;
void error(const char*);
int catchSignal(int, void (*) (int));
#endif
