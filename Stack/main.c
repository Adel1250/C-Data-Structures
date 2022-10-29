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
    s -> top = 0;
    return s;
}

void push (Stack *s, int value)
{
    s -> items[s->top] = value;
    s -> top++;
}

int pop (Stack *s)
{
    int value;
    s -> top--;
    value = s -> items[s -> top];
    return value;
}

int isEmpty (Stack *s)
{
    if (s -> top == 0)
    {
        return 1;
    }
    else
        return 0;
}

int top (Stack *s)
{
    return s -> items[s -> top - 1];
}

int isFull (Stack *s)
{
    if (s -> top == MAXSIZE)
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
    while (!isEmpty(s))
    {
        x = pop(s);
        printf ("* %d\n",x);
        push (copy,x);
    }
    while (!isEmpty(copy))
    {
        push(s,pop(copy));
    }
}

int main()
{
    int n, i, x;
    printf ("\n");
    printf ("** The Stack **\n\n");
    printf ("* Enter the number of elements to be added in the stack: ");
    scanf ("%d",&n);
    printf ("\n");

    Stack* trial = initialize();

    for (i = 0 ; i < n ; i++)
    {
        printf ("* Enter the term #%d : ",i+1);
        scanf ("%d",&x);
        printf ("\n");
        push (trial, x);
    }
    printf ("* The stack elements are : \n\n");
    StackDisplay(trial);
    printf ("\n*** Thanks ! ***\n\n");
}
