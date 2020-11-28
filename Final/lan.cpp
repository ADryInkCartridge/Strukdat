#include <bits/stdc++.h>
using namespace std;
class server
{
	public :
	string id;
	int floor;
	vector <string> data;
};
class router
{
	public :
	int floor;
	vector <string> data;
};
int main()
{
	int n,m,count=0;
	cin >> n;
	server s[n];
	for (int i=0;i<n;i++)
	{
		cin >> s[i].id; 
		int dts;
		cin >> dts;
		for (int j=0;j<dts;j++)
		{
			cin >> s[i].data[j];
		}
		cin >> s[i].floor;
 	}
 	cin >> m;
 	router r[m];
 	for (int i=0;i<m;i++)
 	{
 		int dts;
 		cin >> dts;
 		for (int j=0;j<dts;j++)
		{
			cin >> r[i].data[j];
		}
		cin >> r[i].floor;
		map<int,set<string> > c;
		for (int test=0;test<n;test++)
		{
			set<string> temp;
			int flag=0,df=0;
			for (int a=0;a<s[test].data.size();a++)
			{
				for (int b=0;b<r[test].data.size();b++)
				{
					if (s[test].data[b]==r[test].data[b])
					{
						temp.insert(s[test].data[b]);
						df = abs(abs(s[test].floor-r[test].floor));
						flag=1;
					}
				}
			}
			if (flag==1)
			{
				c[df]=
				count++;
			}
		}
		c.sort();
		
	}
}
