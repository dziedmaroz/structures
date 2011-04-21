#include "ArrayQueue.h"
#include "StructExceptions.h"
ArrayQueue::ArrayQueue(int size)
{
    size_=size;
    pointer_= new int [size];
    head_=0;
    count_=0;
}

ArrayQueue::~ArrayQueue ()
{
    delete [] pointer_;
}

bool ArrayQueue::isEmpty ()
{
    return count_;
}

bool ArrayQueue::isFull ()
{
    return !(count_<size_);
}

void ArrayQueue::push (int item)
{
    if (isFull ()) throw (StructExceptions("Queue is full!"));
    pointer_[(size_+count_)%size_]=item;
    count_++;
}

int ArrayQueue::pop ()
{
    if (isEmpty ()) throw (StructExceptions("Queue is empthy!"));
    int tmp = pointer_[head_];
    head_= (size_+head_+1)%size_;
    count_--;
    return tmp;
}


