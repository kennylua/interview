#include "stdafx.h"

#include "MyStack.h"
#include <iostream>

using namespace std;
/*
 * Stack implementation
 */
void MyStack::Push( int nData ) 
{
	Node *pNewNode = new Node;
	if( NULL != pNewNode )
	{
		pNewNode->nData = nData;
		pNewNode->pNext = mTop;

        mTop = pNewNode;

		mSize++;
	}
}

void MyStack::Pop()
{
	Node *pDelNode = NULL;
	if( NULL != mTop )
	{
		pDelNode = mTop;
		mTop = mTop->pNext ;

		delete pDelNode;
		mSize--;
	}
}

void MyStack::PrintStack() 
{
	Node *pIter = mTop;
	while( NULL != pIter )
	{
		cout<< pIter->nData <<endl;
		pIter = pIter->pNext ;
	}
}

void MyStack::SortMyStack()
{
	MyStack *pNewStack = new MyStack;
	if( NULL == pNewStack )
	{
		return;
	}

	while( !this->IsEmpty () )
	{
		Node nTop = *(this->Top());
		this->Pop ();
		while( !pNewStack->IsEmpty () && nTop.nData < pNewStack->Top ()->nData )
		{
			this->Push ( pNewStack->Top ()->nData) ;
			pNewStack->Pop ();
		}
		pNewStack->Push ( nTop.nData );
	}
}

/*
 * Queue implementation
 */

void MyQueue::Enqueue(int nData) 
{
	Node *pNewNode = new Node;
	if( NULL == pNewNode )
	{
		return;
	}

	pNewNode->nData = nData;
	pNewNode->pNext = NULL;

	if( !mFront )
	{
		mBack = pNewNode;
		mFront = mBack;
	}
	else
	{
		mBack->pNext = pNewNode;
		mBack = pNewNode;
	}
}

void MyQueue::Dequeue() 
{
	Node *pDelNode = NULL;
	if( mFront )
	{
		pDelNode = mFront;
		mFront = mFront->pNext ;

		delete pDelNode;
	}
}

void MyQueue::PrintQueue() 
{
	Node *pIter = mFront;
	while( NULL != pIter )
	{
		cout<<pIter->nData <<endl;
		pIter = pIter->pNext ;
	}
}

void SetofStacks::Push(int nVal) 
{
	int nLastStack = stacks.size();
    MyStack *pStack = NULL;
	if( 0 == nLastStack )
	{
        pStack = new MyStack();
		stacks.push_back ( pStack );
	}

	pStack = stacks.at(nLastStack - 1);
	if( capacity == pStack->GetSize () )
	{
		MyStack *pNewStack = new MyStack();
		pNewStack->Push ( nVal );
		stacks.push_back ( pNewStack );
	}
	else
	{
		pStack->Push ( nVal );
	}
}

void SetofStacks::Pop() 
{
	int nLastStackIdx = stacks.size();
	MyStack *pStack = stacks.at ( nLastStackIdx - 1);
	pStack->Pop ();

	if( pStack->GetSize() == 0 )
	{
		stacks.pop_back ();
	}
}

void Queue2Stacks::Push(int nVal) 
{
	stackpush.Push ( nVal );
}

void Queue2Stacks::Pop() 
{
	if( !stackpop.IsEmpty () )
	{
		stackpop.Pop ();
	}
	else
	{
		while( !stackpush.IsEmpty () )
		{
			int nTmp = stackpush.Top ()->nData ;
			stackpush.Pop ();
			stackpop.Push ( nTmp );
		}

		stackpop.Pop();
	}
}

Node *Queue2Stacks::Top() 
{
	if( !stackpop.IsEmpty () )
	{
		return stackpop.Top ();
	}
	else
	{
		while( !stackpush.IsEmpty () )
		{
			int nTmp = stackpush.Top ()->nData ;
			stackpush.Pop ();
			stackpop.Push ( nTmp );
		}

		return stackpop.Top();
	}
}

void RunHanoi( int nInitHeight )
{
	int nIter = 0;

	if( nInitHeight <= 0 )
	{
		return;
	}

	MyStack **pStacks = new MyStack*[3];
	for( nIter = 0; nIter < 3; nIter++ )
	{
		pStacks[ nIter ] = new MyStack;
		pStacks[ nIter ]->mIdx = nIter;
	}

	while( nInitHeight > 0 )
	{
		pStacks[ 0 ] ->Push ( nInitHeight );
		nInitHeight--;
	}

	MoveDisk( pStacks[0], pStacks[1], pStacks[2], pStacks[0]->GetSize () );
}

void MoveDisk( MyStack *pFrom, MyStack *pUse, MyStack *pTo, int nSize )
{
	int nNumOfDisk;
	if( nSize == 1 )
	{
		nNumOfDisk = pFrom->Top ()->nData;
		cout<<" Move " << nNumOfDisk << " From " << pFrom->mIdx << " TO " << pTo->mIdx << endl;
		pFrom->Pop ();
		pTo->Push ( nNumOfDisk );
	}
	else
	{
		MoveDisk( pFrom, pTo, pUse, ( nSize - 1 ) );
		MoveDisk( pFrom, pUse, pTo, 1);
		MoveDisk( pUse, pFrom, pTo, (nSize - 1) );
	}
}


