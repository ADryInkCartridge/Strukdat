#include <bits/stdc++.h> 
#define NIL -1 
using namespace std; 
int dist=0;
class Graph 
{ 
    int v;   
    list<pair<int,int> > *adj; 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]); 
public: 
    Graph(int v);   
    void addEdge(int s,int n, int w);   
    void bridge();    // prints all bridges 
}; 
  
Graph::Graph(int v) 
{ 
    this->v = v; 
	adj = new list<pair <int,int> >[v]; 
} 
  
void Graph::addEdge(int s,int n, int w) 
{ 
    adj[s].push_back(make_pair(n, w)); 
    adj[n].push_back(make_pair(s, w)); 
} 
  
// A recursive function that finds and prints bridges using 
// DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[]) 
{ 
    static int time = 0; 
    visited[u] = true; 
    disc[u] = low[u] = ++time; 
    for (auto i : adj[u]) 
    { 
        int v = i.first;  
        if (!visited[v]) 
        {
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent); 
            low[u]  = min(low[u], low[v]); 
            if (low[v] > disc[u]) 
            {
            	continue;
			}
			else
			{
				i.second=0;
			}
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void Graph::bridge() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[v]; 
    int *disc = new int[v]; 
    int *low = new int[v]; 
    int *parent = new int[v]; 
  
    // Initialize parent and visited arrays 
    for (int i = 0; i < v; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < v; i++) 
        if (visited[i] == false) 
            bridgeUtil(i, visited, disc, low, parent); 
}
bool DLS(int v, int target, int weight)
	{
		visit[v] = weight;
		for (auto i : adj[v]) 
		{
		int next = i.first;
		int dist= i.second+weight;
		if (weight < visited[next])
			if (DLS(next, target, weight))
			{
				return true;
			}
		}
		return false;
	}
  
// Driver program to test above function 
int main ()
{
	int e,v;
	cin >> v >> e;
	Graph g(v);
	for(int i=0;i<e;i++)
	{
		int s,n,w;
		{
			cin >> s >> n >> w;
			g.addEdge(s,n,w);
		}	
	}
	g.bridge();
	
	
}
