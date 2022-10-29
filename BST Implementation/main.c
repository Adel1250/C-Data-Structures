#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node* newNode (int value)
{
    Node *n = malloc(sizeof(Node));
    n -> data = value;
    n -> right = NULL;
    n -> left = NULL;
    return n;
}

Node* insert(Node* n, int value)
{
    if (n == NULL)
        return newNode(value);
    if (value < n -> data)
        n -> left = insert(n -> left, value);
    else if (value > n -> data)
        n -> right = insert(n -> right, value);
    return n;
}

void InOrdertraverse(Node *t)
{
    if (t != NULL)
    {
        InOrdertraverse(t->left);
        printf("* %d\n", t->data);
        InOrdertraverse(t->right);
    }
}

int main()
{
    printf ("\n");
    printf ("** Binary Search Tree **\n\n");
    Node *root = NULL;
    root = insert(root, 3);
    insert(root, 5);
    insert(root, 1);
    InOrdertraverse(root);
    printf ("\n*** Thanks ! ***\n\n");
}
