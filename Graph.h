#ifndef GRAPH_H
#define GRAPH_H
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

class Graph
{
	private:
		int size;
		int matrixA[100][100];
		int visited[100];
		int infinite = 2000000;
		
	public:
		Graph(int size);
		int getSize();
		void setComponent(int, int, int);
		int getComponent(int, int);
		string to_string();
		void runs(int, int);
		void instVisit();
		void dfs(int, int);
		void deepFound(int, int);
		int minValue(int, int);
		void dijkstra(int);
		//metodos de grafo y digrafo
		void readGraph();
		void showGraph();
		void readDigraph();
		void showDigraph();
		
};

#endif
