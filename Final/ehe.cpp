#include <bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
 
int main() {
	while (1) {
		int n, k;
		cin >> n >> k;
		if (n==0 && k==0)
		{
			return 0;
		}
		pair<int, int> car[101];
		for (int i = 0; i < n; i++) {
			cin >> car[i].fs >> car[i].sc;
		}
 
		sort(car, car + n);
 
		stack<int> st;
		bool can = 1;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && st.top() <= car[i].fs) st.pop();
			st.push(car[i].sc);
			if (st.size() > k) {
				cout << "Gak Bisa Woi\n";
				can = 0;
				break;
			}
		}
 
		if (can) cout <<"Lancar Jaya\n";
	}
	return 0;
}
