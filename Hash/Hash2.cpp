#include <bits/stdc++.h>
using namespace std;

list <int> table[1000];
int hnum=997;
int main ()
{
	ifstream inFile;
	inFile.open("hash.in.txt");
	int n;
	inFile >> n ;
	for (int i=0;i<n;i++)
	{
		int in;
		inFile >> in;
		int key=in % hnum;
		table[key].push_back(in);
	}
	inFile.close();
	cout << "Hash Table" << endl << "Scanning Query" << endl;
	while (1)
	{
		cout << "(1) Insert (2) Find (3) Delete (4) Show All (5) Testing, Warning Laptop will somewhat lag (0) Exit" << endl;
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
			clock_t time; 
			time = clock();
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
			}
			if (it==table[key].end())
			{
				cout << in << " not found :(" << endl;
			}
			time = clock()-time; 
			double tle = ((double) time)/ CLOCKS_PER_SEC ;
			printf("Search done in %lf seconds\n",tle);
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
		if (query==5)
		{	
				clock_t time2; 
				time2 = clock();
				double total=0;
				int hundcount=0;
			for (int testing=0;testing<1000;testing++)
			{
				clock_t time; 
				time = clock();
				if (testing % 100 == 0)
				{
					cout<< "Searching from " << testing*1000+1 << " to " << testing*1000+100000<<endl;
				}
				for (int i=testing*1000+1;i<=testing*1000+1000;i++)
				{
					int in;
					in=i;
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
					//	cout << in << " Found on key : " << key << " on index number " << count << endl;
					}
					if (it==table[key].end())
					{
					//	cout << in << " not found :(" << endl;
					}
				}
					time = clock()-time; 
					double tle = ((double) time)/ CLOCKS_PER_SEC ;
					total+=tle;
					if (testing%100==0 && testing!=0)
					{
						hundcount++;
						printf("%d searches done in %lf seconds\n",hundcount*100000,total);
					}
			}
			time2 = clock()-time2; 
			double tle2 = ((double) time2)/ CLOCKS_PER_SEC ;
			printf("Total time taken is %lf seconds\n",tle2);
		}
		if (query==0)
		{
			return 0;
		}
	}	
}
