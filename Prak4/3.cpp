#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for (int test=0;test<t;test++)
	{
		int x,y;
		cin >> x >> y;
		int* arr = new int[1000000];
		int count =0;
		for (int i=1;i<=x;i++)
		{
			int num;
			cin >> num;
			if (num == 0)
			{
				if (i<=y)
				{
					cout << "-1\n";
				}
				else 
				{
					cout << arr[y] << "\n";
				}
			}
			else 
			{
				count++;
				arr[count]=num;
				sort (arr+1,arr+count+1);
			}
//		cout << " ARRAY : ";
//		for (int j=1;j<=count;j++)
//		{
//			cout << arr[j] << " ";
//		}
//		cout << endl;
		}
		
	}	
}
