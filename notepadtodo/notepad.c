#include "notepad.h"

struct Note* head = NULL;

void addNote(char* text) {
    struct Note* newNode = (struct Note*)malloc(sizeof(struct Note));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->text = (char*)malloc(strlen(text) + 1);
    if (newNode->text == NULL) {
        free(newNode); 
        return;
    }
    
    strcpy(newNode->text, text);

    newNode->next = head;

    head = newNode;

    printf("Note added successfully!\n");
}

void displayAllNotes() {
    struct Note* current = head;

    if (current == NULL) {
        printf("\nNo notes to display.\n");
        return;
    }

    printf("\n--- My Notes ---\n");
    int count = 1;
    while (current != NULL) {
        printf("%d. %s\n", count, current->text);
        
        current = current->next;
        count++;
    }
    printf("----------------\n");
}

void deleteNote(int index) {
    if (head == NULL) {
        printf("\nList is empty, nothing to delete.\n");
        return;
    }

    struct Note* temp = head;

    if (index == 1) {
        head = temp->next; 
        free(temp->text);  
        free(temp);        
        printf("\nNote deleted at index %d.\n", index);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 2; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid index!\n");
        return;
    }

    struct Note* nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    free(nodeToDelete->text);
    free(nodeToDelete);

    printf("\nNote deleted at index %d.\n", index);
}

void saveNotes() {
    FILE *file = fopen("notes.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing notes!\n");
        return;
    }

    struct Note* current = head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->text);
        current = current->next;
    }

    fclose(file);
    printf("Notes saved successfully.\n");
}

void loadNotes() {
    FILE *file = fopen("notes.txt", "r");
    if (file == NULL) {
        return;
    }

    char buffer[256];
    struct Note* tail = NULL;

    struct Note* current = head;
    while(current != NULL && current->next != NULL) {
        current = current->next;
    }
    tail = current;

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;

        struct Note* newNode = (struct Note*)malloc(sizeof(struct Note));
        newNode->text = (char*)malloc(strlen(buffer) + 1);
        strcpy(newNode->text, buffer);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(file);
    printf("Notes loaded.\n");
}
