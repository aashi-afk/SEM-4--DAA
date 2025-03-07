// BST
//time complexity of bst= log n
// height of tree= log n base 2
//search an element-> log n base 2

//left/right skewed tree- search=O(n)
//balanced BST:[avl tree]  balanced factor(Bf)=[-1,0,1]
//Bf= height of left sub tree- height of right sub tree

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *left;
    int val;
    struct Node *right;
};

struct Node *createNode(int val)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->val = val;
    return temp;
}

struct Node *insertNode(struct Node *node,int val)
{
    if(node == NULL)
    {
        node = createNode(val);
        return node;
    }
    if(val<node -> val)
        node->left = insertNode(node->left,val);
    else
        node->right = insertNode(node->right, val);
    return node;
}
void preorder(struct Node *node)
{
    if(!node) return;

    printf("/n %p->%d\n",node,node->val);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node)
{
    if(!node) return;

    inorder(node->left);
    printf("/n %p->%d\n",node,node->val);
    inorder(node->right);
}

void postorder(struct Node *node)
{
    if(!node) return;

    postorder(node->left);
    postorder(node->right);
    printf("/n %p->%d\n",node,node->val);
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int treeHeight(struct Node *node)
{
    if(!node) return 0;
    return 1+max(treeHeight(node->left),treeheight(node->right));
}

int Bf(struct Node *node)
{
    int BalanceFactor= treeHeight(node->left)- treeHeight(node->right);
    return BalanceFactor;
}
int main()
{
    int a[]={7,12,18,10,27,3,5,4,45};
    int n = sizeof(a)/sizeof(int);
    int i;
    struct Node *root;
    root=NULL;
    for (i=0;i<n;i++)
    {
        root = insertNode(root,a[i]);
    }
    printf("preorder sequence is:\n");
    preorder(root);
    printf("inorder sequence is:\n");
    inorder(root);
    printf("postorder sequence is:\n");
    postorder(root);
    treeHeight(root);
    Bf(root);
}
