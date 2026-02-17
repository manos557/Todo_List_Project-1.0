#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Note {
    char* text;
    struct Note* next;
};

void addNote(char* text);
void displayAllNotes();
void deleteNote(int index);
void saveNotes();
void loadNotes();

#endif
