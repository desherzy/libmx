#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == 0) {
        return malloc(size);
    }

    //malloc_usable_size for Linux
    //size_t lenght = malloc_usable_size(ptr);

    //malloc_size for macOS
    size_t lenght = malloc_size(ptr);

    if (size <= lenght) {
        return ptr;
    }

    void *temp = malloc(size);
    mx_memcpy(temp, ptr, lenght);
    free(ptr);
    return temp;
}

