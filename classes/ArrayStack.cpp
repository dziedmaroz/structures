#include "ArrayStack.h"
#include "StructExceptions.h"
#include <iostream>
using namespace std;

template <class T> ArrayStack<T>::ArrayStack (int size)
{
    arr_= new T[size];
    size_ = size;
    top_=0;
}

template <class T> ArrayStack<T>::ArrayStack (T *arr, int arrSize, int stackSize, bool reverse)
{
    arr_ = new T [stackSize];
    size_=stackSize;
    top_ = arrSize;
    if (reverse)
    {
        for (int i=0;i<arrSize;i++)
            arr_[i]=arr[arrSize-i];
    }
    else
    {
        for (int i=0;i<arrSize;i++)
            arr_[i]=arr[i];
    }
}

template <class T> ArrayStack<T>::ArrayStack (ArrayStack &orig)
{
    arr_ = new T [orig.size_];
    size_=orig.size_;
    top_=orig.top_;

    for (int i=0;i<top_;i++)
        this->arr_[i]=orig.arr_[i];
}

template <class T> bool  ArrayStack<T>::isEmpty ()
{
    return top_==0?true:false;
}

template <class T> bool ArrayStack<T>::isFull ()
{
    return top_==size_?true:false;
}

template <class T> void ArrayStack<T>::push (T item)
{
    if (isFull ()) throw (StructExceptions("Stack is full!"));
    arr_[top_]=item;
    top_++;
}

template <class T> T ArrayStack<T>::pop ()
{
    if (isEmpty ()) throw (StructExceptions("Stack is empty!"));
    return arr_[top_--];
}

template <class T> T ArrayStack<T>::peek ()
{
    return arr_[top_];
}

template <class T> void ArrayStack<T>::print ()
{
    for (int i=0;i<top_;i++)
        cout<<arr_[i]<<" \t";
    cout<<"\n";
}

template <class T>  ArrayStack<T>::~ArrayStack ()
{
    delete [] arr_;
}
