#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,T,K;
    scanf("%d", &N);
    vector<int> arr;
    for(int i=0; i<N; i++)
    {
        cin>>K;
        arr.push_back(K);
    }
    scanf("%d", &T);
    for (int k=0; k<T; k++)
    {
        cin>>K;
        int flag=0;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (i!=j && arr[i] + arr[j] == K)
                {
                    flag=1;
                    printf("Case %d: %d %d\n",k+1,i+1,j+1);
                    break;
                }
            }
            if (flag==1)
                break;
        }
        if (flag == 0)
            printf("Case %d: %d not found\n", k+1,K);
    }
    return 0;
}
