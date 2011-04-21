#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

template <class T=int> class ArrayStack
{
    T* arr_;
    int size_;
    int top_;
public:

    ArrayStack (int size);
    ArrayStack (ArrayStack& orig);
    ArrayStack (T* arr, int arrSize, int stackSize, bool reverse=true);

    bool isFull ();
    bool isEmpty ();
    void push (T item);
    T pop ();
    T peek ();
    void print ();

    ~ArrayStack ();

};

#endif // ARRAYSTACK_H
