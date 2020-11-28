#include <bits/stdc++.h> 
using namespace std; 

int binser(vector<long long int> arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binser(arr, l, mid - 1, x); 
        return binser(arr, mid + 1, r, x); 
    } 
    return -1; 
} 
int main() 
{ 
	int n ;
	long long int count=1;
  	cin >> n;
  	vector<long long int> arr;
  	vector<long long int> check;
  	int *fact = (int *)calloc (n,sizeof(int));
  	int k=0;
	fact[k]=1;
	while (++k < n)
	{
		fact[k]=fact[k-1]*k;
	}
  	for (int i=0;i<n;i++)
  	{
  		long long int in;
  		cin >> in;
  		arr.push_back(in);
  		check.push_back(in);
	}
	sort(arr.begin(),arr.end());
	for(int i = 0; i < arr.size(); i++)
	{
		for (int i=0;i<n;i++)
		{
			cout << arr[i] << " ";
		}
		cout << count << endl;
		if(arr[i]==check[i])
		{
			continue;
		}
		else
		{
			int j=binser(arr,0,n-1,check[i]);
			swap(arr[i],arr[j]);
			//cout << j << " " << fact[n-i-1];
			count+=(j-i) * fact[n-i-1];
			//cout<< count << endl <<j*fact[n-i-1]<<endl;
			sort(arr.begin()+i+1,arr.end());
		}
	}
	cout << count << endl;
    return 0; 
}
