#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <typeinfo>
#include <stdio.h>
#include <cstring>
#include "ArrayStack.h"
#include "ArrayStack.cpp"
#include "ArrayQueue.h"
#include "List.h"
#include "StudContainer.h"

// MKNEW type[size=0]
// LOAD <filename> прочитать и добавить
// PRINT
// PRINTF <filename=stdout.txt>
// SORT
// POP
// PRINTPOP
// RM <parameter>
// PUSH "type_string"


template <class T> bool load (char* filename,T &obj)
{
    FILE* fin = fopen (filename);
    if (fin)
    {
        if(strcmp(typeid(obj).name (), "StudContainer"))
            {
                while (!feof(fin))
                {
                    Student tmp;
                    fscanf (fin,"%s %d %lf",&tmp.name,&tmp.num,&tmp.grade);
                    obj.insert (tmp);
                }
                fclose (fin);
                return true;
            }
         if(strcmp(typeid(obj).name (), "ArrayQueue"))
            {
                while (!feof(fin))
                {
                    int tmp;
                    fscanf (fin,"%d",&tmp);
                    obj.push (tmp);
                }
                fclose (fin);
                return true;
            }
        if(strcmp(typeid(obj).name (), "List"))
            {
                while (!feof(fin))
                {
                    int tmp;
                    fscanf (fin,"%d",&tmp);
                    obj.insert (tmp);
                }
                fclose (fin);
                return true;
            }

         if (strcmp(typeid(obj).name (),  "ArrayStack"))
            {
                while (!feof(fin))
                {
                    int tmp;
                    fscanf (fin,"%d",&tmp);
                    obj.push (tmp);
                }
                fclose (fin);
                return true;
            }

       printf ("LOAD_ERR:Can't find action for the type %s!\n",typeid(obj).name ());
       fclose (fin);
 }
}

void* mknew (char* typeName, int size=0)
{
     if(strcmp(typeName, "StudContainer"))
         return (void*) new StudContainer(size);
     if(strcmp(typeName, "ArrayQueue"))
         return (void*) new ArrayQueue (size);
     if(strcmp(typeName, "List"))
         return (void*) new List ();
     if (strcmp(typeName,  "ArrayStack"))
         return (void*) new ArrayStack(size);
     printf ("MKNEW_ERR:Can't find constructor for the type %s!\n",typeName);
     return NULL;
 }





#endif // CONTROLLER_H
