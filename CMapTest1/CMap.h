#pragma once

#ifndef CMAP_H
#define CMP_H

#include<vector>
#include"Edge.h"
#include"Node.h"
#define N 20
using namespace std;
typedef struct
{
	char vexs[N];//顶点数组  
	int arcs[N][N];//邻接矩阵  
}graph;
class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);
	void resetNode();
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);

	void printMartix();

	void deathFirstTraverse(int nodeIndex);//深度遍历 
	void breadthFirstTraverse(int nodeIndex);//广度遍历
	void breadthFirstTraverseImpl(vector<int>PreVec, int index);
	void primTree(int nodeIndex);
	void kruskalTree();

	int *m_pMatrix;//存邻接矩阵

private:
	int m_iCapacity;//图中最多顶点数
	int m_iNodeCount;//用来存图中已有顶点数
	Node *m_pNodeArray;//存顶点矩阵

	Edge *m_pEdge;

	bool getValueFromMatrix(int row, int col, int&val);
	int getMinEdge(vector<Edge>edgeVec);
	bool isInSet(vector<int>nodeSet, int target);
	void mergeNodeSet(vector<int>&nodeSetA, vector<int>&nodeSetB);
};
#endif
