#include "list.h"

void printList(List *l) {
    LNode *temp = l->head;
    while (temp != NULL) {
        printf("%d ", *(int *) temp->value);
        temp = temp->next;
    }

    printf("\n");
}


