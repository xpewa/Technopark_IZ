#include "../include/letter.h"
#include <stdio.h>
#include <stdlib.h>

Letters *create_letter_array(int size) {
    Letters *letters = calloc(1, sizeof(Letters));
    if (letters == NULL) {
        return NULL;
    }
    letters->array = calloc(size, sizeof(Letter));
    for (int i = 0; i < size; ++i) {
        letters->array[i].text = calloc(400, sizeof(char));
        if (letters->array[i].text == NULL) {
            free(letters->array);
            free(letters);
            return NULL;
        }
        letters->array[i].tittle = calloc(30, sizeof(char));
        if (letters->array[i].tittle == NULL) {
            free(letters->array->text);
            free(letters->array);
            free(letters);
            return NULL;
        }
        letters->array[i].addressee = calloc(20 * 20, sizeof(char));
        if (letters->array[i].addressee == NULL) {
            free(letters->array->tittle);
            free(letters->array->text);
            free(letters->array);
            free(letters);
            return NULL;
        }
        letters->array[i].sender.name = calloc(20, sizeof(char));
        if (letters->array[i].sender.name == NULL) {
            free(letters->array->addressee);
            free(letters->array->tittle);
            free(letters->array->text);
            free(letters->array);
            free(letters);
            return NULL;
        }
    }
    letters->size = size;

    return letters;
}

void free_letter_array(Letters *letters) {
    if (letters == NULL) {
        return;
    }
    free(letters->array->sender.name);
    free(letters->array->addressee);
    free(letters->array->tittle);
    free(letters->array->text);
    free(letters->array);
    free(letters);
}

User *create_user() {
    User *user = calloc(1, sizeof(User));
    if (user == NULL) {
        return NULL;
    }
    user->name = calloc(20, sizeof(char));
    if (user->name == NULL) {
        free(user);
        return NULL;
    }

    return user;
}

void free_user(User *user) {
    if (user == NULL)
        return;
    free(user->name);
    free(user);
}

int read_letter(Letter *letter) {
    if (letter == NULL)
        return 0;

    int result = scanf("%21s %31s %401s %401s %d.%d.%d %d:%d", letter->sender.name, letter->tittle, letter->text,
                       letter->addressee, &letter->data.day, &letter->data.month, &letter->data.year,
                       &letter->data.hour, &letter->data.min);
    if (result == 9) {
        return 1;
    } else {
        return 0;
    }
}

int read_data(Data *data) {
    if (data == NULL)
        return 0;

    int result = scanf("%d.%d.%d %d:%d", &data->day, &data->month, &data->year, &data->hour, &data->min);
    if (result == 5) {
        return 1;
    } else {
        return 0;
    }
}

int read_user(User *user) {
    if (user == NULL)
        return 0;

    int result = scanf("%21s", user->name);
    if (result == 1) {
        return 1;
    } else {
        return 0;
    }
}