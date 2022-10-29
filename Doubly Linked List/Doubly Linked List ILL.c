#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node*prev;
    struct Node*next;
} Node;

typedef struct
{
    Node*head;
    Node*tail;
} DoublyLinkedList;

DoublyLinkedList*  init()
{
    DoublyLinkedList* l=malloc(sizeof(DoublyLinkedList));
    l->head=NULL;
    l->tail=NULL;
    return l;
}

Node* newNode(int x)
{
    Node*m=malloc(sizeof(Node));
    m->data=x;
    m->next=NULL;
    m->prev=NULL;
    return m;
}

DoublyLinkedList* mergetwoLists(DoublyLinkedList * list1,DoublyLinkedList* list2)
{
    DoublyLinkedList* result=init();

    Node* p=list1->head;
    Node* q=list2->head;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data<q->data)
        {
            insertEnd(result,p->data);
            p=p->next;
        }
        else
        {
            insertEnd(result,q->data);
            q=q->next;
        }
    }
    // in case p still has some values

    while(p!=NULL)
    {
        insertEnd(result,p->data);
        p=p->next;
    }
    // in case q still has some values

    while(q!=NULL)
    {
        insertEnd(result,q->data);
        q=q->next;
    }
    return result;
}

DoublyLinkedList* intersection(DoublyLinkedList * list1,DoublyLinkedList* list2)
{
    DoublyLinkedList* result=init();

    Node* p=list1->head;
    Node* q=list2->head;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data==q->data)
        {
            insertEnd(result,p->data);
            p=p->next;
            q=q->next;
        }
        else if (p->data<q->data)
        {
            p=p->next;
        }
        else
        {
            q=q->next;
        }
    }

    return result;
}

DoublyLinkedList* unionL(DoublyLinkedList * list1,DoublyLinkedList* list2)
{
    DoublyLinkedList* result=init();

    Node* p=list1->head;
    Node* q=list2->head;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data==q->data)
        {
            insertEnd(result,p->data);
            p=p->next;
            q=q->next;
        }
        else if (p->data<q->data)
        {
            insertEnd(result,p->data);
            p=p->next;
        }
        else
        {
            insertEnd(result,q->data);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insertEnd(result,p->data);
        p=p->next;
    }
    // in case q still has some values

    while(q!=NULL)
    {
        insertEnd(result,q->data);
        q=q->next;
    }

    return result;
}

void insertBegin(DoublyLinkedList* list,int x)
{
    Node * n =newNode(x);
    if(list->head==NULL)
        list->head=list->tail=n;
    else
    {
        n->next=list->head;
        list->head->prev=n;
        list->head=n;
    }
}

void insertEnd(DoublyLinkedList *list,int x)
{
    Node * n =newNode(x);
    if(list->head==NULL)
        list->head=list->tail=n;
    else
    {
        list->tail->next=n;
        n->prev=list->tail;
        list->tail=n;
    }
}

void insertatPosK(DoublyLinkedList *list,int x,int k)
{
    Node*n=newNode(x);
    Node*m;
    Node *z=list->head;
    int i;
    // get z
    for(i=1; i<k; i++)
        z=z->next;
    m=z->prev;

    // m with n
    n->prev=m;
    m->next=n;

    // n with z
    n->next=z;
    z->prev=n;
}

void printListFor(DoublyLinkedList* list)
{
    Node * temp;
    for(temp=list->head; temp!=NULL; temp=temp->next)
        printf("%d ",temp->data);
    printf("\n");

}

void printList(DoublyLinkedList* list)
{
    Node * temp=list->head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void deleteBegin(DoublyLinkedList* list)
{
    //make sure that list is not empty
    if(list->head!=NULL)
    {
        Node*temp=list->head;
        list->head=list->head->next;
        free(temp);
        if(list->head==NULL)
            list->tail=NULL;
    }
}

void deleteEnd(DoublyLinkedList* list)
{
//make sure that list is not empty
    if(list->head!=NULL)
    {
        Node* temp=list->tail;
        list->tail=list->tail->prev;
        free(temp);
        if(list->tail==NULL)//only one node
            list->head=NULL;
    }
}

void printReversed(DoublyLinkedList* list)
{
    Node * temp=list->tail;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->prev;
    }
}

void reverseListInPlace(DoublyLinkedList*list)
{
    Node* temp=list->head;
    while(temp!=NULL)
    {
        Node*z=temp->prev;
        temp->prev=temp->next;
        temp->next=z;

        temp=temp->prev;
    }
    // swap head with tail
    Node*m=list->head;
    list->head=list->tail;
    list->tail=m;
}

void destroyLinkedList(DoublyLinkedList*list)
{
    while(list->head!=NULL)
    {
        Node* temp=list->head;
        list->head=list->head->next;
        free(temp);
    }
    list->tail=NULL;
}

int main()
{
//    DoublyLinkedList*list1=init();
//    insertEnd(list1,1);
//    insertEnd(list1,7);
//    insertEnd(list1,9);
//    printf("List1:\n");
//    printList(list1);
//    DoublyLinkedList*list2=init();
//    insertEnd(list2,2);
//    insertEnd(list2,4);
//    insertEnd(list2,8);
//    printf("List2:\n");
//    printList(list2);
//
//    DoublyLinkedList*result;
//    result=mergetwoLists(list1,list2);
//    printf("List3:\n");
//    printList(result);

    DoublyLinkedList*listx=init();
    insertEnd(listx,1);
    insertEnd(listx,7);
    insertEnd(listx,8);
    insertEnd(listx,9);
    insertEnd(listx,10);
    printf("List x:\n");
    printList(listx);
    DoublyLinkedList*listy=init();
//    insertEnd(listy,3);
//    insertEnd(listy,9);
//    insertEnd(listy,10);
    printf("List y:\n");
    printList(listy);

    DoublyLinkedList*inter;
    inter=intersection(listx,listy);
    printf("List inter:\n");
    printList(inter);

    return 0;
}
