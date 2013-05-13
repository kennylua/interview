#include "stdafx.h"
#include "MyList.h"

#include <iostream>
using namespace std;

void MyList::AppendToTail( int nIn )
{
	Node *pCurNode;
	Node *pNewNode;

	pNewNode = new Node;
	pNewNode->nData = nIn;
	pNewNode->pNext = NULL;
	mSize++;

	if( NULL == mProot )
	{
		mProot = pNewNode;
	}
	else
	{
		pCurNode = mProot;
		while( NULL != pCurNode->pNext )
		{
			pCurNode = pCurNode->pNext ;
		}
		pCurNode->pNext = pNewNode;
	}
}

bool MyList::DeleteNode( int nIn )
{
	Node *pDelNode = NULL;
	Node *pParentNode = NULL;
	bool bRet = false;

	pDelNode = mProot;
	// Delete head case
	if( mProot->nData == nIn )
	{
		mProot = mProot->pNext ;
	}
	else
	{
		while( pDelNode->nData != nIn && pDelNode != NULL )
		{
			pParentNode = pDelNode;
			pDelNode = pDelNode->pNext ;
		}

		if( pDelNode )
		{
			pParentNode->pNext = pDelNode->pNext ;
		}
	}

	if( NULL != pDelNode )
	{
		delete pDelNode;
		mSize--;
		bRet = true;
	}
	return bRet;
}

void MyList::PrintNode() 
{
	Node *pCurNode = mProot;
	while( pCurNode )
	{
		cout<<pCurNode->nData <<endl;
		pCurNode = pCurNode->pNext ;
	}
}

void MyList::DeleteDups() 
{
	Node *pCurNode = NULL;
	Node *pRunningNode = NULL;
	Node *pParentNode = NULL;


	if( NULL == mProot )
	{
		return;
	}

	pCurNode = mProot->pNext ;
    pParentNode = mProot;

	while( NULL != pCurNode )
	{
		pRunningNode = mProot;
		while( pRunningNode != pCurNode )
		{
			if( pRunningNode->nData == pCurNode->nData )
			{
				pParentNode->pNext = pCurNode->pNext ;
				break;
			}
			pRunningNode = pRunningNode->pNext ;
		}
		if( pCurNode != pRunningNode )
		{
			delete pCurNode;
			mSize--;
			pCurNode = pParentNode->pNext ;
		}
		else
		{
			pParentNode = pCurNode;
			pCurNode = pCurNode->pNext ;
		}
	}
}

Node *MyList::NthToLast(int nth) 
{
	int nIter = nth;
	Node *pCurNode;
	Node *pNthNode = mProot;
	if( NULL == mProot || nth < 1 )
	{
		return NULL;
	}

	pCurNode = mProot;
	while( nIter > 0 && NULL != pCurNode )
	{
		pCurNode = pCurNode->pNext ;
	}

	if( NULL == pCurNode )
	{
		return NULL;
	}

    while( pCurNode != NULL )
	{
		pCurNode = pCurNode->pNext ;
		pNthNode = pNthNode->pNext ;
	}
	return pNthNode;
}

Node *MyList::FindBegining() 
{
	Node *pFast = mProot;
	Node *pSlow = mProot;

	while( NULL != pFast->pNext )
	{
		pSlow = pSlow->pNext ;
		pFast = pFast->pNext ->pNext ;

		if( pSlow == pFast )
		{
			break;
		}
	}

	if( NULL == pFast->pNext )
	{
		return NULL;
	}

    pSlow = mProot;
	while( pSlow != pFast )
	{
		pSlow = pSlow->pNext ;
		pFast = pFast->pNext ;
	}

	return pSlow;
}