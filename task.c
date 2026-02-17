#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

// Create a new task
Task* createTask(int id, char desc[], int priority) 
{
    Task* newTask = (Task*)malloc(sizeof(Task));

    newTask->id = id;
    strcpy(newTask->description, desc);
    newTask->priority = priority;
    newTask->completed = 0;
    newTask->next = NULL;

    return newTask;
}

// Insert task based on priority
void insertTask(Task** head, Task* newTask) 
{
    if (*head == NULL || newTask->priority < (*head)->priority) 
    {
        newTask->next = *head;
        *head = newTask;
        return;
    }

    Task* temp = *head;
    while (temp->next != NULL && temp->next->priority <= newTask->priority) 
    {
        temp = temp->next;
    }

    newTask->next = temp->next;
    temp->next = newTask;
}

// Display all tasks
void displayTasks(Task* head) 
{
    if (head == NULL) 
    {
        printf("\nNo tasks available\n");
        return;
    }

    printf("\nID | Priority | Status | Description\n");
    printf("------------------------------------\n");

    while (head != NULL) 
    {
        printf("%d  |   %d      | %s | %s\n",
               head->id,
               head->priority,
               head->completed ? "Done " : "Todo ",
               head->description);
        head = head->next;
    }
}

// Delete a task by ID
void deleteTask(Task** head, int id) 
{
    Task* temp = *head;
    Task* prev = NULL;

    while (temp != NULL && temp->id != id) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("task not found\n");
        return;
    }

    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("task deleted successfully\n");
}

// Mark task as completed
void markCompleted(Task* head, int id) 
{
    while (head != NULL) 
    {
        if (head->id == id) 
        {
            head->completed = 1;
            printf("task marked as completed.\n");

            return;
        }
        head = head->next;
    }
    printf("task not found\n");
}
