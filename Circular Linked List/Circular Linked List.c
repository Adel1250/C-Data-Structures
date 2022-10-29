#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct Node*next;
} Node;
typedef struct
{
    Node*head;
    Node*tail;
} CircularLinkedList;
CircularLinkedList*  init()
{
    CircularLinkedList* l=malloc(sizeof(CircularLinkedList));
    l->head=NULL;
    l->tail=NULL;
    return l;
}
Node* newNode(int x)
{
    Node*m=malloc(sizeof(Node));
    m->data=x;
    m->next=NULL;
    return m;
}
void insertBegining(CircularLinkedList*list,int x)
{
    Node*n=newNode(x);
    if(list->head==NULL){
        n->next=n;
        list->head=list->tail=n;
    }
    else
    {
        n->next=list->head;
        list->tail->next=n;
        list->head=n;
    }
}
void PrintList(CircularLinkedList*list)
{
    if(list->head==NULL)
        return ;

    Node* temp=list->head;
    printf("%d",temp->data);
    temp=temp->next;
    while(temp!=list->head)
    {
        printf("%d",temp->data);
        temp=temp->data;
    }
}




