#ifndef _MY_LIST_
#define _MY_LIST_

#include "Node.h"

class MyList
{
public:
	Node *mProot;
	void AppendToTail( int nIn );
	bool DeleteNode( int nIn );
	void PrintNode();
	MyList():mProot(NULL), mSize(0){};
	int  mSize;

	// Careercup exercise
	void DeleteDups();
	Node *NthToLast( int nth );
    Node *FindBegining();

	// leetcode
	void CreateCyclicList( int *f_pData );

};

#endif