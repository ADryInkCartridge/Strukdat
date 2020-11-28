#include <bits/stdc++.h>
using namespace std;

bool comparator(string a, string b) {return a < b;}
vector<string> sortyboi(vector<string> a) 
{
    int n = a.size();
    sort(a.begin(), a.end(), comparator);
    return a;
}
int main ()
{
	int n;
	cin>>n;
	getchar();
	for (int test=0;test<n;test++)
	{
		vector<string> koyer;
		string in;
		getline(cin, in);
		string word = "";
		for (auto x : in) 
        { 
            if (x == ' ') {
                koyer.push_back(word);
                word = ""; 
            } 
            else
            { 
                word = word + x; 
            } 
        }
        koyer.push_back(word);
        koyer = sortyboi(koyer);
	    string now = "";
	    for (auto i : koyer) 
		{
	        if (i != now) {
	            cout << i << " ";
	            now = i;
	        }
	    }
	    cout << endl;
		}
}
