#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int n ;
	long long int count=1;
  	cin >> n;
  	vector<long long int> arr;
  	vector<long long int> check;
  	for (int i=0;i<n;i++)
  	{
  		long long int in;
  		cin >> in;
  		arr.push_back(in);
  		check.push_back(in);
	}
	sort(arr.begin(),arr.end());
	stringstream ss;
	for(int i = 0; i < check.size(); ++i)
	{
	  ss << check[i];
	}
	string s = ss.str();
	while (1)
	{
		stringstream ss2;
		for(int i = 0; i < arr.size(); ++i)
		{
		  ss2 << arr[i];
		}
		string s2 = ss2.str();
		cout << s2<< " "<< count << endl;
		if (s==s2)
		{
			break;
		}
		else
		{
			next_permutation(arr.begin(), arr.end());
			count++;
			count % 1000000007;	
		}
	}
	cout << count << endl;
    return 0; 
} 
