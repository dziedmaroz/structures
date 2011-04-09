#include <iostream>
#include "List.h"
using namespace std;

List::List ()
{
    head_=NULL;
}

List::List (int *arr, int size)
{
    head_ = new node;
    node* tmpPtr=head_;

    for (int i=0;i<size;i++)
    {
        tmpPtr->item_=arr[i];
        tmpPtr->next_=new node;
        tmpPtr=tmpPtr->next_;
    }
    tmpPtr->next_=NULL;
}

List::List (List &orig)
{
    head_= new node;
    node* origPtr = orig.head_;
    node* thisPtr = this->head_;

    while (origPtr->next_!=NULL)
    {
        thisPtr->item_=origPtr->item_;
        thisPtr->next_=new node;
        origPtr=origPtr->next_;
        thisPtr=thisPtr->next_;
    }

    thisPtr->item_=origPtr->item_;
    thisPtr->next_=NULL;
}

bool List::isEmpty ()
{
    return head_==NULL;
}

void List::insert (int val)
{
    node* tmpNode = new node;
    tmpNode->item_=val;
    tmpNode->next_=head_;
    head_=tmpNode;
}

int List::remove ()
{
    int tmpVal = head_->item_;
    node* tmpNode=head_->next_;
    delete head_;
    head_=tmpNode;
    return tmpVal;
}

List::~List ()
{
    node* tmpNode = head_->next_;
    while (tmpNode!=NULL)
    {
        delete head_;
        head_=tmpNode;
        tmpNode=head_->next_;
    }
}
