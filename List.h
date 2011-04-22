#ifndef LIST_H
#define LIST_H

class List
{
    struct node
    {
        int item_;
        node* next_;
    };
    node* head_;
public:
    List ();
    List (List& orig);
    List (int* arr, int size);

    void insert (int val);
    int remove ();
    bool isEmpty ();

    ~List();
};
#endif