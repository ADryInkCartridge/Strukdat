#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

int main ()
{
    while (1)
    {    
        int n,k,max=0,count=0,flag=0;
        cin >> n >> k;
        pair<int,int> jadwal[101];
        stack<int> s;
        if (n==0 && k==0)
        {
            return 0;
        }
        for (int i=0;i<n;i++)
        {
            cin >> jadwal[i].first >> jadwal[i].second;
            if (jadwal[i].second>max)
            {
                max=jadwal[i].second;
            }
            if (jadwal[i].first>max)
            {
                max=jadwal[i].first;
            }
            if(jadwal[i].first == jadwal[i].second)
            {
                flag=1;
            }
        }
    	sort (jadwal,jadwal+n);
    	for (int i=0;i<n;i++)
    	{
    		if (jadwal[i].first==jadwal[i+1].first)
    		{
    			flag=1;
			}
			if (jadwal[i].second==jadwal[i+1].second)
    		{
    			flag=1;
			}
		}
		int timec=0;
        for (int time=0;time<=max;time++)
        {
            if (!s.empty())
            {
                int maxtime=s.top();
                if (time==s.top())
                {
                   s.pop();
                   if (!s.empty() && maxtime>=s.top())
                   {
                   	flag=1;
				   }
                }
            }
            if (time==jadwal[timec].first)
            {
            	s.push(jadwal[timec].second);
            	timec++;
			}
            
            if (s.size() > k || flag==1)
            {
                printf("Gak Bisa Woi\n");
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            printf("Lancar Jaya\n");
        }
    }
}
