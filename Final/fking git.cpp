#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
	int bc=0,mc=0;
	int master=1;
	string sm,sb;
	deque<pair<string,int>> m,b;
    while (1)
    {
        string opt;
        cin >> opt;
        if (opt=="quit")
        {
            return 0;
        }
        if (opt=="commit")
        {
            string in;
            cin >> in;
            if (master==1)
            {
            	sm=in;
            	m.push_back(make_pair(in,mc));
            	mc++;
            }
            else
            {
            	sb=in;
            	b.push_back(make_pair(in,bc));
            	bc++;
            }
        }
        if (opt=="reset")
        {
            int reset;
            cin >> reset;
            if (master==1)
            {
	            while(m.back().second != reset)
			    {
			        m.pop_back();
			    }
			    sm=m.back().first;
			    cout << "Anda berada di commit " << m.back().first << endl;
            }
            else
            {
                while(b.back().second != reset)
			    {
			        b.pop_back();
			    }
			    sb=b.back().first;
			    cout << "Anda berada di commit " << b.back().first << endl;
            }
        }
        if (opt=="log")
        {
            if (master==1)
            {
                if(m.empty())
                {
                	cout << endl;
				}
    			for(int i=(m.size()-1); i >= 0; i--)
			    {
			        cout << m[i].second << endl << m[i].first << endl;
			    }
			}
            else
            {
            	if(b.empty())
                {
                	cout << endl;
				}
    			for(int i=(b.size()-1); i >= 0; i--)
			    {
			        cout << b[i].second << endl << b[i].first << endl;
			    }
            }
        }
        if (opt=="checkout")
        {
            int num;
            cin >> num;
            if (master==1)
            {
                deque<pair<string,int>>::reverse_iterator it;
			    int flag = 0;
			    for(it = m.rbegin();it!=m.rend();it++)
			    {
			        if(it->second == num)
			        {
			            cout << "Anda berada di commit " << it->first << endl;
			            flag = 1;
			            sm=it->first;
			            break;
			        }
			    }
			    if(flag != 1)
			        cout << "ID tidak ditemukan" << endl;
            }
            else
            {
                deque<pair<string,int>>::reverse_iterator it;
			    int flag = 0;
			    for(it = b.rbegin();it!=b.rend();it++)
			    {
			        if(it->second == num)
			        {
			            cout << "Anda berada di commit " << it->first << endl;
			            flag = 1;
			            sb=it->first;
			            break;
			        }
			    }
			    if(flag != 1)
			    cout << "ID tidak ditemukan" << endl;
            }
        }
        if (opt=="status")
        {
            if (master==1)
            {
                cout << "Anda berada di commit " << sm << endl;
            }
            else
            {
                cout << "Anda berada di commit " << sb << endl;
            }
        }
        if (opt=="branch")
        {
            string q;
            cin >> q;
            if (q=="master")
            {
                master=1;
            }
            else
            {
                master=0;
            }
        }
        if (opt=="sync")
        {
            if (master==1)
            {
            	for(size_t i = min(b.size(),m.size())-1;i>=0;i--)
			    {
			        if(b[i].first == m[i].first && b[i].second == m[i].second)
			        {
			            while(b[i].first != b.back().first)
			                b.pop_back();
			            break;
			        }  
			    }
			}
			else
			{
            	for(size_t i = min(m.size(),b.size())-1;i>=0;i--)
			    {
			        if(m[i].first == b[i].first && m[i].second == b[i].second)
			        {
			            while(m[i].first != m.back().first)
			                m.pop_back();
			            break;
			        }  
			    }
			}
    	}
    }
}
