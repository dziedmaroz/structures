#include "ArrayStack.h"
#include "ArrayStack.cpp"
#include "List.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    ArrayStack<int> stack (5);
    for (int i=0;i<5;i++)
        stack.push (i);
    stack.print ();

    int* arr = new int [5];
    for (int i=0;i<5;i++)
        arr[i]=i;
    List lst (arr,5);
    for (int i=0;i<10;i++)
        lst.insert (i);

    for (int i=0;i<10;i++)
        printf ("%d\n",lst.remove ());
    return 0;
}
