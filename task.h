#ifndef TASK_H
#define TASK_H

typedef struct Task 
{
    int id;
    char description[100];
    int priority;                 // 1 = High, 2 = Medium, 3 = Low
    int completed;                // 0 = No, 1 = Yes
    struct Task* next;
} Task;

Task*createTask(int id, char desc[], int priority);
void insertTask(Task** head, Task* newTask);
void displayTasks(Task* head);
void deleteTask(Task** head, int id);
void markCompleted(Task* head, int id);

#endif
