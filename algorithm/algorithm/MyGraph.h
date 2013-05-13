#ifndef _MY_GRAPH_
#define _MY_GRAPH_

#include <vector>
#include <list>
using namespace std;

struct ArcNode
{
	int nAdjVex;
	ArcNode *pNext;
	float nData;
};
enum color { white, gray, black };
struct VNode
{
	int nVdata;
	color c;
	ArcNode *pFirstNode;
};

class MyGraph
{
	vector< VNode *> vertices;
	int nNumOfNode;
	int nNumOFVetex;
public:
	MyGraph():nNumOfNode(0), nNumOFVetex(0){};
	void AddVNode( int nVal );
	void AddArc( int nToNode, int nFromNode, float fWeight );
	void CreateGraph();
	void CloneGraph();

	void BFS();
	void DFS();

	void Dijkstra();
};

#endif