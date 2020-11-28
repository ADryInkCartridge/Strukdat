#include <bits/stdc++.h>
using namespace std;

vector<int> arr ;

int main ()
{
    int n,t,num;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    cin >> t;
    for (int test=1;test<=t;test++)
    {
        int in,flag=0;
        cin >> in;
        for (int i=0; i<n; i++)
        {
            for (int j=n-1; j>n/2; j--)
            {
                if (i!=j && arr[i] + arr[j] == in)
                {
                    flag=1;
                    cout << "Case " << test << ": " << i+1 << " "<< j+1 << "\n";
                    break;
                }
            }
            if (flag==1)
                break;
        }
        if (flag == 0)
           cout << "Case " << test << ": " << in << " not found\n";
    }
}
