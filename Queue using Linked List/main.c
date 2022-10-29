#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} Queue;

Node* newNode (int data)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n -> data = data;
    n -> next = NULL;
    return n;
}

Queue* initialize ()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q -> head = NULL;
    q -> tail = NULL;
    return q;
}

void enqueue (Queue *q, int value)
{
    Node *n = newNode(value);
    if (q -> head == NULL)
        q -> head = q -> tail = n;
    else
    {
        q -> tail -> next = n;
        q -> tail = n;
    }
}

int dequeue (Queue *q)
{
    int value;
    if (q -> head)
    {
        Node *temp = q -> head;
        value = temp -> data;
        q -> head = q -> head -> next;
        free(temp);
        if (q -> head == NULL)
            q -> tail = NULL;
    }
    return value;
}

int isEmpty (Queue *q)
{
    if (q -> head == NULL)
        return 1;
    else
        return 0;
}

void displayQueue (Queue *q)
{
    Node *temp = q -> head;
    while (temp != NULL)
    {
        printf ("* %d\n",temp -> data);
        temp = temp -> next;
    }
}

int main ()
{
    int n, i, x;
    Queue *myQueue = initialize();
    printf ("\n");
    printf ("** Queue using Linked List **\n\n");
    printf ("* Enter the number of elements to be entered in the Queue : ");
    scanf ("%d",&n);
    printf ("\n");
    for ( i =  0 ; i < n ; i++ )
    {
        printf ("* Enter the term #%d : ",i+1);
        scanf ("%d",&x);
        printf ("\n");
        enqueue(myQueue,x);
    }
    printf ("* The Queue :\n\n");
    displayQueue(myQueue);
    printf ("\n*** Thanks ! ***\n\n");
    return 0;
}
