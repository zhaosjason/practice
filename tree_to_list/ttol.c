#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "list.h"

#define N 15
//#define DEBUG 0

// Preorder traversal of tree
LNode * TreeToList(TNode *root, LNode **last) {
	if (root == NULL)
		return NULL;

#ifdef DEBUG
	printf("Adding value=%d\n", *(int *) root->value);
#endif

	LNode *temp = malloc(sizeof(LNode));
	temp->value = root->value;
	temp->prev = *last;
	temp->next = NULL;

	if (*last != NULL)
		(*last)->next = temp;

	*last = temp;

	TreeToList(root->left, last);
	TreeToList(root->right, last);

	return temp;
}

int main() {
	int *input = malloc(sizeof(int) * N);
	int *ptr = input;

	int i;
	for (i = 1; i <= N; i++) {
		*ptr++ = i;
	}

	TNode *root = malloc(sizeof(TNode));
	init_tree(root);

	buildTree(root, input, N, 0);

	printf("Preorder traversal: ");
	preorderPrint(root);
	printf("\n");

	List *l = malloc(sizeof(List));
	init_list(l);

	LNode **last = malloc(sizeof(LNode *));
	*last = NULL;

	l->head = TreeToList(root, last);	
	
	printf("    List traversal: ");
	printList(l);
	return 0;
}
