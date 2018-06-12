#include<iostream>
#include<stdio.h>  
#include<stdlib.h>
#include"CMap.h"
using namespace std;

void TopoSort_matrix(graph g)
{
	int row[N] = { 0 };//按照列来设置标志，为1表示已经输出（不再考虑），为0表示未输出。  
	int v = 1;//标志符，1表示已经输出（不再考虑），为0表示未输出，赋给row数组  
	int i, j, k, t, m;
	for (k = 0; k<N; k++)
	{
		for (j = 0; j<N; j++)
		{
			if (row[j] == 0)//活动j还未输出  
			{
				t = 1;//标识符  
				for (i = 0; i<N; i++)
					if (g.arcs[i][j] == 1)//当前活动有入度（活动i必须在活动j之前）  
					{
						t = 0;
						break;
					}
				if (t == 1)//活动j没有入度  
				{
					m = j;
					break;
				}
			}
		}
		if (j != N)
		{
			row[m] = v;
			printf("%c", g.vexs[m]);
			for (i = 0; i<N; i++)
				g.arcs[m][i] = 0;//将已经输出的活动所到达的下个活动的入度置为0  
			v++;
		}
		else
			break;
	}
	if (v - 1<N)//当row中不是所有的元素都被赋予新值v时，说明有环存在  
		printf("\n该有向图有环存在！");

}



int main()
{
	//int capacity = 0;
	//cout << "请输入顶点数(默认先最多40个吧)" << endl;
	//cin >> capacity;
	//CMap *pMap = new CMap(capacity);

	CMap *pMap = new CMap(20);


	//for (int i = 0; i < capacity; i++)
	//{
	//	string name;
	//	
	//	cout << "请输入第"<< i+1 <<"个顶点名称" << endl;
	//	cin >> name;
	//	/*Node *m_pNodeArray[i] = new Node(name);*/
	//	switch (i)
	//	{
	//	case 1: {Node * pNodeA = new Node(name); pMap->addNode(pNodeA); break; }
	//	case 2: {Node * pNodeB = new Node(name); pMap->addNode(pNodeB); break; }
	//	case 3: {Node * pNodeC = new Node(name); pMap->addNode(pNodeC); break; }
	//	case 4:{Node * pNodeD = new Node(name); pMap->addNode(pNodeD); break; }
	//	case 5: {Node * pNodeE = new Node(name); pMap->addNode(pNodeE); break; }
	//	case 6: {Node * pNodeF = new Node(name); pMap->addNode(pNodeF); break; }
	//	case 7: {Node * pNodeG = new Node(name); pMap->addNode(pNodeG); break; }
	//	case 8: {Node * pNodeH = new Node(name); pMap->addNode(pNodeH); break; }
	//	case 9: {Node * pNodeI = new Node(name); pMap->addNode(pNodeI); break; }
	//	case 10: {Node * pNodeJ = new Node(name); pMap->addNode(pNodeJ); break; }
	//	
	//	case 11: {Node * pNodeK = new Node(name); pMap->addNode(pNodeK); break; }
	//	case 12: {Node * pNodeL = new Node(name); pMap->addNode(pNodeL); break; }
	//	case 13: {Node * pNodeM = new Node(name); pMap->addNode(pNodeM); break; }
	//	case 14: {Node * pNodeN = new Node(name); pMap->addNode(pNodeN); break; }
	//	case 15: {Node * pNodeO = new Node(name); pMap->addNode(pNodeO); break; }
	//	case 16: {Node * pNodeP = new Node(name); pMap->addNode(pNodeP); break; }
	//	case 17: {Node * pNodeQ = new Node(name); pMap->addNode(pNodeQ); break; }
	//	case 18: {Node * pNodeR = new Node(name); pMap->addNode(pNodeR); break; }
	//	case 19: {Node * pNodeS = new Node(name); pMap->addNode(pNodeS); break; }
	//	case 20: {Node * pNodeT = new Node(name); pMap->addNode(pNodeT); break; }

	//	/*case 21:{Node * pNodeU = new Node(name); pMap->addNode(pNodeU); break; }
	//	case 22:{Node * pNodeV = new Node(name); pMap->addNode(pNodeV); break; }
	//	case 23:{Node * pNodeW = new Node(name); pMap->addNode(pNodeW); break; }
	//	case 24:{Node * pNodeX = new Node(name); pMap->addNode(pNodeX); break; }
	//	case 25:{Node * pNodeY = new Node(name); pMap->addNode(pNodeY); break; }
	//	case 26:{Node * pNodeZ = new Node(name); pMap->addNode(pNodeZ); break; }
	//	case 27:{Node * pNodeA1 = new Node(name); pMap->addNode(pNodeA1); break; }
	//	case 28:{Node * pNodeB1 = new Node(name); pMap->addNode(pNodeB1); break; }
	//	case 29:{Node * pNodeC1 = new Node(name); pMap->addNode(pNodeC1); break; }
	//	case 30:{Node * pNodeD1 = new Node(name); pMap->addNode(pNodeD1); break; }

	//	case 31:{Node * pNodeE1 = new Node(name); pMap->addNode(pNodeE1); break; }
	//	case 32:{Node * pNodeF1 = new Node(name); pMap->addNode(pNodeF1); break; }
	//	case 33:{Node * pNodeG1 = new Node(name); pMap->addNode(pNodeG1); break; }
	//	case 34:{Node * pNodeH1 = new Node(name); pMap->addNode(pNodeH1); break; }
	//	case 35:{Node * pNodeI1 = new Node(name); pMap->addNode(pNodeI1); break; }
	//	case 36:{Node * pNodeJ1 = new Node(name); pMap->addNode(pNodeJ1); break; }
	//	case 37:{Node * pNodeK1 = new Node(name); pMap->addNode(pNodeK1); break; }
	//	case 38:{Node * pNodeL1 = new Node(name); pMap->addNode(pNodeL1); break; }
	//	case 39:{Node * pNodeM1 = new Node(name); pMap->addNode(pNodeM1); break; }
	//	case 40:{Node * pNodeN1 = new Node(name); pMap->addNode(pNodeN1); break; }
	//	*/
	//	default:
	//		break;
	//	}
	//}

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');

	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');
	Node *pNodeI = new Node('I');
	Node *pNodeJ = new Node('J');

	Node *pNodeK = new Node('K');
	Node *pNodeL = new Node('L');
	Node *pNodeM = new Node('M');
	Node *pNodeN = new Node('N');
	Node *pNodeO = new Node('O');

	Node *pNodeP = new Node('P');
	Node *pNodeQ = new Node('Q');
	Node *pNodeR = new Node('R');
	Node *pNodeS = new Node('S');
	Node *pNodeT = new Node('T');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);

	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);
	pMap->addNode(pNodeI);
	pMap->addNode(pNodeJ);

	pMap->addNode(pNodeK);
	pMap->addNode(pNodeL);
	pMap->addNode(pNodeM);
	pMap->addNode(pNodeN);
	pMap->addNode(pNodeO);

	pMap->addNode(pNodeP);
	pMap->addNode(pNodeQ);
	pMap->addNode(pNodeR);
	pMap->addNode(pNodeS);
	pMap->addNode(pNodeT);

	delete pNodeA;
	delete pNodeB;
	delete pNodeC;
	delete pNodeD;
	delete pNodeE;

	delete pNodeF;
	delete pNodeG;
	delete pNodeH;
	delete pNodeI;
	delete pNodeJ;

	delete pNodeK;
	delete pNodeL;
	delete pNodeM;
	delete pNodeN;
	delete pNodeO;

	delete pNodeP;
	delete pNodeQ;
	delete pNodeR;
	delete pNodeS;
	delete pNodeT;

	/*int capacity_line = 0;
	cout << "请输入弧数" << endl;
	cin >> capacity_line;

	for (int k = 0; k < capacity_line; k++)
	{
	int a = -1;
	int b = -1;
	int value = 0;
	cout << "请输入第" << k + 1 << "个弧尾索引" << endl;
	cin >> a;
	cout << "请输入第" << k + 1 << "个弧头索引" << endl;
	cin >> b;
	cout << "请输入第" << k + 1 << "个弧头的权值" << endl;
	cin >> value;
	pMap->setValueToMatrixForUndirectedGraph(a, b, value);
	}*/
	//这里是输入弧的代码

	//   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
	//1    1 1 1                 1  
	//2      1 
	//3          1   1 1 
	//4          1
	//5              1
	//6                1      1                 1 
	//7                                               1
	//8                                            1
	//9                    1  1  1
	//10                         1
	//11                               1  1
	//12                            1
	//13                               1
	//14                                  1
	//15                                     1
	//16                                        1
	//17                                           1
	//18                                              1
	//19                                                 1
	//20
	/*这里是邻接矩阵*/

	pMap->setValueToMatrixForDirectedGraph(0, 1);
	pMap->setValueToMatrixForDirectedGraph(0, 2);
	pMap->setValueToMatrixForDirectedGraph(0, 3);
	pMap->setValueToMatrixForDirectedGraph(0, 11);
	pMap->setValueToMatrixForDirectedGraph(1, 2);

	pMap->setValueToMatrixForDirectedGraph(2, 4);
	pMap->setValueToMatrixForDirectedGraph(2, 6);
	pMap->setValueToMatrixForDirectedGraph(2, 7);
	pMap->setValueToMatrixForDirectedGraph(3, 4);
	pMap->setValueToMatrixForDirectedGraph(4, 6);

	pMap->setValueToMatrixForDirectedGraph(5, 7);
	pMap->setValueToMatrixForDirectedGraph(5, 10);
	pMap->setValueToMatrixForDirectedGraph(5, 16);
	pMap->setValueToMatrixForDirectedGraph(6, 18);
	pMap->setValueToMatrixForDirectedGraph(7, 17);

	pMap->setValueToMatrixForDirectedGraph(8, 9);
	pMap->setValueToMatrixForDirectedGraph(8, 10);
	pMap->setValueToMatrixForDirectedGraph(8, 11);
	pMap->setValueToMatrixForDirectedGraph(9, 11);
	pMap->setValueToMatrixForDirectedGraph(10, 13);

	pMap->setValueToMatrixForDirectedGraph(10, 14);
	pMap->setValueToMatrixForDirectedGraph(11, 12);
	pMap->setValueToMatrixForDirectedGraph(12, 13);
	pMap->setValueToMatrixForDirectedGraph(13, 14);
	pMap->setValueToMatrixForDirectedGraph(14, 15);

	pMap->setValueToMatrixForDirectedGraph(15, 16);
	pMap->setValueToMatrixForDirectedGraph(16, 17);
	pMap->setValueToMatrixForDirectedGraph(17, 18);
	pMap->setValueToMatrixForDirectedGraph(18, 19);
	/*这里是直接实现弧的代码*/

	/*
	A
	/  |  \
	B- -F- -E
	\  / \  /
	C- - -D

	A B C D E F
	0 1 2 3 4 5

	A-B 6 A-E 5 A-F 1
	B-C 3 B-F 2
	C-F 8 C-D 7
	D-F 4 D-E 2
	E-F 9

	A
	6/ 1| 5\
	B-2-F-9-E
	3\ 8/4\ 2/
	C- 7 -D

	*/
	/*这里是最小樹的图形例子及相关数据*/

	//pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);
	//pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);
	//pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);
	//pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);
	//pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);

	//pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);
	//pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);
	//pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);
	//pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);
	//pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);
	/*这里是最小樹的弧的相关代码直接赋值*/

	pMap->printMartix();
	cout << endl;
	/*这里是打印矩阵*/


	pMap->resetNode();

	/*int deepIndex = -1;
	cout << "请输入起点节点的索引" << endl;
	cin >> deepIndex;*/

	//pMap->deathFirstTraverse(0);
	//pMap->resetNode();
	//cout << endl;
	//cout << endl;

	///*int breadthIndex = -1;
	//cout << "请输入起点节点的索引" << endl;
	//cin >> breadthIndex;*/
	//
	//pMap->breadthFirstTraverse(0);
	//pMap->resetNode();

	//pMap->primTree(0);
	//pMap->kruskalTree();
	graph g;

	char vertex[N] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T' };//初始化  
	for (int i = 0; i<N; i++)
	{
		g.vexs[i] = vertex[i];
		for (int j = 0; j<N; j++)
			g.arcs[i][j] = pMap->m_pMatrix[i*N + j];
	}//对图初始化
	TopoSort_matrix(g);
	printf("\n");
	/*pMap->printMartix();
	cout << endl;
	*/
	system("pause");
	return 0;
}