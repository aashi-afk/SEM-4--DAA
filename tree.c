#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *left;
    int val;
    struct Node *right;
};

struct Node *createNode(int val) {
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int findHeight(struct Node *node) {
    if (node == NULL) return 0;
    else
        return 1 + max(findHeight(node->left), findHeight(node->right));
}

struct Node *createTree(struct Node *node) {
    int val;
    char choice;
    if (node == NULL) {
        printf("Enter value to insert: ");
        scanf("%d", &val);
        node = createNode(val);
    }
    printf("Want to create left child for %p -> %d? (Y/N): ", node, node->val);
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
        node->left = createTree(node->left);

    printf("Want to create right child for %p -> %d? (Y/N): ", node, node->val);
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
        node->right = createTree(node->right);

    return node;
}

void inorder(struct Node *node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

int main() {
    struct Node *root;
    root = NULL;
    root = createTree(root);

    printf("Inorder traversal of the tree: ");
    inorder(root);
    printf("\n");
    return 0;
}
