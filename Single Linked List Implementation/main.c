#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} Linkedlist;

Node* newNode (int data)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n -> data = data;
    n -> next = NULL;
    return n;
}

Linkedlist* initialize ()
{
    Linkedlist *l = (Linkedlist*)malloc(sizeof(Linkedlist));
    l -> head = NULL;
    l -> tail = NULL;
    return l;
}

void insertBeginning (Linkedlist *l, int value)
{
    Node *n = newNode(value);
    if (l -> head == NULL)
        l -> head = l -> tail = n;
    else
    {
        n -> next = l -> head;
        l -> head = n;
    }
}

void insertEnd (Linkedlist *l, int value)
{
    Node *n = newNode(value);
    if (l -> head == NULL)
        l -> head = l -> tail = n;
    else
    {
        l -> tail -> next = n;
        l -> tail = n;
    }
}

void deleteBeginning (Linkedlist *l)
{
    if (l -> head)
    {
        Node *temp = l -> head;
        l -> head = l -> head -> next;
        free(temp);
        if (l -> head == NULL)
            l -> tail = NULL;
    }
}

void deleteEnd (Linkedlist *l)
{
    if (l -> head)
    {
        Node *temp = l -> head;
        Node *prev = NULL;
        while (temp -> next != NULL)
        {
            prev = temp;
            temp = temp -> next;
        }
        free (temp);
        if (prev == NULL)
        {
            l -> head = l -> tail = NULL;
        }
        else
        {
            prev -> next = NULL;
            l -> tail = prev;
        }
    }
}

void displayList (Linkedlist *l)
{
    Node *temp = l -> head;
    while (temp != NULL)
    {
        printf ("* %d\n",temp -> data);
        temp = temp -> next;
    }
}

int main ()
{

}
