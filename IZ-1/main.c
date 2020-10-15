#include <stdio.h>
#include "functions.h"

void insertion_sort(t_symbol* mas, const int Size) {
    for (int i = 1; i < Size; ++i) {
        t_symbol temp = mas[i];
        int j = i-1;
        for (; j>=0 && temp.count < mas[j].count; --j)
            mas[j+1] = mas[j];
        mas[j+1] = temp;
    }
}

void read_file(FILE* fo, t_symbol* mas) {
    int symbol;
    symbol = fgetc(fo);
    while (symbol != EOF) {
        if ((symbol>=65 && symbol<=90) || (symbol>=97 && symbol<=122))//'A'-'Z', 'a'-'z'
            mas[symbol].count += 1;
        symbol = fgetc(fo);
    }
}

int main(void) {
    t_symbol symbols[256];
    for (int i = 0; i < 256; ++i) {
        symbols[i].count = 0;
        symbols[i].code = i;
    }

    //Open file, read from a file, close file
    FILE *f;
    f = fopen("text.txt", "r");
    if (NULL == f) {
        printf("The file did not open.\n");
        return -1;
    }

    //Fill array
    read_file(f, symbols);

    if (fclose(f) == EOF)
        printf("The file did not close.\n");

    //Sorting
    insertion_sort(symbols, 256);

    //Output on display
    printf("Most unpopular char - \n");
    for (int i = 0; i < 256; ++i)
        if (symbols[i].count != 0)
            printf("%c (%d) \n", (char)symbols[i].code, symbols[i].count);
    printf("- most popular char.\n");
    return 0;
}
