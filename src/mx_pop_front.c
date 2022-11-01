#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    t_list *node = (*head)->next;

    if (head == NULL || (*head) == NULL) {
        return;
    }

    if (node != NULL) {
        free(*head);
        *head = node;   
    }
    else {
        free(*head);
        *head = NULL;
    }
}

