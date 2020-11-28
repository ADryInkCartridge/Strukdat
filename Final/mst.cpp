#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int> > > e;
int n,m;
int mep[105][105],p[105];
int findr(int x)
{
  if(p[x]<0)
    {
        return x;
    }
  return p[x]=findr(p[x]);
}
long long leggo(vector<pair<int,int> >& ec)
{
  vector<int>hash;
  for(int i=0; i<ec.size(); i++)
    {
      hash.push_back(ec[i].first);
      hash.push_back(ec[i].second);
    }
  sort(hash.begin(),hash.end());
  hash.erase(unique(hash.begin(),hash.end()),hash.end());
  int n=hash.size();
  n--;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      mep[i][j]=0;
  for(int i=0; i<ec.size(); i++)
    {
      int u=lower_bound(hash.begin(),hash.end(),ec[i].first)-hash.begin();
      int v=lower_bound(hash.begin(),hash.end(),ec[i].second)-hash.begin();
      mep[u][u]++;
      mep[v][v]++;
      mep[u][v]--;
      mep[v][u]--;
    }
  long long ans=1LL;
  for(int i=0; i<n; i++)
    {
      for(int j=i+1; j<n; j++)
        {
          while(mep[j][i])
            {
              ans*=-1;
              long long int t=mep[i][i]/mep[j][i];
              for(int k=i; k<n; k++)
                {
                  mep[i][k]=(mep[i][k]-mep[j][k]*t)%31011;
                  mep[i][k]^=mep[j][k];
                  mep[j][k]^=mep[i][k];
                  mep[i][k]^=mep[j][k];
                }
            }
        }
      if(mep[i][i]==0)
        {
          return 0;
        }
      else ans=(ans*mep[i][i])%31011;
    }
  return (ans%31011+31011)%31011;
}
int main ()
{
    while(~scanf("%d %d",&n,&m))
    {
    	e.clear();
	    memset(p,-1,sizeof(p));
	    for (int i=0;i<m;i++)
	    {
	        int s,n,w;
	        cin >> s >> n >> w;
	        s--; n--;
	        e.push_back(make_pair(w,make_pair(s,n)));
	    }
	    long long ans=1LL;
	    sort(e.begin(),e.end());
	    int left,right =0;
	    while (right<e.size())
	    {
	        left=right++;
	        while(right<e.size() && e[right].first ==  e[left].first)
	        {
	            right++;
	        }
	        for(int i=left; i<right; i++)
	        {
	            int& u=e[i].second.first;
	            int& v=e[i].second.second;
	            //cout << "1111" << endl;
	            u=findr(u);
	            v=findr(v);
	        }
	        for (int i=left;i<right;i++)
	        {
	            int u=e[i].second.first;
	            int v=e[i].second.second;
	            u=findr(u);
	            v=findr(v);
	            if(u!=v)
	            p[u]=v;
	            //cout << "12121" << endl;
	        }
	        for(int i=0; i<n; i++)
	        {
	            if(p[i]<0)
	            {
	                vector<pair<int,int> >ec;
	                for(int j=left; j<right; j++)
	                {
	                    int u=e[j].second.first;
	                    int v=e[j].second.second;
	                    if(findr(u)==i && findr(v)==i)
	                    ec.push_back(make_pair(u,v));
	    				//cout << "a" << endl;
	                }
	                // cout << "a" << endl;
	                ans=(ans*leggo(ec))%31011;
	                //cout << ans << endl;
	            }
	        }
	    }
	    //cout << "a" << endl;
	    int count=0;
	    for(int i=0; i<n; i++)
	    {
	        if(p[i]<0)
	        {
	            count++;
	        }
	    }
	    if (count>1)
	    {
	        puts("0");
	        continue;
	    }
	    printf("%lld\n",(ans%31011+31011)%31011);
	}
}
