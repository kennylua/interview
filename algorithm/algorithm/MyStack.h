#ifndef _MY_STACK_H
#define _MY_STACK_H

#include "Node.h"
#include <vector>

using namespace std;

class MyStack
{
public:
	MyStack():mTop( NULL ), mSize( 0 ){};
	void Push( int nData );
	void Pop();
	Node *Top() { return mTop; } 
	void PrintStack();
	int GetSize(){ return mSize; }
	bool IsEmpty() { return ( 0 == mSize ); }
	void SortMyStack();
	int  mIdx;

private:
	int mSize;
	Node *mTop;
};

class MyQueue
{
private:
	Node *mFront, *mBack;
public:
	void Enqueue( int nData );
	void Dequeue();
	Node *Front(){ return mFront; }
	Node *Back() { return mBack; }
	MyQueue():mFront(NULL), mBack( NULL ){};
	void PrintQueue();

};

class SetofStacks
{
public:
	void Push( int nVal );
	void Pop();
	int  Top();

	enum { capacity = 50 };
private:
	vector<MyStack *> stacks;
};

class Queue2Stacks
{
private:
	MyStack stackpush;
    MyStack stackpop;

public:
	void Push( int nVal );
	void Pop();
	Node *Top();
};

// Hanoi tower
void RunHanoi( int nInitHeight );
void MoveDisk( MyStack *pFrom, MyStack *pUse, MyStack *pTo, int nSize );

#endif