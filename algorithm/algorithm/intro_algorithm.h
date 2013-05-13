#include <iostream>

using namespace std;

void InsertSort( int *pIn, int nSize);
void SelectionSort( int *pIn, int size);
void MergeSort( int *pIn, int idxBegin, int idxEnd );
void DoMerge( int *pIn, int nP, int nQ, int nR);
int XtoThePwr( int x, int n);
void QuickSort( int *pIn, int nBegin, int nEnd);

#define HEAP_SIZE 20
#define LEFT( i )  ( ( i << 1 )+ 1 )
#define RIGHT( i ) ( ( i << 1 )+ 2 )
#define PARENT( i ) ( (( i + 1) >> 1) - 1 )

struct heap
{
	int pIn[ HEAP_SIZE ];
	int nSize;
};

void MaxHeap( heap *pInHeap, int idx );
void BuildHeap( heap *pInHeap );
void HeapSort( heap *pInHeap );
void HeapInsert( heap *pInHeap, int nKey );
void HeapIncreaseKey( heap *pInHeap, int nIdx );
void CountingSort( int *pIn, int nSize, int nRange, int *pOut );
void RemoveDuplicate( int *pIn, int nSize, int **pOut );
