#include "Deque.h"
#include "StructExceptions.h"

Deque::Deque()
{
    head_=NULL;
    tail_=NULL;
}

Deque::Deque (Deque &orig)
{
    head_=new Node;
    Node* tmpOrig = orig.head_;
    Node* tmpThis = this->head_;

    tmpThis->item_=tmpOrig->item_;
    tmpThis->prev_=NULL;
    tmpThis->next_=new Node;
    tmpOrig=tmpOrig->next_;
    tmpThis->next_->prev_=tmpThis;
    tmpThis=tmpThis->next_;

    while (tmpOrig!=NULL)
    {
        tmpThis->item_=tmpOrig->item_;
        tmpThis->next_=new Node;
        tmpThis->next_->prev_=tmpThis;
        tmpThis=tmpThis->next_;
        tmpOrig=tmpOrig->next_;
    }
    tmpThis=tmpThis->prev_;
    delete tmpThis->next_;
    tmpThis->next_=NULL;
    tail_=tmpThis;
}

Deque::Deque (int val)
{
   this->head_ = new Node ;
   head_->item_=val;
   head_->next_=NULL;
   head_->prev_=NULL;
   tail_=head_;
}

Deque::insertHead (int item)
{
    Node* tmp = new Node;
    tmp->item_=item;
    tmp->next_=head_;
    tmp->prev_=NULL;
    head_=tmp;
}

Deque::insertTail (int item)
{
    Node* tmp = new Node;
    tmp->item_=item;
    tmp->prev_=tail_;
    tmp->next_=NULL;
    tail_=tmp;
}

int Deque::removeHead ()
{
    if (isEmpty()) throw StructExceptions ("Deque is empty!");

    Node* tmp = head_->next_;
    int tmpItem = head_->item_;

    delete head_;
    head_=tmp;
    return tmpItem;
}

int Deque::removeTail ()
{
    if (isEmpty()) throw StructExceptions ("Deque is empty!");

    Node* tmp = tail_->prev_;
    int tmpItem = tail_->item_;
    delete tail_;
    tail_=tmp;
    return tmpItem;
}

bool Deque::isEmpty ()
{
    return (head_==tail_ && head_==NULL);
}

