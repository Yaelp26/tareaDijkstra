#include "Graph.h"
#include <iostream>
#include <sstream>
using namespace std;

Graph::Graph(int size)
{
	this->size=size;
}

int Graph::getSize()
{
	return size;
}

void Graph :: setComponent(int value, int i, int j)
{
	
	matrixA[i][j] = value;
}

/*string Graph::to_string()
{
	string str1 = "";
	string s = "";
	
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{             
			s = static_cast < std :: ostringstream*> (&(std :: ostringstream() << matrixA [i][j])) -> str();
			str1 = str1 + s + "\t";
		}
		str1 = str1 + "\n";
	}
	return str1;
}*/
void Graph :: runs(int nodeI, int nodeJ)
{
	for(int i=0; i<size; i++)
	{
		if ((nodeI != nodeJ) && (matrixA[nodeI][i] == 1))
		{
			cout << "\nThe path of: " << nodeI << " to " << i << " ";
			runs(i, nodeJ);
		}
	}
}
void Graph :: instVisit()
{
	for (int i=0; i<size; i++)
	{
		visited[i] = false;
	}
}
void Graph :: dfs(int nodeI, int nodeJ)
{
	visited[nodeI] = true;
	for(int i=0; i<size; i++)
	{
		if(!visited[i])
		{
			if((nodeI != nodeJ) && matrixA[nodeI][i] == 1)
			{
				cout << "\nThe path of : " << nodeI << " to " << i << " ";
				dfs(i, nodeJ);
			}
		}
	}
}
void Graph :: deepFound(int nodeI, int nodeJ)
{
	instVisit();
	dfs(nodeI, nodeJ);
}
int Graph :: minValue(int value1, int value2)
{
	if (value1 <= value2)
		return value1;
	else
		return value2;
}

//graph and digraph methods
/*void Graph::readGraph()
{
	cout << "Enter the paths of the graph 1:yes\t0:no\n";
	for (int i =0; i <size; i ++)
	{
		for (int j = i ; j < size; j++)
		{
			cout << " Node " << (i +1) << " to node " << (j+1) << ":" ;
			cin >>  matrixA[i][j];
			matrixA[j][i] = matrixA [i][j];
		}
		cout << endl ;
	}
}

void Graph::showGraph()
{
	cout << " \nThe digraph is \n";
	for (int i=0; i < size; i++)
	{
		for (int j=i;j<size;j++)
		{
			cout << "Node " << (i+1)<< " to node " << (j+1)<< " and vice versa is :" << matrixA[i][j] << endl;
			cout << endl;
		}
	}
}*/

void Graph::readDigraph()
{
	cout << "Enter the paths of the Digraph 1:yes\t0:no\n";
	for (int i =0; i < size; i ++)
	{
		for (int j = 0 ; j < size; j++)
		{
			cout << " Node " << (i +1) << " to node " << (j+1) << ":" ;
			cin >>  matrixA[i][j];
		}
		cout << endl ;
	}
}
                         
void Graph::showDigraph()
{
		cout << " \nThe digraph is \n";
	for (int i=0; i < size; i++)
	{
		for (int j=0;j<size;j++)
		{
			cout << "Node " << (i+1)<< " to node " << (j+1)<< "  is :" << matrixA[i][j] << endl;
		}
		cout << endl;
	}
}
		                                                                                     	                                                                                    
//Dijkstra starts
void Graph :: dijkstra(int nodeI)
{
	int D[size], P[size];
	bool S[size];
	int min, w;
	for(int i=0; i<size; i++)
	{
		S[i] = false;
		P[i] = nodeI;
		D[i] = matrixA[nodeI][i];
	}
	S[nodeI] = true;
	for(int i=0; i<size; i++){
		min = infinite;
		for(int v=0; v<size; v++)
			if (!S[v])
				if (D[v] < min){
					min = D[v];
					w = v;
				}
		//Agrega w a s
		S[w] = true;
		//Para cada vertice v en v-s
		for(int v=0; v<size; v++)
			if(!S[v])
				if(D[w] +  + matrixA[w][v] < D[v]){
					D[v] = minValue(D[v], D[w] + matrixA[w][v]); 
					P[v] = w;
				}
	}
	Stack *paths = new Stack(size);
	int c;
	for (int i=0; i<size; i++){
		if(i != nodeI){
			int v = i;
			paths -> push(v);
			while (P[v] != nodeI){
				paths -> push(P[v]);
				v = P[v];
			}
			paths -> push(nodeI);
			cout << "\nPath of node " << (nodeI+1) << " to node " << (i+1) << ": ";
			c = paths->getTop();
			while(c >= 0) {
				cout << (c+1) << " ";
				c = paths->pop(); // You need to remove the top element after using it // Then get the next top element
			}
			cout << "\nWith minimun cost of: " << D[i];
		}
	}
}

//Dijkstra ends
