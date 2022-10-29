#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100

typedef union
{
    float floatdata;
    char chardata;
} Item;

typedef struct
{
    Item items[MAXSIZE];
    int top;
} Stack;

Stack* initialize ()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = 0;
    return s;
}

void push (Stack *s, Item value)
{
    s->items[s->top] = value;
    s->top++;
}

Item pop (Stack *s)
{
    Item value;
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

Item top (Stack *s)
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

float evaluate (char x, float op1, float op2)
{
    if (x == '+')
        return (op1 + op2);
    if (x == '-')
        return (op1 - op2);
    if (x == '*')
        return (op1 * op2);
    if (x == '/')
        return (op1 / op2);
    if (x == '^')
        return (pow(op1,op2));
    return 0;
}

float evaluatePostfix (char *exp)
{
    Stack *s = initialize();
    float op1, op2, val;
    Item x, m;
    char *p = strtok(exp," ");
    while ( p != NULL )
    {
        if ((strlen(p) == 1) && ( p[0] == '+' || p[0] == '-' || p[0] == '*' || p[0] == '/' || p[0] == '^'))
        {
            op2 = pop(s).floatdata;
            op1 = pop(s).floatdata;
            val = evaluate (*p,op1,op2);
            x.floatdata = val;
            push(s,x);
        }
        else
        {
            float n = atof(p);
            m.floatdata = n;
            push (s,m);
        }
        p = strtok (NULL," ");
    }
    float k = pop(s).floatdata;
    return k;
}

int main()
{
    char exp[100];
    printf ("\n");
    printf ("** Postfix Expression Evaluation **\n\n");
    printf ("* Enter the Postfix expression : ");
    gets(exp);
    printf ("\n");
    float x = (float)evaluatePostfix(exp);
    printf ("* The expression's value is : %.2f\n\n",x);
    printf ("*** Thanks ! ***\n\n");
}
