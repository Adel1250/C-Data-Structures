#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *items;
    int head, tail, nitems, capacity;
} Queue;

Queue* initialize(int n)
{
    Queue *q = malloc(sizeof(Queue));
    q -> head = 0;
    q -> tail = 0;
    q -> nitems = 0;
    q -> capacity = n;
    q -> items = malloc(n*sizeof(int));
    return q;
}

void enqueue (Queue *q, int value)
{
    q -> items[q -> tail] = value;
    q -> tail = (q -> tail+1) % q -> capacity;
    q -> nitems++;
}

int dequeue (Queue *q)
{
    int value = q -> items[q -> head];
    q -> head = (q -> head+1) % q -> capacity;
    q -> nitems--;
    return value;
}

int isEmpty (Queue *q)
{
    if (q -> nitems == 0)
        return 1;
    else
        return 0;
}

int isFull (Queue *q)
{
    if (q -> nitems == q -> capacity)
        return 1;
    else
        return 0;
}

void diplayQueue (Queue *q)
{
    Queue *copy = initialize(q -> capacity);
    while (!isEmpty(q))
    {
        int x = dequeue(q);
        printf ("* %d\n",x);
        enqueue (copy, x);
    }
    while (!isEmpty(copy))
        enqueue (q,dequeue(copy));
}

int getHead (Queue *q)
{
    Queue *copy = initialize(q -> capacity);
    int value = dequeue (q);
    enqueue (copy, value);
    while (!isEmpty(q))
        enqueue (copy, dequeue(q));
    while (!isEmpty(copy))
        enqueue(q,dequeue(copy));
    return value;
}

int getTail (Queue *q)
{
    int value;
    Queue *copy = initialize(q -> capacity);
    while (!isEmpty(q))
    {
        value = dequeue(q);
        enqueue (copy, value);
    }
    while (!isEmpty(copy))
        enqueue (q,dequeue(copy));
    return value;
}

int main ()
{
    int cap, n, i, x;
    printf ("\n");
    printf ("** Queue Implementation **\n\n");
    printf ("* Enter the Queue's capacity : ");
    scanf ("%d",&cap);
    printf ("\n");
    Queue *myQueue = initialize(cap);
    printf ("* Enter the number of elements to be entered in the Queue : ");
    scanf ("%d",&n);
    printf ("\n");
    for ( i = 0 ; i < n ; i++ )
    {
        printf ("* Enter the term #%d : ",i+1);
        scanf ("%d",&x);
        printf ("\n");
        enqueue(myQueue,x);
    }
    printf ("* The queue :\n\n");
    diplayQueue(myQueue);
    printf ("\n* The first element in the Queue is %d\n\n",getHead(myQueue));
    printf ("* The last element of the Queue is %d\n\n",getTail(myQueue));
    printf ("*** Thanks ! ***\n\n");
}
