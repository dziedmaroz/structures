#include "StudContainer.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
StudContainer::StudContainer (int n)
{
	size_=n;
	studPointer_=new Student[size_];
	int count_=0;
}

StudContainer::StudContainer(const StudContainer &orig)
{
	size_= orig.size_;
	count_=orig.count_;
	studPointer_=new Student [size_];

	for (int i=0;i<count_;i++)
	{
		studPointer_[i]=orig.studPointer_[i];
	}
}

StudContainer::~StudContainer ()
{
	delete [] studPointer_;
}

bool StudContainer::insert (Student &item)
{
	if (count_!=size_)
	{
		studPointer_[count_++]=item;
		return true;
	}
	return false;
}

bool StudContainer::remove (char* name)
{
	if (findByName (name)==-1) return false;
	if (count_!=0)
	{
		for (int i=findByName(name);i<count_;i++)
		{
			studPointer_[i]=studPointer_[i+1];
		}
		count_--;
		return true;
	}
	return false;
}
int StudContainer::getSize ()
{
	return size_;
}
int StudContainer::getCount ()
{
	return count_;
}

Student* StudContainer::getStud (char* name)
{
	if (findByName (name)==-1) return NULL;
	Student* tmp = new Student;
	*tmp = studPointer_[findByName(name)];
	return tmp;
}

void StudContainer::print (ostream &stream)
{
	for (int i=0;i<count_;i++)
		stream<<studPointer_[i].name<<"\t"<<studPointer_[i].num<<"\t"<<studPointer_[i].grade<<"\n";
}

int StudContainer::findByName (char* name)
{
    for (int i=0;i<count_;i++)
    {
        bool isMatch=true;
        for (int j=0;j<strlen(name);j++)
            if (studPointer_[i].name[j]!=name[j])
            {
                isMatch=false;
                break;
            }
        if (isMatch) return i;
    }

    return -1;
}



void StudContainer::sortByName ()
{
    struct
    {
        int cmpNames (const void* x, const void* y)
        {
            int i=0;
            Student* a=(Student*)x;
            Student* b=(Student*)y;
            while (strlen(a->name)==strlen(b->name) && i<strlen(a->name) && a->name[i]==b->name[i++]);
            return a->name[i]-b->name[i];
        };
    } cmp;
    qsort (studPointer_,sizeof(Student),count_,cmpNames);
}
