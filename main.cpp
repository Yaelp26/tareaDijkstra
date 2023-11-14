#include <iostream>
#include "Graph.h"
#include "Stack.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    int size;
    cout << "Enter the size of the graph: ";
    cin >> size;

    Graph graph(size);
    graph.readDigraph(); 
    graph.showDigraph();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int weight;
            cout << "Enter weight for Node " << (i + 1) << " to Node " << (j + 1) << ": ";
            cin >> weight;
            graph.setComponent(weight, i, j);
        }
        cout << endl;
    }

	cout << graph.to_string() << endl;
    graph.dijkstra(0); 

    return 0;
}