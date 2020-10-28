#ifndef IZ_2_LETTER_H
#define IZ_2_LETTER_H

//Время
typedef struct data {
    int day;
    int month;
    int year;
    int hour;
    int min;
} Data;

//Пользователь
typedef struct user {
    char *name;
    int id;
} User;

//Письмо
typedef struct letter {
    Data data;
    User sender;
    char *text;
    char *tittle;
    char *addressee;
} Letter;

//Массив писем
typedef struct letter_array {
    Letter *array;
    int size;
} Letters;

//Конструктор для массива писем
Letters *create_letter_array(int size);
//Деструктор для массива писем
void free_letter_array(Letters *letters);

//Конструктор пользователя
User *create_user();
//Деструктор пользователя
void free_user(User *user);

//Ввести письмо из консоли
int read_letter(Letter *letter);

//Ввести дату из консоли
int read_data(Data *data);

//Ввести данные пользователя из консоли
int read_user(User *user);

#endif //IZ_2_LETTER_H
