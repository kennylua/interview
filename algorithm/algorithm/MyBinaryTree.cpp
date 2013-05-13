#include "stdafx.h"

#include "MyBinaryTree.h"


void Btree::Insert( int nKey )
{   
	node *pParent = NULL;
	node *pCurNode = pRoot;
	node *pNewNode = NULL;

	pNewNode = new node;
	if( NULL == pNewNode )
	{
		return;
	}
    pNewNode->nData = nKey;
	pNewNode->pLeft = NULL;
	pNewNode->pParent = NULL;
	pNewNode->pRight = NULL;


    while( NULL != pCurNode )
	{
		pParent = pCurNode;

		if( pCurNode->nData > nKey )
		{
			pCurNode = pCurNode->pLeft ;
		}
		else
		{
			pCurNode = pCurNode->pRight ;
		}
	}
    
	pNewNode->pParent = pParent;
	if( NULL == pParent )
	{
		pRoot = pNewNode;
	}
	else if ( pParent->nData > nKey )
	{
		pParent->pLeft = pNewNode;
	}
	else
	{
		pParent->pRight = pNewNode;
	}
};

void Btree::Transplant(node *pTo, node *pFrom )
{
	if( NULL == pTo->pParent )
	{
		pRoot = pFrom;
	}
	else if( pTo == pTo->pParent ->pLeft )
	{
		pTo->pParent ->pLeft = pFrom;
	}
	else
	{
		pTo->pParent ->pRight = pFrom;
	}

	if( NULL != pFrom )
	{
		pFrom->pParent = pTo->pParent ;
	}
}

void Btree::Remove(int nKey)
{
	node *pDelNode = NULL;
	if( !Search( nKey, &pDelNode ) )
	{
		return;
	}

	// 3 cases based on <<Introduction to algorithm>> p298
	if( NULL == pDelNode->pLeft )
	{
		Transplant( pDelNode, pDelNode->pRight ); 
	}
	else if ( NULL == pDelNode->pRight )
	{
		Transplant( pDelNode, pDelNode->pLeft );
	}
	else
	{
		// Both kids exist
		node *pSmallest = pDelNode->pRight ;
		while( pSmallest->pLeft )
		{
			pSmallest = pSmallest->pLeft ;
		}

		if( pSmallest->pParent != pDelNode )
		{
			Transplant( pSmallest, pSmallest->pRight );
			pSmallest->pRight = pDelNode->pRight ;
			pSmallest->pRight->pParent = pSmallest;
		}

		Transplant( pDelNode, pSmallest );
		pSmallest->pLeft = pDelNode->pLeft;
		pSmallest->pLeft->pParent  = pSmallest ;
	}

	delete (pDelNode);
}

bool Btree::Search(int nKey, node **pnode)
{
	node *pCurNode = pRoot;
	bool bRet = false;
	while( pCurNode != NULL )
	{
		if( pCurNode->nData == nKey )
		{
			break;
		}
		else if ( pCurNode->nData > nKey )
		{
			pCurNode = pCurNode->pLeft ;
		}
		else
		{
			pCurNode = pCurNode->pRight;
		}
	}

	if( NULL != pCurNode )
	{
		bRet = true;
        *pnode = pCurNode;
	}

	return bRet;
}

void Btree::TraverseTree ()
{
	InOrderTraverse( pRoot );
}

void Btree::InOrderTraverse( node *pNode )
{
	if( NULL != pNode )
	{
		InOrderTraverse( pNode->pLeft );
		cout<<pNode->nData <<" "<<endl;
		InOrderTraverse( pNode->pRight );
	}
}

int Btree::MinDepth( node *pNode )
{
	if( NULL == pNode )
	{
		return 0;
	}
	return 1 + MIN( MinDepth( pNode->pLeft ), MinDepth( pNode->pRight ) );
}

int Btree::MaxDepth( node *pNode )
{
	if( NULL == pNode )
	{
		return  0;
	}
	return 1 + MAX( MaxDepth( pNode->pLeft ), MaxDepth( pNode->pRight ) );
}

bool Btree::IsBalancedTree()
{
	return ( ( MaxDepth( pRoot ) - MinDepth( pRoot ) ) <= 1 );
}

void Btree::CreateBalancedTree(int *pData, int nSize)
{
	pRoot = AddNode( pData, 0, (nSize - 1) );
}

node *Btree::AddNode(int *pData, int nLower, int nUpper)
{
	node *pNewNode = NULL;

	if( nLower > nUpper )
	{
		return NULL;
	}

	int nMid = ( nLower + nUpper ) / 2;
	pNewNode = new node;
	pNewNode->nData = pData[ nMid ];
	pNewNode->pLeft = AddNode( pData, nLower, (nMid - 1) );
	pNewNode->pRight = AddNode( pData, (nMid + 1), nUpper );

	return pNewNode;
}

void Btree::BFSTraverse()
{
	queue<node *> q;
	node *pCurNode = NULL;
	if( NULL != pRoot )
	{
		q.push( pRoot );
	}

	while( !q.empty() )
	{
		pCurNode = q.front ();
		q.pop ();

		cout<<pCurNode->nData <<endl;

		if( NULL != pCurNode->pLeft )
		{
			q.push( pCurNode->pLeft );
		}

		if( NULL != pCurNode->pRight )
		{
			q.push( pCurNode->pRight );
		}
	}
}

list<list<node *>> Btree::CreateLinkedLists()
{
	list<list<node *>> result;
	list<node *> *level = new list<node *>;
	return result;
}

node *Btree::FindSuccessor(node *pNode)
{
	node *pRet = NULL;
	node *pParent = NULL;
	if( NULL != pNode || pNode->pParent == NULL )
	{
		pRet = pNode->pRight ;
		while( pRet->pLeft )
		{
			pRet = pRet->pLeft ;
		}
	}
	else
	{
		while( ( pParent = pNode->pParent ) != NULL )
		{
			if( pParent->pLeft == pNode )
			{
				pRet = pParent;
				break;
			}
			pNode = pParent;
		}
	}
	return pRet;
}

void Btree::LeftRotate( node *pNode )
{

}





