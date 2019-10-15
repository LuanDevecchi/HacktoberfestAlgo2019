#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
	unordered_map<T, list<T> > adjList;

public:
	void addEdge(T u, T v, bool bidir = true ) {
		adjList[u].push_back(v);
		if( bidir ) adjList[v].push_back(u);
	}

	void topologicalSort() { 
		queue<T> q;
		unordered_map<T, int> indegree;
		unordered_map<T, bool> visited; 

		// initialize visited
		for( auto vertex: adjList ) {
			T node = vertex.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		// initialize indegree
		for( auto vertex: adjList ) {
			T u = vertex.first;
			for( T v: adjList[u] ) {
				indegree[v]++;
			}
		}

		// initialize queue, enqueue all the vertex having indegree 0
		for( auto vertex: adjList ) {
			T node = vertex.first;
			if( indegree[node] == 0 ) q.push( node );
		}

		// kahn's algorithm
		while( !q.empty() ) {
			T node = q.front();
			q.pop();
			cout << node << "->";
			for( T neighbour: adjList[node] ) {
				indegree[neighbour]--;
				if( indegree[neighbour] == 0 ) {
					q.push(neighbour);
				}
			}
		}
	}

};
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

// directed acyclic graph ( DAG ) 
Graph<int> g;
g.addEdge(0, 2, false);
g.addEdge(1, 2, false);
g.addEdge(1, 4, false);
g.addEdge(2, 3, false);
g.addEdge(2, 4, false);
g.addEdge(3, 5, false);
g.addEdge(4, 5, false);

g.topologicalSort();
return 0;
}