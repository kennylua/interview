#include "stdafx.h"

#include "intro_algorithm.h"
#include <memory>

#define USE_BINARY_SEARCH 
void InsertSort( int *pIn, int nSize)
{
	int i,j,k;
	int nValue;
	for( i = 1 ; i <= nSize; i++ )
	{
		nValue = pIn[i];
		j = i - 1;
#ifdef USE_BINARY_SEARCH
		k = 0;
        while( k <= j )
		{
			if( nValue > pIn[ (k + j ) / 2 ])
			{
				k = ( k + j )/2 + 1;
			}
			else
			{
				j = ( k + j)/2 -1;
			}
		}
		j = i - 1;
		while( j >= k )
		{
 			pIn[ j + 1] = pIn[ j ];
			j--;
		}
		pIn[ k ] = nValue;
#else
		while( j >= 0 && pIn[j] > nValue )
		{
			pIn[ j + 1 ] = pIn[ j ];
			j--;
		}
		pIn[ j + 1 ] = nValue;
#endif
		
	}
}
#define swap( a, b )  (a)^=(b); (b)^=(a); (a)^=(b)
void SelectionSort( int *pIn, int size)
{
	int i,j;
	int min;
	int minIndex;
	for( i = 0; i < (size - 1); i++ )
	{
		min = pIn[i];
		minIndex = i;
		for( j = i; j < (size); j++ )
		{
			if( min > pIn[ j ] )
			{
				min = pIn[ j ];
				minIndex = j;
			}
		}
		if( pIn[i] != pIn[minIndex ] )
		{
			swap( pIn[i], pIn[minIndex] );
		}
	}
}

void DoMerge( int *pIn, int nP, int nQ, int nR)
{
	int nLeft = nQ - nP + 1;
	int nRight = nR - nQ;
    int i,j,k;

	int *pLeft = new int[nLeft];
	int *pRight = new int[nRight];
	int *pCur = &pIn[nP];

	memcpy(pLeft, &pIn[nP], sizeof(int)*nLeft);
	memcpy(pRight, &pIn[nQ + 1], sizeof(int)*nRight );
 
	j = 0;
	k = 0;
    while( j < nLeft && k < nRight )
	{
		if( pLeft[j] > pRight[k] )
		{
			*pCur = pRight[k];
			k++;
		}
		else
		{
			*pCur = pLeft[j];
			j++;
		}

		pCur++;
	}

	if( j >= nLeft )
	{
		memcpy(pCur, &pRight[k], (nRight - k )*sizeof(int));
	}

	if( k >= nRight )
	{
		memcpy(pCur, &pLeft[j], ( nLeft - j )*sizeof(int));
	}
}

void MergeSort( int *pIn, int idxBegin, int idxEnd )
{
	if( ( idxEnd - idxBegin ) < 2 )
	{
		if( pIn[idxEnd] < pIn[idxBegin] )
		{
			swap( pIn[idxEnd], pIn[idxBegin] );
		}
	}
	else
	{
		MergeSort( pIn, idxBegin, (idxBegin + idxEnd)/2);
		MergeSort( pIn, (idxBegin + idxEnd)/2 + 1, idxEnd);

		//Merge the sorted arrays
		DoMerge( pIn, idxBegin, (idxBegin + idxEnd)/2, idxEnd );
	}

}

int XtoThePwr( int x, int n)
{
	int val; 
	if( 1 == n )
	{
		return x;
	}
	else if ( 0 == n )
	{
		return 1;
	}

	if( x % 2 == 0 )
	{
		val = XtoThePwr( x, n / 2) ;
		return val * val;
	}
	else
	{
		val = XtoThePwr( x, (n - 1)/2 );
		return val * val * x;
	}
}

void QuickSort( int *pIn, int begin, int end )
{
	int nPivot;
	int nBegin = begin;
	int nEnd = end;
	if( ( nEnd - nBegin ) <= 1 )
	{
		if( pIn[ nEnd ] < pIn[ nBegin ])
		{
			swap( pIn[nEnd], pIn[nBegin]);
		}
		return;
	}

	nPivot = pIn[ nBegin ];
    while( nBegin < nEnd )
	{
		while( nPivot < pIn[ nEnd ] && nEnd > nBegin )
		{
			nEnd--;
		}

		if( nEnd > nBegin )
		{
			swap( pIn[ nBegin ], pIn[ nEnd ] );
		}

		while( nPivot >= pIn[ nBegin ] && nEnd > nBegin )
		{
			nBegin++;
		}
		if( nEnd > nBegin )
		{
			swap( pIn[ nEnd], pIn[nBegin]);
		}
	}
    
	if( nPivot >= pIn[nEnd] )
	{
		swap( nPivot, pIn[nEnd] );
	}
	if( nBegin >= 1)
	{
		QuickSort( pIn, 0, (nBegin - 1) );
	}
	if( nBegin + 1 < end )
	{
		QuickSort( pIn, nBegin + 1, end );
	}
}

void MaxHeap( heap *pInHeap, int idx )
{
	int nLargest = idx;
	int nLeft = LEFT( idx );
	int nRight = RIGHT( idx );

	if( nLeft < pInHeap->nSize && pInHeap->pIn [idx] < pInHeap->pIn[nLeft] )
	{
		nLargest = nLeft;
	}

	if( nRight < pInHeap->nSize  && pInHeap->pIn[nRight] > pInHeap->pIn [nLargest] )
	{
		nLargest = nRight;
	}

	if( idx != nLargest )
	{
		swap( pInHeap->pIn [ idx ], pInHeap->pIn [ nLargest ] );
        MaxHeap( pInHeap, nLargest );
	}
}

void BuildHeap( heap *pInHeap )
{
	int nSize = pInHeap->nSize / 2;
	while( nSize >= 0 )
	{
		MaxHeap( pInHeap, nSize );
		nSize--;
	}
}

void HeapSort( heap *pInHeap )
{
	int nIter = pInHeap->nSize ;
	while( nIter >= 2 )
	{
		swap( pInHeap->pIn [0], pInHeap->pIn[nIter-1]);
		pInHeap->nSize--;
        MaxHeap( pInHeap, 0 );
		nIter--;
	}
}

#define INC_STEP 5
void HeapIncreaseKey( heap *pInHeap, int nIdx )
{
	if( nIdx > pInHeap->nSize - 1 )
	{
		return;
	}
	
	(pInHeap->pIn [nIdx]) += INC_STEP;
	while( PARENT(nIdx) >=0 && pInHeap->pIn[nIdx] > pInHeap->pIn[ PARENT(nIdx) ] )
	{
		swap( pInHeap->pIn[nIdx], pInHeap->pIn[ PARENT(nIdx) ] );
		nIdx = PARENT( nIdx );
	}
}

void HeapInsert( heap *pInHeap, int nKey )
{

}

void CountingSort( int *pIn, int nSize, int nRange, int *pOut )
{
	int *pBuf = new int[nRange + 1];
	memset( pBuf, 0, sizeof(int) * (nRange + 1));
    int i;
	int nTotal = 0;
	int nTemp;
	for( i =0; i < nSize; i++ )
	{
		pBuf[ pIn[i]] = pBuf[ pIn[i]] + 1;
	}

	for( i = 0; i <= nRange; i++ )
	{
		nTemp = pBuf[i];
		pBuf[ i ] = nTotal;
		nTotal += nTemp;
	}

	for( i = 0; i < nSize; i++ )
	{
		pOut[ pBuf[ pIn[i] ] ] = pIn[i];
		pBuf[ pIn[i] ] = pBuf[ pIn[i] ] + 1;
	}
}

// Remove duplicate number
// Caller is responsible to free the memory by calling free()
void RemoveDuplicate( int *pIn, int nSize, int **pOut )
{
	int nBegin = 1, nEnd = 0;
	int nCurVal;
	if( NULL == pIn || 1 == nSize )
	{
		return;
	}

	nCurVal = pIn[ nEnd ];
	nEnd++;
	while( nEnd < nSize )
	{
		if( pIn[ nEnd ] != nCurVal )
		{
			pIn[ nBegin++ ] = pIn[ nEnd ];
            nCurVal = pIn[ nEnd ];
		}
		nEnd++;
	}

    *pOut = (int *)malloc( nBegin * sizeof( int ) );
	if( NULL != pOut )
	{
		memcpy( *pOut, pIn, sizeof(int)*(nBegin));
	}
}