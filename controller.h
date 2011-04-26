#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <typeinfo>
#include <stdio.h>
#include <cstring>
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "List.h"
#include "StudContainer.h"
// TYPE   type
// MKNEW  size
// LOAD   <filename> прочитать и добавить
// PRINT
// FPRINT <filename>
// SORT
// POP
// PRINTPOP
// RM <parameter>
// PUSH "type_string"

enum Keywords {TYPE,MKNEW, LOAD,PRINT, FPRINT, SORT, POP, PRINTPOP, RM, PUSH};
struct Action
{
	Keywords keyWrd;
	char textParam[100];
	int intParam;
	int lineNum;
};


void control (char* scriptfilename);
void dealStudContainer (const Action* actionList, int actSize);

#endif // CONTROLLER_H
