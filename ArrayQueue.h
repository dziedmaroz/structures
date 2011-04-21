#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue
{
    int size_;
    int* pointer_;
    int head_;
    int count_;
public:
    ArrayQueue(int size);
    ~ArrayQueue();
    void push (int item);
    int pop ();
    bool isEmpty ();
    bool isFull ();

};

#endif // ARRAYQUEUE_H
