#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void stackDtoB (int decimal)
{
    int x;
    Stack *s = initialize();
    while (decimal != 0)
    {
        x = decimal%2;
        push (s,x);
        decimal/=2;
    }
    while (!isEmpty(s))
    {
        printf ("%d",pop(s));
    }
}

int main()
{
    int decimal;
    printf ("\n");
    printf ("** Stack Decimal to Binary **\n\n");
    printf ("* Enter a decimal number : ");
    scanf ("%d",&decimal);
    printf ("\n");
    printf ("* The number in Binary is ");
    stackDtoB(decimal);
    printf ("\n\n*** Thanks ! ***\n\n");
}
