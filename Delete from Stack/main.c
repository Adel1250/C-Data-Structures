#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int items[MAXSIZE];
    int top;
} Stack;

Stack* initialize ()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = 0;
    return s;
}

void push (Stack *s, int value)
{
    s->items[s->top] = value;
    s->top++;
}

int pop (Stack *s)
{
    int value;
    s->top--;
    value = s->items[s->top];
    return value;
}

int isEmpty (Stack *s)
{
    if (s->top == 0)
    {
        return 1;
    }
    else
        return 0;
}

int top (Stack *s)
{
    return s->items[s->top-1];
}

int isFull (Stack *s)
{
    if (s->top == MAXSIZE)
    {
        return 1;
    }
    else
        return 0;
}

void StackDisplay (Stack *s)
{
    Stack *copy = initialize();
    int x;
    while (! isEmpty(s))
    {
        x = pop(s);
        printf ("* %d\n",x);
        push (copy,x);
    }
    while (! isEmpty(copy))
    {
        push(s,pop(copy));
    }
}

int stackCount (Stack *s)
{
    int count = 0;
    Stack *copy = initialize();
    while (!isEmpty(s))
    {
        push (copy,pop(s));
        count++;
    }
    while (!isEmpty(copy))
    {
        push (s,pop(copy));
    }
    return count;
}

void stackDelete (Stack *s, int pos)
{
    int index = pos-1, i;
    Stack *copy = initialize();
    for ( i = 0 ; i < index ; i++ )
    {
        push (copy,pop(s));
    }
    pop(s);
    while (!isEmpty(copy))
    {
        push(s,pop(copy));
    }
}

int main()
{
    int n, i, x;
    printf ("\n");
    printf ("** Delete from Stack **\n\n");
    printf ("* Enter the number of elements to be added in the stack: ");
    scanf ("%d",&n);
    printf ("\n");

    Stack* star = initialize();

    for ( i = 0 ; i < n ; i++ )
    {
        printf ("* Enter the term #%d : ",i+1);
        scanf ("%d",&x);
        printf ("\n");
        push (star,x);
    }
    printf ("* The number of elements in this stack is %d\n\n",stackCount(star));
    printf ("* The stack elements are : \n\n");
    StackDisplay(star);
    printf ("\n");
    int index;
    printf ("* Enter the index of the term you want to delete (LOOK from UP to DOWN) : ");
    scanf ("%d",&index);
    printf ("\n");
    stackDelete(star,index);
    printf ("* The stack elements are : \n\n");
    StackDisplay(star);
    printf ("\n");
    printf ("\n*** Thanks ! ***\n\n");
}
