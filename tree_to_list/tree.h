#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
	void *value;
	struct TNode *left;
	struct TNode *right;
} TNode;

static inline void init_tree(TNode *root) {
	root->value = NULL;
	root->left = NULL;
	root->right = NULL;
}

/**
 * Builds a tree from a space-deliminated L-R BFT 
 * @param data: -1 if NULL
 */
TNode * buildTree(TNode *root, int *data, int len, int index);

void preorderPrint(TNode *root);

#endif /* TREE_H */
