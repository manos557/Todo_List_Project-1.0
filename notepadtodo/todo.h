#ifndef TODO_H
#define TODO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char* description;   
    int priority;        
};

void addTask(char* desc, int priority);
void getNextTask();
void saveTasks();
void loadTasks();

#endif
