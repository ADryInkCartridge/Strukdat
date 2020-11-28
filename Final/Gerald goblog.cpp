#include <bits/stdc++.h>

using namespace std;

int dua(int T){
    int x,counter=0;
    while(T--){
        cin >> x;
        counter+=x;
    }
    return counter;
    if(counter % 2 == 0){
        cout << counter/2 << " " << counter/2 << endl;
    }
    else{
        cout << (counter/2)+1 << " " << (counter/2) << endl;
    }
}

int main(){
    int T;
    int x;
    int counter = 0;

    cin >> T;
    while(T--){
    	cout << "Nih T nya = "<< T << endl;
        if(T == 1){
            cin >> x;
            cout << x << " 0\n";
        }
        else{
             dua(T);
        }
    }
}
