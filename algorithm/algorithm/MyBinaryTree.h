#include <iostream>
#include <queue>
#include <stack>
#include <list>

using namespace std;

enum color_t {
	red_t,
	black_t
};

#define MAX(a, b) ((a>b)?a:b)
#define MIN(a, b) ((a>b)?b:a)
struct node 
{
	node *pLeft;
	node *pRight;
	node *pParent;
	int   nData;
	color_t color;
};

class Btree
{
private:
	node *pRoot;
	void Transplant( node *pTo, node *pFrom );

	// Exercise
	int MinDepth( node *pNode );
	int MaxDepth( node *pNode );
	node *AddNode( int *pData, int nUpper, int nLower );
public:
	Btree():pRoot(NULL){};

	void Insert( int nKey );
	void Remove( int nKey );
	bool Search( int nKey, node **pnode );

	// Traverse
	void TraverseTree();
	void InOrderTraverse( node *pNode );

	// Black-red tree
	void LeftRotate( node *pNode );
	void RightRotate( node *pNode );

	// Exercise
	bool IsBalancedTree();
    void CreateBalancedTree( int *pData, int nSize );
	void BFSTraverse();
	list<list<node *>> CreateLinkedLists( );
	node *FindSuccessor( node *pNode );
};

