#include "../include/search.h"
#include <stdlib.h>
#include <string.h>

#define COUNT_USER 10000

Users *create_user_array(int size) {
    Users *users = calloc(1, sizeof(Users));
    if (users == NULL) {
        return NULL;
    }
    users->array = calloc(size, sizeof(User));
    if (users->array == NULL) {
        free(users);
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        users->array[i].name = calloc(20, sizeof(char));
        if (users->array[i].name == NULL) {
            free(users->array);
            free(users);
            return NULL;
        }
    }
    users->size = size;

    return users;
}

void free_user_array(Users *users) {
    if (users == NULL)
        return;
    for (int i = 0; i < users->size; ++i) {
        free(users->array[i].name);
    }
    free(users->array);
    free(users);
}

void get_id(Users *user_array, User *user) {
    for (int i = 0; i < user_array->size; ++i) {
        if (strcmp(user_array->array[i].name, user->name) == 0) {
            user->id = i;
            return;
        }
        if (strcmp(user_array->array[i].name, "") == 0) {
            user_array->array[i].name = user->name;
            user_array->array[i].id = i;
            user->id = i;
            return;
        }
    }
}

char *get_name_by_id(const Users *const user_array, const int id) {
    for (int i = 0; i < user_array->size; ++i) {
        if (user_array->array[i].id == id) {
            return user_array->array[i].name;
        }
    }
    return NULL;
}

int cmp_data_struct(const Data *const one, const Data *const two) {
    if (one == NULL || two == NULL)
        return 0;

    int data_1 = (one->year - 1990) * 365 * 24 * 60 + one->month * 30 * 24 * 60 + one->day * 24 * 60 + one->hour * 60 +
                 one->min;
    int data_2 = (two->year - 1990) * 365 * 24 * 60 + two->month * 30 * 24 * 60 + two->day * 24 * 60 + two->hour * 60 +
                 two->min;
    if (data_1 <= data_2) {
        return 1;
    } else {
        return 0;
    }
}

int in_data(const Data *const one, const Data *const two, const Letter *const letter) {
    if (one == NULL || two == NULL || letter == NULL)
        return 0;
    return cmp_data_struct(one, &letter->data) && cmp_data_struct(&letter->data, two);
}

int find_max_array(int *array) {
    int max_letters = 0;
    int id_max = -1;
    for (int i = 0; i < COUNT_USER; ++i) {
        if (array[i] > max_letters) {
            max_letters = array[i];
            id_max = i;
        }
    }
    return id_max;
}

int in_addressee(const User *const user, const Letter *const letter) {
    if (user == NULL || letter == NULL)
        return 0;
    char *result = strstr(letter->addressee, user->name);
    if (result == NULL)
        return 0;
    else
        return 1;
}

void fill_array(Letters *letters, int *array, User *user, Data *one, Data *two) {
    for (int i = 0; i < letters->size; ++i) {
        if (in_addressee(user, &letters->array[i]) && in_data(one, two, &letters->array[i]))
            ++array[letters->array[i].sender.id];
    }
}