#include"CMap.h"
#include<iostream>
#include<vector>
using namespace std;

CMap::CMap(int capacity)
{
	if (capacity == 0)
	{
		cout << "顶点数不为0" << endl;

	}
	else
	{
		m_iCapacity = capacity;
		m_iNodeCount = 0;
		m_pNodeArray = new Node[m_iCapacity];
		m_pMatrix = new int[m_iCapacity * m_iCapacity];

		memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));
		//等价于下面这段
		/*for (int i = 1;i < m_iCapacity*m_iCapacity; i++)
		{
		m_pMatrix[i] = 0;
		}*/

		m_pEdge = new Edge[m_iCapacity - 1];
	}
}

CMap::~CMap()
{
	delete[]m_pNodeArray;
	delete[]m_pMatrix;
	delete[]m_pEdge;
}

bool CMap::addNode(Node *pNode)
{
	if (pNode == NULL)
	{
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	/*cout << "已存入第"<<m_iNodeCount<<"个" <<m_pNodeArray[m_iCapacity].m_cData << endl;*/
	m_iNodeCount++;
	return true;
}

void CMap::resetNode()
{
	for (int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row*m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row*m_iCapacity + col] = val;
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}

bool CMap::getValueFromMatrix(int row, int col, int&val)
{
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	val = m_pMatrix[row*m_iCapacity + col];
	return true;
}

void CMap::printMartix()
{
	for (int i = 0; i < m_iCapacity; i++)
	{
		for (int j = 0; j < m_iCapacity; j++)
		{
			cout << m_pMatrix[i*m_iCapacity + j] << "  ";
		}
		cout << endl;
	}
}
//深度优先遍历
void CMap::deathFirstTraverse(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << "  ";
	/*cout << "这是取出的第" << nodeIndex << "个" << m_pNodeArray[nodeIndex].m_cData << endl;*/
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	for (int i = 0; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, value);
		if (value == 1)
		{
			if (m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			else
			{
				deathFirstTraverse(i);
			}
		}
		else
		{
			continue;
		}
	}
}
//广度优先遍历
void CMap::breadthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << "  ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	cout << endl;

	vector<int>curVec;
	curVec.push_back(nodeIndex);
	int index = 1;
	breadthFirstTraverseImpl(curVec, index);
}

void CMap::breadthFirstTraverseImpl(vector<int>preVec, int index)
{
	int value = 0;
	vector<int>curVec;

	for (int j = 0; j < (int)preVec.size(); j++)
	{
		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(preVec[j], i, value);
			if (value != 0)
			{
				if (m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					/*for (int i = 0; i < index; i++)
					{
					cout << "|----";
					}*/
					cout << m_pNodeArray[i].m_cData << "  ";
					/*cout << endl;*/
					m_pNodeArray[i].m_bIsVisited = true;
					curVec.push_back(i);
				}
			}
		}
	}
	if (curVec.size() == 0)
	{
		return;
	}
	else
	{
		index++;
		cout << endl;
		breadthFirstTraverseImpl(curVec, index);
	}
}

//普利姆生成树
void CMap::primTree(int nodeIndex)
{
	int value = 0;
	int edgeCount = 0;
	vector<int>nodeVec;
	vector<Edge>edgeVec;

	cout << m_pNodeArray[nodeIndex].m_cData << endl;

	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	//停止时
	while (edgeCount < m_iCapacity - 1)
	{
		int temp = nodeVec.back();

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(temp, i, value);
			if (value != 0)
			{
				if (m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					Edge edge(temp, i, value);
					edgeVec.push_back(edge);
				}
			}
		}
		//从可选边集合中找到最小边
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;

		cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB << "  " << edgeVec[edgeIndex].m_iWeightValue << endl;

		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		edgeCount++;

		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;

		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}
int CMap::getMinEdge(vector<Edge>edgeVec)
{
	int minWeight = 0;
	int edgeIndex = 0;
	int i = 0;
	for (; i < edgeVec.size(); i++)
	{
		if (!edgeVec[i].m_bSelected)
		{
			minWeight = edgeVec[i].m_iWeightValue;
			edgeIndex = i;
			break;
		}
	}

	if (minWeight == 0)
	{
		return -1;
	}
	for (; i < edgeVec.size(); i++)
	{
		if (edgeVec[i].m_bSelected)
		{
			continue;
		}
		else
		{
			if (minWeight > edgeVec[i].m_iWeightValue)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}
	}
	return edgeIndex;
}


void CMap::kruskalTree()
{
	int value = 0;
	int edgeCount = 0;

	vector<vector<int>>nodeSets;

	vector<Edge>edgeVec;
	for (int i = 0; i < m_iCapacity; i++)
	{
		for (int k = i + 1; k < m_iCapacity; k++)
		{
			getValueFromMatrix(i, k, value);
			if (value != 0)
			{
				Edge edge(i, k, value);
				edgeVec.push_back(edge);
			}
		}
	}

	while (edgeCount<m_iCapacity - 1)
	{
		int minEdgeIndex = getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected = true;

		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

		bool nodeAInSet = false;
		bool nodeBInSet = false;

		int nodeAInSetLable = -1;
		int nodeBInSetLable = -1;

		for (int i = 0; i < (int)nodeSets.size(); i++)
		{
			nodeAInSet = isInSet(nodeSets[i], nodeAIndex);
			if (nodeAInSet)
			{
				nodeAInSetLable = i;
			}
		}

		for (int i = 0; i < (int)nodeSets.size(); i++)
		{
			nodeBInSet = isInSet(nodeSets[i], nodeBIndex);
			if (nodeAInSet)
			{
				nodeBInSetLable = i;
			}
		}

		//5.根据点所在集合的不同做出不同的处理
		if (nodeAInSetLable == -1 && nodeBInSetLable == -1)
		{
			vector<int>vec;
			vec.push_back(nodeAIndex);
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);
		}
		else if (nodeAInSetLable == -1 && nodeAInSetLable != -1)
		{
			nodeSets[nodeBInSetLable].push_back(nodeAIndex);
		}

		else if (nodeAInSetLable != -1 && nodeAInSetLable == -1)
		{
			nodeSets[nodeAInSetLable].push_back(nodeBIndex);
		}

		else if (nodeAInSetLable != -1 && nodeBInSetLable != -1 && nodeAInSetLable != nodeBInSetLable)
		{
			mergeNodeSet(nodeSets[nodeAInSetLable], nodeSets[nodeBInSetLable]);
			for (int k = 0; k < (int)nodeSets.size() - 1; k++)
			{
				nodeSets[k] = nodeSets[k + 1];
			}
		}

		else if (nodeAInSetLable != -1 && nodeBInSetLable != -1 && nodeAInSetLable != nodeBInSetLable)
		{
			continue;
		}

		m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
		edgeCount++;

		cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "--" << edgeVec[minEdgeIndex].m_iNodeIndexB << "  ";
		cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

bool CMap::isInSet(vector<int>nodeSet, int target)
{
	for (int i = 0; i < (int)nodeSet.size(); i++)
	{
		if (nodeSet[i] == target)
		{
			return true;
		}
	}
	return false;
}
void CMap::mergeNodeSet(vector<int>&nodeSetA, vector<int>&nodeSetB)
{
	for (int i = 0; i < (int)nodeSetB.size(); i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}