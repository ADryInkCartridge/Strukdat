#include <bits/stdc++.h>
using namespace std;

struct ipkmhs
{
	char nim[11];
	char name[30];
	float gpa;
};

int main ()
{
	struct ipkmhs mhs[5];
    for (int i=0;i<5;i++)
    {
    	int in;
    	char nimIN[11];
    	char nameIN[30];
    	cout << "Input NIM, Nama, dan GPA anda !" << endl;
    	cin >> nimIN >> nameIN >> in ;
    	strcpy(mhs[i].nim,nimIN);
    	strcpy(mhs[i].name,nameIN);
    	mhs[i].gpa = in;
	}
	cout << "mhs gpa>=3.0" << endl;
	for (int i=0;i<5;i++)
	{
		if (mhs[i].gpa>=3)
		{
			cout << mhs[i].name << endl;
		}
	}
	cout << "mhs gpa< 3.0" << endl;
	for (int i=0;i<5;i++)
	{
		if (mhs[i].gpa<3)
		{
			cout << mhs[i].name << endl;
		}
	}
}
