#include <bits/stdc++.h>

using namespace std;


int main()
{
	map<string,int> waris;
	string die;
	int money;
	int bagian,sum,T;
	
	cout<<"Jumlah Harta yang ditinggalkan :\n";
	cin>>money;

	cout<<"Siapa yang meninggal? :\n";
	cin>>die;
	
	cout << "Ada berapa ahli waris ?" << endl;
	cin >>sum;
	
	cout<<"\tPembagian Harta Waris\n";
	cout<<"\n";
	
	
	cout<<"Siapa Saja:\n";

	for(T=1;T<=sum;T++)
	{
		cout<<"Tuliskan Nama Ahli Waris dan Bagianya dalam titik(Misal 0.25)"<<endl;
		float persen;
		string name;
		cin>>name>>persen;
		waris.insert(make_pair(name,persen*money));
	}
	for(auto it = waris.cbegin(); it != waris.cend(); ++it)
	{
	    std::cout << it->first << " " << it->second << "\n";
	}
	
}
