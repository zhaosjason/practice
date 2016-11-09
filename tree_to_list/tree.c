#include "tree.h"

//#define DEBUG 0

TNode * buildTree(TNode *root, int *data, int len, int index) {
    if (index >= len || data[index] == -1)
        return NULL;

#ifdef DEBUG
    printf("Adding index=%d val=%d\n", index, data[index]);
#endif

    if (index == 0) {
        root->value = &data[index];
        root->left = buildTree(root, data, len, index * 2 + 1);
        root->right = buildTree(root, data, len, index * 2 + 2);
        return root;
    }

    TNode *temp = malloc(sizeof(TNode));
    temp->value = &data[index];
    temp->left = buildTree(temp, data, len, index * 2 + 1);
    temp->right = buildTree(temp, data, len, index * 2 + 2);
    return temp;
}

void preorderPrint(TNode *root) {
    if (root == NULL)
        return;

    printf("%d ", *(int *) root->value);
    preorderPrint(root->left);
    preorderPrint(root->right);
}


