#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notepad.h"
#include "todo.h"

int main() {
    int choice;
    char buffer[256]; 
    int priority;
    int index;

    printf("Loading data...\n");
    loadNotes();
    loadTasks();
    printf("Data loaded.\n");

    while (1) {
        printf("\n--- Project Menu ---\n");
        printf("1. Add Note (Notepad)\n");
        printf("2. View All Notes (Notepad)\n");
        printf("3. Delete Note (Notepad)\n");
        printf("4. Add Task (Todo List)\n");
        printf("5. Get Next Task (Todo List)\n");
        printf("0. Save and Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        getchar(); 

        switch (choice) {
            case 1:
                printf("\nEnter note text: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; 
                addNote(buffer);
                break;
            case 2:
                displayAllNotes();
                break;
            case 3:
                printf("\nEnter index of note to delete: ");
                scanf("%d", &index);
                deleteNote(index);
                break;
            case 4:
                printf("\nEnter task description: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; 
                printf("Enter priority (1=High, 2=Medium, 3=Low): ");
                scanf("%d", &priority);
                addTask(buffer, priority);
                break;
            case 5:
                getNextTask();
                break;
            case 0:
                printf("Saving data...\n");
                saveNotes();
                saveTasks();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
