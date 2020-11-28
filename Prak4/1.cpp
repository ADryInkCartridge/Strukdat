#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >graph[510];
int dist[510];
typedef pair <int, int> pii;

void dijkstra(int s, int out) {
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    set <int> seen;
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pii now = pq.top();
        pq.pop();
        if(seen.find(now.second) != seen.end()) continue;
        seen.insert(now.second);
        for(int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i].second;
            int cost = graph[now.second][i].first;
            
            if(now.first + cost < dist[next] || dist[next] == -1) {
                dist[next] = now.first + cost;
                pq.push({dist[next], next});
            }
        }
    }
    cout << dist[505] << endl;
    return;
}

int main ()
{
	int n,w,h;
	cin >> n >> w >> h;
	pair<char,int> pler;
	map<char,int> dis;
	vector<pair <int,int> > dismap[510];
	char in;
	int s;
	int count=0;
	for (int i=0;i<n;i++)
	{
		cin >> pler.first >> pler.second;
		dis.insert(pler);
	}
	for (int i=0;i<h;i++)
	{
		for (int j=0;j<w;j++)
		{
			cin >> in;
			if (in == 'Y')
			{
				dismap[i].push_back(make_pair(0,count));
				s = count;
				count++;
			}
			else
			{
				int time=dis[in];
				dismap[i].push_back(make_pair(time,count));
				count++;
			}
		}
	}
	dismap[505].push_back(make_pair(0,505));
	count=0;
	for (int i = 0 ; i < w ; i++)
    {
        for (int j = 0 ; j < h ; j++)
        {
            if (j > 0)
            {
            	graph[count].push_back(make_pair(dismap[i][j-1].first, dismap[i][j-1].second));
			}
            else
            {
            	graph[count].push_back(make_pair(dismap[505][0].first, dismap[505][0].second));
			}
            if (i > 0)
            {
            	graph[count].push_back(make_pair(dismap[i-1][j].first, dismap[i-1][j].second));
			}
            else
            {
            	graph[count].push_back(make_pair(dismap[505][0].first, dismap[505][0].second));
			}
            if (j < w-1)
        	{
        		graph[count].push_back(make_pair(dismap[i][j+1].first, dismap[i][j+1].second));
			}
            else
            {
            	graph[count].push_back(make_pair(dismap[505][0].first, dismap[505][0].second));

			}
            if (i < h-1)
            {
            	graph[count].push_back(make_pair(dismap[i+1][j].first, dismap[i+1][j].second));
			}
            else
            {
            	graph[count].push_back(make_pair(dismap[505][0].first, dismap[505][0].second));
			}
            count ++;
        }
    }
//    for (int i = 0 ; i < count ; i++)
//    {
//        for(int j=0; j<4;j++)
//        {
//        	printf("%d %d\n",graph[i][j].first,graph[i][j].second);
//		}
//		puts(" ");
//	}
    dijkstra(s,505);

    return 0;
}
