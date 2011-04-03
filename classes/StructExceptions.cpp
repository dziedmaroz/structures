#include "StructExceptions.h"
#include <cstring>
StructExceptions::StructExceptions(char *message)
{
    message_= new char [strlen(message)];
    strcpy (message_,message);
}

StructExceptions::~StructExceptions ()
{
    delete [] message_;
}
