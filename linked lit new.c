#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

}node;

node *head=NULL;
node *tail = NULL;
//node *newnode = (node*)malloc(sizeof(node));
//node *temp1 = (node*)malloc(sizeof(node));

void PushFront(int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    if(tail==NULL) tail = head;

}
void PopFront()
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode = head;
    if(head==NULL) printf("List is empty");
    head = newnode->next;
    if(head==NULL) tail=head;
}

void PushBack(int data)
{
    node *newnode = (node*)malloc(sizeof(node));

    newnode->data= data;
    newnode->next= NULL;

    if(tail==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}
void PopBack()
{
    node *temp1 = (node*)malloc(sizeof(node));
    if(head==NULL) printf("Empty List");
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        temp1 =head;
        while(temp1->next->next!=NULL)
        {
            temp1= temp1->next;
        }

        temp1->next=NULL;
        tail = temp1;
    }

}

void Addafter(node *point, int data)
{
    //node *newnode = (node*)malloc(sizeof(node));
    node *newnode1 = (node*)malloc(sizeof(node));
    newnode1->data=data;
    newnode1->next= point->next;
    point->next= newnode1;

    if(tail==point) tail =newnode1;

}
void Print()
{
    node *temp = head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;

    }



}
void Delete(int data)
{
    node *temp = head;
    node *current;

    if(temp->data==data)
    {
        PopFront();
        return;
    }

    while(temp->next->data!=data )
    {
        temp = temp->next;
    }

    current = temp->next;
    temp->next = current->next;
    free(current);


}

int main()
{

    PushBack(5);
    PushBack(6);
    PushBack(7);
    PushBack(8);
    Print();
    printf("\n");
    //PopFront();
    //print();
    //PopBack();
    //printf("\n");
    //print();
    Addafter(head->next,100);
    printf("\n");
    Print();
    Delete(8);
    printf("\n");
    Print();



}
