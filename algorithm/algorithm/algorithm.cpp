// algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "intro_algorithm.h"
#include "MyBinaryTree.h"
#include "MyList.h"
#include "MyStack.h"
#include "MyGraph.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	MyGraph g;
	g.CreateGraph();
	g.Dijkstra();
	system( "pause");
	return 0;
}

  