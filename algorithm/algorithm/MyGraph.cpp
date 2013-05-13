#include "stdafx.h"

#include "MyGraph.h"
#include <queue>
#include <iostream>
#include <stack>

/*********************************

  (9)<--(0)-->(1)--(2)--(4)
		|  /
	   (3)--(6)--(7)
		|    |
	   (5)  (8)
 ********************************/
struct ArcData
{
	int   nStart;
	int   nEnd;
	float fCost;
};
static ArcData arcs[10] = {{0,9, 5},{0,1,4},{0,3,10},{3,5,7},{3,6,21},{7,6,15},{6,8,3},{2,1,1},{2,4,14},{3,1,42}}; 

void MyGraph::AddVNode( int nVal )
{
	VNode *pNewNode = new VNode;
    
	pNewNode->pFirstNode = NULL;
	pNewNode->nVdata = nVal;
	pNewNode->c = white;

	vertices.push_back( pNewNode );

	return;
}

void MyGraph::AddArc(int nFromNode, int nToNode, float fWeight ) 
{
	int nIdx = vertices.size();
    ArcNode *pNewArc = NULL;
	ArcNode *pArcIter = NULL;

	if( nToNode >= nIdx || nFromNode >= nIdx )
	{
		return;
	}

	pNewArc = new ArcNode;
    pNewArc->nAdjVex = nToNode;
	pNewArc->pNext = NULL;
	pNewArc->nData = fWeight;

	VNode *pNode = vertices.at( nFromNode );
	pArcIter = pNode->pFirstNode ;
    if( NULL == pArcIter )
	{
		pNode->pFirstNode = pNewArc;
	}
	else
	{
		while( !pArcIter->pNext )
		{
			pArcIter = pArcIter->pNext ;
		}
		pArcIter->pNext = pNewArc;
	}
}

void MyGraph::CreateGraph()
{
	int i;
	for( i = 0; i <= 9; i++ )
	{
		AddVNode ( i );
	}

	for( i = 0; i < sizeof( arcs )/sizeof(arcs[0]); i++ )
	{
		AddArc ( arcs[i].nStart , arcs[i].nEnd, arcs[i].fCost );
	}
}

void MyGraph::BFS() 
{
	queue<VNode *> nodes;
	VNode *pCurNode = NULL;
	VNode *pAdjNode = NULL;
	ArcNode *pCurArc = NULL;
    
	if( vertices.size() <= 0 )
	{
		return;
	}

	nodes.push ( vertices.at (0));
	while( !nodes.empty () )
	{
		pCurNode = nodes.front ();
		nodes.pop();

		pCurArc = pCurNode->pFirstNode ;
		while( !pCurArc )
		{
			pAdjNode = vertices.at( pCurArc->nAdjVex );
			if( pAdjNode->c == white )
			{
				pAdjNode->c = gray;
				nodes.push ( pAdjNode );
			}
			pCurArc = pCurArc->pNext ;
		}
		pCurNode->c = black;
		cout<<pCurNode->nVdata <<endl;
	}
}

void MyGraph::DFS() 
{
	stack<VNode *> nodes;
	VNode *pCurNode = NULL;
	VNode *pAdjNode = NULL;
	ArcNode *pCurArc = NULL;

	if( vertices.size() <= 0 )
	{
		return;
	}

    nodes.push ( vertices.at(0) );
	while( !nodes.empty() )
	{
		pCurNode = nodes.top ();
		nodes.pop();

		pCurArc = pCurNode->pFirstNode ;
		while( pCurArc )
		{
			pAdjNode = vertices.at ( pCurArc->nAdjVex );
			if( pAdjNode->c == white )
			{
				pAdjNode->c = gray;
				nodes.push ( pAdjNode );
			}
			pCurArc = pAdjNode->pFirstNode ;
		}
        pCurNode->c = black;
		cout<<pCurNode->nVdata <<endl;
	}
}

void MyGraph::CloneGraph()
{
}

template <typename T>
inline int FindMin( T *pInData, int nSize )
{
	int nCurMin = 0;
	while( nSize > 0 )
	{
		if( pInData[ nSize - 1] < pInData[ nCurMin ] )
		{
			nCurMin = nSize; 
		}
		nSize--;
	}
	return nCurMin;
}

void MyGraph::Dijkstra()
{
	float                *pDistanceVec = NULL;
	unsigned int          nSize        = 0;
	const float           MAX_DIS      = 9999;
	vector<VNode *>       sNodes;
	vector<VNode *>       tNodes;
	int                   nIter        = 0;
	VNode                *pCurNode     = NULL;
	ArcNode              *pNextArcNode = NULL;
	int                   nNewMin      = 0;


	// Distance vector
	nSize = vertices.size();
	pDistanceVec = new float[ nSize ];
    memset( pDistanceVec, 9999, sizeof(float)*nSize );

	// Add first Node and update the distance table 
	sNodes.push_back( vertices.at(0) );
	pCurNode = vertices.at(0);
	pNextArcNode = pCurNode->pFirstNode;
	while( pNextArcNode )
	{
		pDistanceVec[ pNextArcNode->nAdjVex ] = pNextArcNode->nData;
		pNextArcNode = pNextArcNode->pNext;
	}
   
	while( sNodes.size() < nSize )
	{
		nNewMin = FindMin( pDistanceVec, nSize );
		pCurNode = vertices.at( nNewMin );
		sNodes.push_back( pCurNode );

		//update the distance
		pNextArcNode = pCurNode->pFirstNode;
		while( pNextArcNode )
		{
			if( pDistanceVec[ pNextArcNode->nAdjVex] > pNextArcNode->nData )
			{
				pDistanceVec[ pNextArcNode->nAdjVex] = pNextArcNode->nData;
			}
			pNextArcNode = pNextArcNode->pNext;
		}
	}
}