#include <bits/stdc++.h>
using namespace std;

list <int> table[1000];
int hnum=997;
int main ()
{
	cout << "Hash Table" << endl << "Scanning Query" << endl;
	while (1)
	{
		cout << "(1) Insert (2) Find (3) Delete (4) Show All (0) Exit" << endl;
		int query;
		cin >> query;
		if (query==1)
		{
			int in;
			cin >> in;
			int key=in % hnum;
			table[key].push_back(in);
		}
		if (query==2)
		{
			int in;
			cin >> in;
			int count=0;
			int key=in % hnum;
			list<int>::iterator it;
			it=table[key].begin();
			while (*it!=in && it!=table[key].end())
			{
				it++;
				count ++;
			}
			if (*it==in)
			{
				cout << in << " Found on key : " << key << " on index number " << count << endl;
				cout << table[key].size()<<endl;
			}
			if (it==table[key].end())
			{
				cout << in << " not found :(" << endl;
			}
		}
		if (query==3)
		{
			int in;
			cin >> in;
			int key=in % hnum;
			list<int>::iterator it;
			it=table[key].begin();
			while (*it!=in && it!=table[key].end())
			{
				it++;
			}
			if(it==table[key].end())
			{
				cout << in <<  " Not Found" << endl;
			}
			else
			table[key].erase(it);
		}
		if (query==4)
		{
			for (int i=0;i<1000;i++)
			{
				list<int>::iterator it2;
				if (!table[i].empty())
				{
					it2=table[i].begin();
					while (it2!=table[i].end())
					{
						if (it2==table[i].begin())
						{
							cout << *it2;
						}
						else
						cout << " --> " << *it2;
						
						it2++;
					}
					cout << endl;
				}
			}
		}
		if (query==0)
		{
			return 0;
		}
	}	
}
