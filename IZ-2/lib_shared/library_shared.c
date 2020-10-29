#include "library_shared.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <stdio.h>
#include <sys/sysinfo.h>

#define COUNT_USER 10000

int NUM_THREADS;

typedef struct args {
    int *array;
    Letters *letters;
    User *user;
    Data *one;
    Data *two;
    pthread_mutex_t mutex;
    int th_id;
} Thr_args;


void *th_fill_array(void *args) {
    Thr_args *arg = ((Thr_args *)args);
    for (int i =arg->th_id; i < arg->letters->size; i+=NUM_THREADS) {
        if (in_addressee(arg->user, &arg->letters->array[i]) && in_data(arg->one, arg->two, &arg->letters->array[i])) {
            pthread_mutex_lock(&(arg->mutex));
            arg->array[arg->letters->array[i].sender.id] += 1;
            pthread_mutex_unlock(&(arg->mutex));
        }
    }
    return  0;
}

char *th_find_max_letter_sender(Letters *letters, User *user, Data *one, Data *two) {
    //Количество ядер процессора
    NUM_THREADS = get_nprocs();

    pthread_t threads[NUM_THREADS];
    Thr_args args[NUM_THREADS];

    int *array = calloc(COUNT_USER, sizeof(int));
    Users *users = create_user_array(COUNT_USER);
    pthread_mutex_t mutex;
    pthread_mutex_init(&(mutex), NULL);
    for (int i=0; i<NUM_THREADS; ++i) {
        args[i].one = one;
        args[i].two = two;
        args[i].letters = letters;
        args[i].user = user;

        args[i].array = array;
        args[i].mutex = mutex;
    }

    for (int i = 0; i < letters->size; ++i) {
        get_id(users, &letters->array[i].sender);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        args[i].th_id = i;
        pthread_create(&threads[i], NULL, th_fill_array, &args[i]);
    }

    for (int i=0; i<NUM_THREADS; ++i) {
        pthread_join(threads[i],NULL);
    }

    for (int i=0; i<7; ++i) {
        printf(" array[%d] = %d ", i, array[i]);
    }

    int result_id = find_max_array(array);
    printf("\n max_id = %d\n", result_id);

    char *result = calloc(20, sizeof(char));
    strcpy(result, "none");
    if (result_id != -1)
        result = get_name_by_id(users, result_id);

    return result;
}
