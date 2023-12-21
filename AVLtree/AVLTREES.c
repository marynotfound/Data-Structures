#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} AVLTREE;

int height(AVLTREE *x) {
    if (x == NULL) {
        return -1;
    }
    return x->height;
}

int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

AVLTREE* newNode(int data) {
    AVLTREE* node = (AVLTREE*)malloc(sizeof(AVLTREE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

AVLTREE *rightRotate(AVLTREE *z) {
    AVLTREE *temp = z->left;
    z->left = temp->right;
    temp->right = z;

    z->height = maxValue(height(z->left), height(z->right)) + 1;
    temp->height = maxValue(height(temp->left), height(temp->right)) + 1;
    return temp;
}

AVLTREE *leftRotate(AVLTREE *z) {
    AVLTREE *temp = z->right;
    z->right = temp->left;
    temp->left = z;

    z->height = maxValue(height(z->left), height(z->right)) + 1;
    temp->height = maxValue(height(temp->left), height(temp->right)) + 1;
    return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z) {
    z->left = leftRotate(z->left);
    return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z) {
    z->right = rightRotate(z->right);
    return leftRotate(z);
}

void inOrder(AVLTREE *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data); 
        inOrder(root->right);
    }
}

AVLTREE *insertToAVL(AVLTREE *tree, int x) {
    if (tree != NULL) {
        if (x < tree->data)
            tree->left = insertToAVL(tree->left, x);
        else if (x > tree->data)
            tree->right = insertToAVL(tree->right, x);
        else
            return tree;

        tree->height = 1 + maxValue(height(tree->left), height(tree->right));

        int balance = height(tree->left) - height(tree->right);

        if (balance > 1 && x < tree->left->data)
            return rightRotate(tree);

        if (balance > 1 && x > tree->left->data)
            return leftRightRotate(tree);

        if (balance < -1 && x > tree->right->data)
            return leftRotate(tree);

        if (balance < -1 && x < tree->right->data)
            return rightLeftRotate(tree);
    } else {
        tree = newNode(x);
    }
    return tree;
}

int main(int argc, char *argv[]) {
    AVLTREE* myroot = NULL;
    int i ; 
    scanf("%d",&i);
    while(i!=-1){
    	myroot=insertToAVL(myroot,i);
    	scanf("%d",&i);
	}
   
    inOrder(myroot);
    
    return 0;
}
