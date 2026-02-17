#include "todo.h"

#define MAX_TASKS 100
struct Task heap[MAX_TASKS]; 
int heapSize = 0;            

void addTask(char* desc, int priority) {
    if (heapSize >= MAX_TASKS) {
        printf("\nTask list is full!\n");
        return;
    }

    int currentIndex = heapSize;
    heap[currentIndex].priority = priority;
    
    heap[currentIndex].description = (char*)malloc(strlen(desc) + 1);
    strcpy(heap[currentIndex].description, desc);
    
    heapSize++; 

    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;

        if (heap[currentIndex].priority < heap[parentIndex].priority) {
            
            struct Task temp = heap[currentIndex];
            heap[currentIndex] = heap[parentIndex];
            heap[parentIndex] = temp;

            currentIndex = parentIndex;
        } else {
            break;
        }
    }
    printf("\nTask added with priority %d!\n", priority);
}

void getNextTask() {
    if (heapSize == 0) {
        printf("\nNo tasks in the Todo List.\n");
        return;
    }

    struct Task highestPriorityTask = heap[0];
    printf("\nRunning Task: %s (Priority: %d)\n", highestPriorityTask.description, highestPriorityTask.priority);

    free(highestPriorityTask.description);

    heapSize--; 
    heap[0] = heap[heapSize]; 

    int currentIndex = 0;
    while (1) {
        int leftChild = 2 * currentIndex + 1;
        int rightChild = 2 * currentIndex + 2;
        int smallest = currentIndex; 

        if (leftChild < heapSize && heap[leftChild].priority < heap[smallest].priority) {
            smallest = leftChild;
        }

        if (rightChild < heapSize && heap[rightChild].priority < heap[smallest].priority) {
            smallest = rightChild;
        }

        if (smallest == currentIndex) {
            break;
        }

        struct Task temp = heap[currentIndex];
        heap[currentIndex] = heap[smallest];
        heap[smallest] = temp;

        currentIndex = smallest;
    }
}

void saveTasks() {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing tasks!\n");
        return;
    }

    for (int i = 0; i < heapSize; i++) {
        fprintf(file, "%d|%s\n", heap[i].priority, heap[i].description);
    }

    fclose(file);
    printf("Tasks saved.\n");
}

void loadTasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        return;
    }

    char line[256];
    int priority;
    char description[200];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d|%[^\n]", &priority, description) == 2) {
            addTask(description, priority);
        }
    }

    fclose(file);
    printf("Tasks loaded.\n");
}
