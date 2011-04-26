#ifndef DEQUE_H
#define DEQUE_H

class Deque
{
    struct Node
    {
        int item_;
        Node* next_;
        Node* prev_;
    };

    Node* head_;
    Node* tail_;

public:
    Deque ();
    Deque (int val);
    Deque (Deque &orig);

    ~Deque ();

    bool insertHead (int item);
    bool insertTail (int item);

    int removeHead ();
    int removeTail ();

    bool isEmpty ();
};

#endif // DEQUE_H
