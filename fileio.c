#include <stdio.h>
#include "fileio.h"

void saveTasks(Task* head) 
{
    FILE* fp = fopen("tasks.txt", "w");
    while (head) 
    {
        fprintf(fp, "%d|%d|%d|%s\n",
                head->id,
                head->priority,
                head->completed,
                head->description);
        head = head->next;
    }
    fclose(fp);
}

void loadTasks(Task** head, int* idCounter) 
{
    FILE* fp = fopen("tasks.txt", "r");
    if (!fp) return;

    int id, priority, completed;
    char desc[100];

    while (fscanf(fp, "%d|%d|%d|%[^\n]\n", &id, &priority, &completed, desc) != EOF) 
    {
        Task* t = createTask(id, desc, priority);
        t->completed = completed;
        insertTask(head, t);

        if (id >= *idCounter)
        {
            *idCounter = id + 1;
        }
    }
    fclose(fp);
}
