#pragma once


#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;
class Node
{
public:
	Node(char data = 0);
	char m_cData;
	/*Node(string data = 0);
	string m_cData;*/
	bool m_bIsVisited;
};
#endif // !NODE_H
