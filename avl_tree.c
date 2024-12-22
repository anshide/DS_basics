#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getheight(struct Node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

struct Node *createNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getbalancefactor(struct Node *n) {
    if (n == NULL) {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct Node *rightrotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return x;
}

struct Node *leftrotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        // Duplicate keys are not allowed in AVL Tree
        return node;
    }

    node->height = 1 + max(getheight(node->left), getheight(node->right));

    int bf = getbalancefactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key) {
        return rightrotate(node);
    }

    // Right Right Case
    if (bf < -1 && key > node->right->key) {
        return leftrotate(node);
    }

    // Left Right Case
    if (bf > 1 && key > node->left->key) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d\n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);

    return 0;
}
 