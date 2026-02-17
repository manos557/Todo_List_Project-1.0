#include <stdio.h>
#include <string.h>
#include "notepad.h"
#include "task.h"
#include "fileio.h"

void runNotepad() 
{
    Task* head = NULL;
    int choice, priority, id;
    char desc[100];
    int idCounter = 1;

    loadTasks(&head, &idCounter);

    while (1) 
    {
        printf("\n-----TASK NOTEPAD-----\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Mark Task Completed\n");
        printf("5. Save And Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) 
        {
            printf("Add Your Task: ");
            fgets(desc, 100, stdin);

            desc[strcspn(desc, "\n")] = 0;

            printf("Enter Your Task Priority: ");
            scanf("%d", &priority);

            insertTask(&head, createTask(idCounter++, desc, priority));
            printf("Task Added Successfully\n");
        }
        else if (choice == 2) 
        {
            displayTasks(head);
        }
        else if (choice == 3) 
        {
            printf("Enter Deleting Task ID: ");
            scanf("%d", &id);
            deleteTask(&head, id);
        }
        else if (choice == 4) 
        {
            printf("Enter Completed Task ID: ");
            scanf("%d", &id);
            markCompleted(head, id);
        }
        else if (choice == 5) 
        {
            saveTasks(head);
            printf("Saved And Exiting...\n");
            return;
        }
        else 
        {
            printf("Invalid choice\n");
        }
    }
}

