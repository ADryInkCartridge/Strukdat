#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    int g;
    cin >> g;    
    for(int test = 0; test < g; test++)
	{
        int n,m,x;
        int total=0,count=0,temp=0,ai=0,bi=0;  
        cin >> n >> m >> x;
        int a[n],b[m];
        for(int i = 0; i <n; i++)
		{
           cin >> a[i];
        }
        for(int i =0; i <m; i++)
		{
           cin >> b[i];
        }
        while(ai<n && total+a[ai]<=x)
		{    
            total+=a[ai];
            ai++;
        }
        count=ai;        
        while(bi<m && ai>=0)
		{        
            total+=b[bi];             
            bi++;
            while(total>x && ai>0)
			{
                ai--;
                total-=a[ai];
            }
            if(total<=x && ai+bi>count)
            {
            	count=ai+bi;	
			}
        }
        cout<<count<<endl;
    } 
}
