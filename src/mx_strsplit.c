#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    int counter = mx_count_words(s, c);
    char **splitted = (char **)malloc(8 * counter);

    int lenght = 0;
    int j = 0;

    for (int i = 0; i < counter; i++) {
        int next = 0;

        for (; s[j]; j++) {
            if (s[j] != c) {
                lenght += 1;

                if (next == 0) {
                    next = j;
                }
            }
            else if (s[j] == c && lenght) {
                break;
            }
        }

        char *string = mx_strnew(lenght);
        
        for (int k = 0; next < j; k++) {
            string[k] = s[next];
            next++;
        }

        splitted[i] = string;
    }

    splitted[lenght] = NULL;
    
    return splitted;
}

