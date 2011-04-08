#ifndef LIST_H
#define LIST_H

template <class T> class List
{
    struct node
    {
        T item_;
        node* next_;
    };

    node* head_;
public:
    List();	             /* конструктор */
    List(const List& lst);   // конструктор копирования
    List (const T* arr, int size);
    ~List();	             /* деструктор */
    void insert(const T& n);  /* включить элемент в список */
    T remove ();		       /* исключить элемент из списка */
    bool isEmpty();	       /* пустой список? */
};

#endif // LIST_H
