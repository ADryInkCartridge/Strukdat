#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int N,W,H,M,V;
vector <pii> matrix[505];
vector <pii> graph[505];
int dist[505];
void dijkstra(int s, int out);
int main ()
{
    char ch;
    cin >> N;
    cin >> W;
    cin >> H;
    V = N*N;
    map <char,int> m;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> ch;
        cin >> M;
        pii x = make_pair(ch,M);
        m.insert(x);
    }

    int count=0,out;
    int src;

    for (int i = 0 ; i < H ; i++)
    {
        for (int j = 0 ; j < W ; j++)
        {  
            cin >> ch;
            if (ch == 'Y')
            {
                matrix[i].push_back(make_pair(0,count));
                src=count;
                count++;
                continue; 
            }
            int weight = m[ch];
            matrix[i].push_back(make_pair(weight,count));
            
            count++;
        }
        out = count;
    }
    matrix[out].push_back(make_pair(0,count));
    count=0;
    for (int i = 0 ; i < W ; i++)
    {
        for (int j = 0 ; j < H ; j++)
        {
            if (j > 0)
                graph[count].push_back(make_pair(matrix[i][j-1].first, matrix[i][j-1].second));
            else
                graph[count].push_back(make_pair(matrix[out][0].first, matrix[out][0].second));

            if (i > 0)
                graph[count].push_back(make_pair(matrix[i-1][j].first, matrix[i-1][j].second));
            else
                graph[count].push_back(make_pair(matrix[out][0].first, matrix[out][0].second));

            if (j < W-1)
                graph[count].push_back(make_pair(matrix[i][j+1].first, matrix[i][j+1].second));
            else
                graph[count].push_back(make_pair(matrix[out][0].first, matrix[out][0].second));

            if (i < H-1)
                graph[count].push_back(make_pair(matrix[i+1][j].first, matrix[i+1][j].second));
            else
                graph[count].push_back(make_pair(matrix[out][0].first, matrix[out][0].second));

            count ++;
        }
    }
    dijkstra(src,out);

    return 0;
}

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
    cout << dist[out] << endl;
    return;
}
