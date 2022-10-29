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

int stackPalindromeCheck (char *word)
{
    int i;
    Stack *s = initialize();
    for ( i = 0 ; i < strlen(word) ; i++ )
    {
        push(s,word[i]);
    }
    for ( i = 0 ; i < strlen(word) ; i++ )
    {
        if (word[i] != pop(s))
            return 0;
    }
    return 1;
}

int main()
{
    printf ("\n");
    printf ("** Stack Palindrome Check **\n\n");
    char word[20];
    printf ("* Enter a word : ");
    gets(word);
    printf ("\n");
    int check = stackPalindromeCheck(word);
    if (check == 0)
        printf ("** This word is X NOT PALINDROME X **\n\n");
    else printf ("** This word is PALINDROME **\n\n");
    printf ("*** Thanks ! ***\n\n");
}
