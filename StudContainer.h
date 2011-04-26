#ifndef STUDCONTAINER_H
#define STUDCONTAINER_H
#include <iostream>

using namespace std;
struct Student
{
	char name [10];
	int num;
	double grade;
};
class StudContainer 
{
	int size_;
	Student* studPointer_;
	int count_;
	int findByName (char* name);
	int cmpNames ( const void* a,const void* b);
public:
	StudContainer (int n);
	StudContainer (const StudContainer& orig);
	~StudContainer ();

	StudContainer&	operator= (StudContainer &orig);

	bool insert (Student& item);
	bool remove (char* name);
	void sortByName ();
	Student* getStud (char* name);	
	void print (ostream& stream=cout);
	int getSize ();
	int getCount ();
};

#endif
