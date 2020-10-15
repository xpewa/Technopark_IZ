#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>

typedef struct t_symbol {
    int code;
    int count;
} t_symbol;

void insertion_sort(t_symbol* mas, const int Size);
void read_file(FILE* fo, t_symbol* mas);

#endif //FUNCTIONS_H
