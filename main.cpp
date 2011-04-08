#include "classes/ArrayStack.h"
#include "classes/ArrayStack.cpp"


int main(int argc, char *argv[])
{
    ArrayStack<int> stack (5);
    for (int i=0;i<5;i++)
        stack.push (i);        
    stack.print ();
    return 0;
}
