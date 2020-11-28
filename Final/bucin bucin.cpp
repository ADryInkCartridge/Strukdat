#include <bits/stdc++.h>
using namespace std;

class Graph 
{ 
    int V; 
    vector< pair<int,int > > *adj; 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[], vector< pair < int, int> > bridge[]); 
public: 
    Graph(int V); // Constructor 
    void addEdge(int u, int v, long long w); 
    void bridging(vector< pair < int, int> > bridge[]); 
    void shortestPath(int src, vector< pair < int, int> > bridge[], long long dist[]); 
}; 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new vector< pair < int, int> >[V]; 
} 

void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[], vector< pair < int, int> > bridge[]) 
{ 
    static int time = 0; 
 
    visited[u] = true; 
 
    disc[u] = low[u] = ++time; 
 
    vector< pair < int, int> >::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = i->first;
        long long w = i->second;
 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent, bridge); 
 
            low[u] = min(low[u], low[v]); 
 
            if (low[v] > disc[u]) 
            {
                bridge[u].push_back(make_pair(v,w));
                bridge[v].push_back(make_pair(u,w));
            }
        } 
 
        else if (v != parent[u]) 
            low[u] = min(low[u], disc[v]); 
    } 
} 
void Graph::addEdge(int s, int n, long long w) 
{ 
    //cout << s << n << w << endl;
    adj[s].push_back(make_pair(n, w)); 
    adj[n].push_back(make_pair(s, w));
} 
    void Graph::bridging (vector< pair < int, int> > bridge[])
    {
        bool visited[V];
        int disc[V];
        int low[V];
        int parent[V];
 
        for (int i=0;i<V;i++) 
        { 
            parent[i] = -1; 
            visited[i] = false; 
        } 
        for (int i=0;i<V;i++) 
            if (!visited[i]) 
                bridgeUtil(i, visited, disc, low, parent, bridge); 
    }
    void Graph::shortestPath(int src, vector< pair < int, int> > bridge[], long long dist[]) 
{ 
     priority_queue< int, vector <int> , greater<int> > pq; 
 
    for (int i = 0 ; i < V ; i++)
        dist[i] = -1 ;
 
    pq.push(src); 
    dist[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top(); 
        pq.pop(); 
 
        vector< pair < int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        {  
            int v = (*i).first; 
            long long weight = (*i).second; 
            if (dist[v] > dist[u] + weight ||  dist[v] == -1) 
            { 
                pair < int, int> target = make_pair(v, weight);
                if (find(bridge[u].begin(), bridge[u].end(), target) == bridge[u].end())
                    dist[v] = dist[u];
                else  
                    dist[v] = dist[u] + weight; 
                pq.push(v); 
            } 
        } 
    } 
} 



int main ()
{
    int V,E;
    cin >> V >> E;
    cout << "a" << endl;
    Graph g(V);
    vector< pair < int, int> > bridge[V];
    for (int i=0;i<E;i++)
    {
        int s,n;
        long long w;
        cin >> s >> n >> w;
        g.addEdge( s-1, n-1, w);
        cout << "a" << endl;
    }
    g.bridging(bridge);
    cout << "a" << endl;
    long long dist[V][V];
    for(int i=0;i<V;i++)
    {
        //cout << "a" << endl;
        g.shortestPath(i, bridge, dist[i]);
    }
    int tc;
    cin >> tc;
    for (int i=0;i<tc;i++)
    {
        int s,t;
        cin >> s >> t;
        cout << dist[s-1][t-1] << endl;
    }
}
