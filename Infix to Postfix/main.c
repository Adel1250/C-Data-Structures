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

int priority (char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    case '^':
        return 2;
    case '(':
        return 3;
    }
    return -1;
}

void infixtoPostfix (char *infexp)
{

    Stack *s = initialize();
    char *token = strtok (infexp," ");
    Item a, b;

    while (token != NULL)
    {
        if (!((strlen(token) == 1) && ( token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '^' || token[0] == '(' || token[0] == ')')))
        {
            printf ("%s ",token);
        }

        else if (token[0] == ')')
        {
            while (!isEmpty(s) && top(s).chardata != '(')
            {
                printf("%c ",pop(s).chardata);
            }
            pop(s);
        }

        else if (isEmpty(s))
        {
            a.chardata = token[0];
            push (s,a);
        }

        else
        {
            while(!isEmpty(s) && priority(top(s).chardata) >= priority(token[0]) && top(s).chardata != '(')
                printf ("%c ",pop(s).chardata);

            b.chardata = token[0];
            push (s,b);

        }

        token = strtok (NULL, " ");
    }

    while(!isEmpty(s))
        printf("%c ",pop(s).chardata);

}

int main()
{
    char infexp[MAXSIZE];
    printf ("\n");
    printf ("** Infix to Postfix **\n\n");
    printf ("* Enter the Infix expression : ");
    gets (infexp);
    printf ("\n");
    printf ("* The Postfix expression is ");
    infixtoPostfix(infexp);
    printf ("\n\n");
    printf ("*** Thanks ! ***\n\n");
    return 0;
}
