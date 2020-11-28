#include <bits/stdc++.h>
using namespace std;
int *visit;
class Graph 
{ 
	int v; 
	list<pair<int,int> > *adj; 
public: 
	Graph(int v)
	{
		this->v = v; 
		adj = new list<pair <int,int> >[v]; 
	}
	void edges(int s, int n, int w)
	{ 
		adj[s].push_back(make_pair(n, w)); 
	} 
	bool DLS(int v, int target, int limit, int weight)
	{
		visit[v] = weight;
		if (limit<1)
		{
			return false;
		}
		for (auto i : adj[v]) 
		{
		int next = i.first;
		//cout<< next << endl;
		int w= i.second+weight;
		if (w < visit[next])
			if (DLS(next, target, limit-1, w))
			{
				return true;
			}
		}
		return false;
	}
}; 

int main ()
{
	int e,v;
	cin >> v >> e;
	visit = (int*) malloc (v*sizeof(int));
	Graph g(v);
	for (int i=0;i<v;i++)
	{
		visit[i]=INT_MAX;
	}
	for(int i=0;i<e;i++)
	{
		int s,n,w;
		{
			cin >> s >> n >> w;
			g.edges(s,n,w);
		}	
	}
	int bts,start;
	cin>>start>>bts;
	for (int i=0;i<v;i++)
	{
		cout << i << " ";
		g.DLS(start,i,bts,0);
		if (visit[i] == INT_MAX)
		{
			cout << "INFINITY" << endl;
		}
		else
		{
			cout << visit[i] << endl;
		}
	}
}
