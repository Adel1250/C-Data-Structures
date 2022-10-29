#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Key char*

typedef enum Color {black, red} Color;

typedef struct Node
{
    Color color;
    Key key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;


Node* newNode(Key key)
{
    Node* node = malloc(sizeof(Node));
    node->color = red;
    node->key = malloc(strlen(key)+1);
    strcpy(node->key, key);
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

Node* leftRotate(Node* root, Node* x)
{
    Node* y = x->right;

    x->right = y->left;

    if(y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if(x->parent == NULL)
        root = y;
    else
    {
        if(x->parent->left == x)
        {
            x->parent->left = y;

        }
        else
        {
            x->parent->right = y;

        }
    }

    y->left = x;
    x->parent = y;


    return root;
}

Node* rightRotate(Node* root, Node* x)
{

    Node* y = x->left;

    x->left = y->right;

    if(y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if(x->parent == NULL)
        root = y;
    else
    {
        if(x->parent->right == x)
            x->parent->right = y;
        else
            x->parent->left = y;
    }

    y->right = x;
    x->parent = y;

    return root;

}

void printNode(Node* node)
{
    if(node)
    {
        printf("Node:%s - ", node->key);
        printf("%s\n", node->color? "red":"black");
    }

    if(node->parent)
        printf("p:%s\n", node->parent->key);

    if(node->left)
        printf("l:%s\n", node->left->key);

    if(node->right)
        printf("r:%s\n", node->right->key);
}

Node* search(Node* root, Key key)
{
    if(!root || strcasecmp(root->key,key) == 0)
        return root;
    else if(strcasecmp(root->key,key) < 0)
        return search(root->right, key);
    else
        return search(root->left, key);
}

Node* insert_recursive(Node* root, Key key)
{

    if(!root)
    {

        return newNode(key);
    }

    if(strcasecmp(key, root->key) > 0)
    {
        root->right = insert_recursive(root->right, key);
        root->right->parent = root->right;
    }
    else if(strcasecmp(key, root->key) < 0)
    {
        root->left = insert_recursive(root->left, key);
        root->left->parent = root->left;
    }

    return root;
}


int isBlack(Node* x)
{
    return !x || x->color == black;
}

Node* insert_fixup(Node* root, Node* z)
{

    if(z == root)
    {
        z->color = black;
        return z;
    }

    Node* grand_parent = z->parent->parent;
    if(!grand_parent)
    {
        return root;
    }
    if(z->parent->color == red)
    {


        if(!isBlack(grand_parent->left) && !isBlack(grand_parent->right))
        {
            grand_parent->color = red;
            grand_parent->left->color = black;
            grand_parent->right->color = black;
            root = insert_fixup(root, grand_parent);
        }

        else
        {
            if(z->parent == grand_parent->left)
            {
                if(z == z->parent->right)
                {
                    root = leftRotate(root, z->parent);
                    z->color = black;
                    z->parent->color = red;
                }
                else
                {
                    z->parent->color = black;
                    z->parent->parent->color = red;
                }

                root = rightRotate(root, grand_parent);

            }
            else
            {
                if(z == z->parent->left)
                {
                    root = rightRotate(root, z->parent);
                    z->color = black;
                    z->parent->color = red;
                }
                else
                {
                    z->parent->color = black;
                    z->parent->parent->color = red;
                }
                root = leftRotate(root, grand_parent);
            }
        }
    }
    return root;

}

Node* insert(Node* root, Key key)
{

    Node* new_node = newNode(key);
    Node* curr = root;

    Node* prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        if (strcasecmp(key, curr->key) < 0)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (prev == NULL)
    {
        prev = new_node;
        prev->color = black;
        return prev;
    }


    if (strcasecmp(key, prev->key) < 0)
    {
        prev->left = new_node;
        new_node->parent = prev;
        root = insert_fixup(root, new_node);
    }

    else
    {
        prev->right = new_node;
        new_node->parent = prev;
        root = insert_fixup(root, new_node);
    }


    return root;
}

int size(Node* root)
{
    if(!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}



int max(int x, int y)
{
    return x>y? x:y;
}

int height(Node* root)
{
    if(!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void Inorder(Node* root)
{
    if (root == NULL)
        return;
    else
    {
        Inorder(root->left);
        printf("%s\n", root->key);
        Inorder(root->right);
    }
}


int main()
{
    char word[25];

    FILE *fp;
    fp = fopen("EN-US-Dictionary.txt","r");
    if(fp == NULL)
    {
        printf("Error !");
        exit(0);
    }

    Node* root = NULL;
    fscanf(fp, "%s", word);

    while(!feof(fp))
    {
        root = insert(root, word);
        fscanf(fp, "%s", word);
    }

    int choice;

    system("cls");
    system("COLOR F0");
    printf("\n** Dictionary **\n\n");
    do
    {
        printf("\n* RBT size: %d\n", size(root));
        printf("* RBT height: %d\n\n", height(root));

        printf("* Choose one of the following options:\n\n");
        printf("  1.Insert a new word to dictionary\n");
        printf("  2.Search for a word in the dictionary\n");
        printf("  3.Exit\n\n");

        printf("* Your choice: ");

        scanf("%d", &choice);

        system("cls");

        if(choice != 1 && choice != 2 && choice != 3)
        {
            printf("\nXX Invalid choice please choose one of the 2 operations XX\n");
            continue;
        }

        switch (choice)
        {

        case 1:
            printf("* Enter the word you want to insert please: ");
            scanf("%s", word);
            if(!search(root, word))
            {
                insert(root, word);
                printf("\n* Word inserted successfully *\n");
            }
            else
                printf("\n* %s already exists\n", word);
            break;
        case 2:
            printf("* Enter the word you want to search for please: ");
            scanf("%s", word);
            printf("\n* %s\n\n", search(root, word)? "FOUND!":"NOT FOUND!");
            break;
        case 3:
            break;

        }
    }
    while(choice != 3);

    return 0;
}
