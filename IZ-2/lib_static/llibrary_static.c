#include "llibrary_static.h"
#include <stdlib.h>
#include <string.h>

#define COUNT_USER 10000

char *find_max_letter_sender(Letters *letters, User *user, Data *one, Data *two) {
    int *array = calloc(COUNT_USER, sizeof(int));
    Users *users = create_user_array(COUNT_USER);
    for (int i = 0; i < letters->size; ++i) {
        get_id(users, &letters->array[i].sender);
    }

    fill_array(letters, array, user, one, two);

    int result_id = find_max_array(array);
    char *result = calloc(20, sizeof(char));
    strcpy(result, "none");
    if (result_id != -1)
        result = get_name_by_id(users, result_id);
    return result;
}