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
	char vexs[N];//��������  
	int arcs[N][N];//�ڽӾ���  
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

	void deathFirstTraverse(int nodeIndex);//��ȱ��� 
	void breadthFirstTraverse(int nodeIndex);//��ȱ���
	void breadthFirstTraverseImpl(vector<int>PreVec, int index);
	void primTree(int nodeIndex);
	void kruskalTree();

	int *m_pMatrix;//���ڽӾ���

private:
	int m_iCapacity;//ͼ����ඥ����
	int m_iNodeCount;//������ͼ�����ж�����
	Node *m_pNodeArray;//�涥�����

	Edge *m_pEdge;

	bool getValueFromMatrix(int row, int col, int&val);
	int getMinEdge(vector<Edge>edgeVec);
	bool isInSet(vector<int>nodeSet, int target);
	void mergeNodeSet(vector<int>&nodeSetA, vector<int>&nodeSetB);
};
#endif
