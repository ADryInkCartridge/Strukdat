#include <bits/stdc++.h>
using namespace std;
struct queuenter
{ 
    int vertex;     
    int s;  
}; 

int diceboi(int move[], int n) 
{ 
    bool *visited = new bool[n]; 
    for (int i = 0; i < n; i++) 
        visited[i] = false; 
  
    queue<queuenter> q; 
  
    visited[0] = true; 
    queuenter s = {0, 0};  
    q.push(s); 
    queuenter qe;
    while (!q.empty()) 
    { 
        qe = q.front(); 
        int v = qe.vertex;
        if (v == n-1) 
            break; 
  
        q.pop(); 
        for (int j=v+1; j<=(v+6) && j<n; ++j) 
        { 
            if (!visited[j]) 
            { 
                queuenter a; 
                a.s = (qe.s + 1); 
                visited[j] = true; 
                if (move[j] != -1) 
                    a.vertex = move[j]; 
                else
                    a.vertex = j; 
                q.push(a); 
            } 
        } 
    } 
    return qe.s; 
} 

int main ()
{
	int n;
	cin >> n;
	int board[n]; 
    for (int i = 0; i<n; i++) 
	{
		board[i] = -1; 	
	}
	int tc;
	cin >> tc;
	for (int test=0;test<tc;test++)
	{
		int c;
		cin >> c;
		for (int snek=0;snek<c;snek++)
		{
			int a,b;
			cin >> a >> b;
			board[a]=b;
		}
		int dice = diceboi(board,n);
		cout << dice << endl;
	}	
}
