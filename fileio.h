#ifndef FILEIO_H
#define FILEIO_H

#include "task.h"

void saveTasks(Task* head);
void loadTasks(Task** head, int* idCounter);

#endif
