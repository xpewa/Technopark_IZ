#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "include/letter.h"

#define COUNT_LETTERS 1000000
void *library;

int main() {
    //Подключение библиотеки
    library = dlopen("lib_shared/libshared_lib.so", RTLD_LAZY);
    if (!library) {
        printf("Library error.");
        return 0;
    }
    char * (*th_find_max_letter_sender)(Letters *letters, User *user, Data *one, Data *two);
    th_find_max_letter_sender = dlsym(library, "th_find_max_letter_sender");
    if (!th_find_max_letter_sender) {
        printf("Can`t find function in library.");
        return 0;
    }

    //Количество писем
    int size_letters = 0;
    printf("Write count of letters\n");
    while (scanf("%d", &size_letters) != 1 || size_letters > COUNT_LETTERS || size_letters < 1) {
        printf("Input error. Try again.");
        while ((getchar()) != '\n');
    }

    Letters *letters = create_letter_array(size_letters);
    if (letters == NULL) {
        printf("Allocation error.\n");
        return 0;
    }

    //Чтение писем
    printf("Write letters. Format: Sender_name tittle text addressee "
           "dd.mm.yyyy h:m\n");
    for (int i = 0; i < letters->size; i++) {
        if (!read_letter(&letters->array[i])) {
            i--;
            printf("Input error. Try again.\n");
            while ((getchar()) != '\n');
        }
    }

    //Чтение искомого пользователя
    User *user = create_user();
    if (user == NULL) {
        printf("Allocation error.\n");
        free_letter_array(letters);
        return 0;
    }
    printf("Write user. Format: name\n");
    while (!read_user(user)) {
        printf("Input error. Try again.\n");
        while ((getchar()) != '\n');
    }

    // чтение периода для поиска
    Data *data_one = calloc(1, sizeof(Data));
    if (data_one == NULL) {
        printf("Allocation error.\n");
        free_letter_array(letters);
        free_user(user);
        return 0;
    }
    Data *data_two = calloc(1, sizeof(Data));
    if (data_two == NULL) {
        printf("Allocation error.\n");
        free(data_one);
        free_letter_array(letters);
        free_user(user);
        return 0;
    }
    printf("Write data(from). Format: dd.mm.yyyy h:m\n");
    if (!read_data(data_one)) {
        printf("Input error. Try again.\n");
        while ((getchar()) != '\n');
    }
    printf("Write data(to). Format: dd.mm.yyyy h:m\n");
    if (!read_data(data_two)) {
        printf("Input error. Try again.\n");
        while ((getchar()) != '\n');
    }

    //Вызов библиотечной функции
    char *result = (*th_find_max_letter_sender)(letters, user, data_one, data_two);
    printf("Result: %s\n", result);

    free(data_one);
    free(data_two);
    free_user(user);
    free_letter_array(letters);
    dlclose(library);
    return 0;
}

