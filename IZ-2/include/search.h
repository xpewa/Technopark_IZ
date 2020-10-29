#ifndef IZ_2_SEARCH_H
#define IZ_2_SEARCH_H

#include "letter.h"

//Массив пользователей
typedef struct user_array {
    User *array;
    int size;
} Users;

Users *create_user_array(int size);

void free_user_array(Users *users);

//Назначение пользователю id по имени
void get_id(Users *user_array, User *user);

//Получение имени пользователя по id
char *get_name_by_id(const Users *const user_array, const int id);

//Сравнение дат (структур)
int cmp_data_struct(const Data *const one, const Data *const two);

//Проверка времени отправки сообщения
int in_data(const Data *const one, const Data *const two, const Letter *const letter);

//Проверка имени получателя с именем пользователя
int in_addressee(const User *const user, const Letter *const letter);

//Поиск в вспомогательном массиве
int find_max_array(int *array);

//Заполнение вспомогательного массива
void fill_array(Letters *letters, int *array, User *user, Data *one, Data *two);

#endif //IZ_2_SEARCH_H
