#include <stdio.h>
#include <stdlib.h>

typedef struct t_symbol {
    int code;
    int count;
} t_symbol;

void BubbleSort(t_symbol* mas) {
    for (int i = 0; i + 1 < 256; ++i)
        for (int j = 0; j + 1 < 256; ++j)
            if (mas[j + 1].count < mas[j].count) {
                t_symbol tmp = mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = tmp;
            }
}

int main(void) {
    system("cls");
    system("color 70");

    t_symbol symbols[256];
    for (int i = 0; i < 256; ++i) {
        symbols[i].count = 0;
        symbols[i].code = i;
    }

    //Opening and reading from a file
    FILE *f;
    f = fopen("text.txt", "r");
    if (NULL == f) {
        printf("The file did not open.");
        return -1;
    }
    int symbol;
    symbol = fgetc(f);
    while (symbol != EOF) {
        if ((symbol>=65 && symbol<=90) || (symbol>=97 && symbol<=122))
            symbols[symbol].count += 1;
        symbol = fgetc(f);
    }

    //Sorting
    BubbleSort(symbols);

    //Output on display
    printf("Most unpopular char - \n");
    for (int i = 0; i < 256; ++i)
        if (symbols[i].count != 0)
            printf("%c (%d) \n", (char)symbols[i].code, symbols[i].count);
    printf("- most popular char.");
            
    return 0;
}