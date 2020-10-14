#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>

typedef struct t_symbol {
    int code;
    int count;
} t_symbol;

void InsertionSort(t_symbol* mas, int Size);
void ReadFile(FILE* fo, t_symbol* mas);

#endif //FUNCTIONS_H
