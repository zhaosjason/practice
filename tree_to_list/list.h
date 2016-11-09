#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	struct LNode *head;
} List;

typedef struct LNode {
	void *value;
	struct LNode *next;
	struct LNode *prev;
} LNode;

static inline void init_list(List *l) {
	l->head = NULL;
}

void printList(List *l);

#endif /* LIST_H */
