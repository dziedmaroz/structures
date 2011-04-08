//#include "classes/ArrayStack.h"
//#include "classes/ArrayStack.cpp"

#include "classes/List.h"
#include "classes/List.cpp"

#include <stdio.h>

int main(int argc, char *argv[])
{
//    ArrayStack<int> stack (5);
//    for (int i=0;i<5;i++)
//        stack.push (i);
//    stack.print ();

    List<int> lst ();
    for (int i=0;i<10;i++)
        lst.insert (i);

    for (int i=0;i<10;i++)
        printf ("%d\n",lst.remove ());
    return 0;
}
