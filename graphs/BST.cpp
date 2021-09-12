// Program to print BFS traversal from a given source vertex. BFS(int s) traverses vertices reachable from s.
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V; // No. of vertices

	// Pointer to an array containing adjacency lists
	list<int> *adj;
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints BFS traversal from a given source s
	void BFS(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s){
	
    bool visited[V] = {false};

	visited[s] = true;
	queue<int> q;
    q.push(s);

	while(!q.empty()){
		// Dequeue a vertex from queue and print it
		s = q.front();
		cout << s << " ";
		q.pop();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i){
			if (!visited[*i]){
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

// Driver program to test methods of graph class
int main(){
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
