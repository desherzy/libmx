#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    char c;
    int i = 0;

    if (fd < 0) { 
        return NULL;
    }

    int lenght = 0;
    while (read(fd, &c, 1)) {
        lenght++;
    }
    close(fd);

    char *str = mx_strnew(lenght);
    
    fd = open(file, O_RDONLY);
    while (read(fd, &c, 1)) {
        str[i] = c;
        i++;
    }

    close(fd);
    return str;
}

