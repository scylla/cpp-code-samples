#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>
#include <stack>

using namespace std;

class Graph {

	public:
		int V;
		list<int> *adj;
	public:
		Graph(int V);
		void addEdge(int v, int w);
};

Graph::Graph(int V) {
	this->V = V;
	this->adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].emplace_back(w);
}

void DFS(const Graph& g, int V) {

	vector<bool> visited(V, false);
	stack<int> dfs_stack;
	dfs_stack.push(0);

	while(!dfs_stack.empty()) {
		int top = dfs_stack.top();
		dfs_stack.pop();
		cout << top << endl;
		visited[top] = true;
		for(list<int>::iterator i = g.adj[top].begin(); i != g.adj[top].end(); ++i) {
			if(!visited[*i])
				dfs_stack.push(*i);
		}
	} 

}

int main() {

	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    DFS(g, 4);
	return 0;

}