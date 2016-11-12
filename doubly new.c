#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}node;

node *head = NULL;
node *tail = NULL;

void PushFront(int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    if(head==NULL)
    {
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}
void PopFront()
{
    if(head==NULL) printf("No Element");
    if(head==tail)
    {
        head=NULL; tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
}
void PushBack(int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(tail==NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->prev = NULL;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail = newnode;
    }

}
void PopBack()
{
    if(tail==NULL) printf("No Element");
    if(head==tail)
    {
        head=NULL; tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
}
void Addafter(node *point,int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next= point->next;
    newnode->prev = point;
    point->next= newnode;
    if(newnode->next!=NULL) newnode->next->prev=newnode;
    if(tail==point) tail=newnode;
}
void Addbefore(node *point,int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = point->prev;
    newnode->next = point;
    point->prev = newnode;

    if(newnode->prev!=NULL) newnode->prev->next=newnode;
    if(head==point) head=newnode;
}
void Erase(int data)
{
    node *temp = head;
    node *temp2 = tail;
    node *current;

    if(temp->data==data)
    {
        PopFront();
        return;
    }
    if(temp2->data==data)
    {
        PopBack();
        return;
    }


    while(temp->next->data!=data) temp = temp->next;

    current = temp->next;
    temp->next= current->next;
    current->next->prev = temp;
    free(current);
}

void Print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }



}
int main()
{
    printf("..............Insert in the beginning...........\n\n");
    PushFront(6);
    PushFront(7);
    PushFront(8);
    PushFront(9);
    Print();
    printf("\t After delete: ");
    Erase(6);
    Print();
    printf("\n\n..............Insert in End...........\n\n");
    PushBack(5);
    PushBack(4);
    PushBack(3);
    PushBack(2);
    Print();
    printf("\t After delete: ");
    Erase(3);
    Print();
    Addafter(head->next->next,6);
    printf("\n");
    Print();
    Addbefore(tail,3);
    printf("\n");
    Print();
}
