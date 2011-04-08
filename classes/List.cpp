#include "List.h"
#include <cstdlib>
#include <stdio.h>
#include <classes/StructExceptions.h>

template <class T> List<T>::List()
{
    head_=NULL;
    printf ("MWAHAHA!\n");
}

template <class T> List<T>::List (const List& orig)
{
    node* origPointer=orig.head_;
    this->head_ = new node;
    node* thisPointer = this->head_;

    while (origPointer!=NULL)
    {
        thisPointer->item_=origPointer->item_;
        thisPointer->next_=new node;
        origPointer=origPointer->next_;
    }
}

template <class T> List<T>::~List ()
{
    while (head_!=NULL)
    {
        node* tmp = head_;
        head_=head_->next_;
        delete tmp;
    }
}

template <class T> T List<T>::remove ()
{
    if (isEmpty ()) throw (StructExceptions("Trying to remove item from empty list!"));
    node* tmpPtr = head_;
    head_=head_->next_;
    T tmpVal = tmpPtr->item_;
    delete tmpPtr;
    return tmpVal;
}

template <class T> void List<T>::insert (const T& val)
{
    node* tmpPtr = new node;
    tmpPtr->next_=head_;
    head_=tmpPtr;
    head_->item_=val;
}

template <class T> bool List<T>::isEmpty ()
{
    return head_==NULL;
}
