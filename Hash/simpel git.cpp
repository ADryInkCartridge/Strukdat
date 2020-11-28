#include <bits/stdc++.h> 
using namespace std; 

vector<pair<string,int> > git;
vector<pair<string,int> > branch;
int bc=0,mc=0;
int master=1;
int pm=-1,pb=-1;
int main ()
{
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
                git.push_back(make_pair(in,mc));
                mc++;
                if (git[pm+1].second!=-1)
                {
                    pm++;
                }
                else
                {
                    pm=mc-1;
                }
            }
            else
            {
                branch.push_back(make_pair(in,bc));
                bc++;
                if (branch[pb+1].second!=-1)
                {
                    pb++;
                }
                else
                {
                    pb=bc-1;
                }
            }
        }
        if (opt=="reset")
        {
            int reset;
            cin >> reset;
            if (master==1)
            {
                for (int i=git.size()-1;i>reset;i--)
                {
                    git[i].second=-1;
                }
                pm=reset;
                cout << "Anda berada di commit " << git[pm].first << endl;
            }
            else
            {
                for (int i=branch.size()-1;i>reset;i--)
                {
                    branch[i].second=-1;
                }
                pb=reset;
                cout << "Anda berada di commit " << branch[pb].first << endl;
            }
        }
        if (opt=="log")
        {
            if (master==1)
            {
                for (int i=git.size()-1;i>=0;i--)
                {
                    if(git[i].second!=-1)
                    cout << git[i].second  << endl << git[i].first << endl;
                }
                if (git.empty())
                {
                    cout << endl;
                }
            }
            else
            {
                for (int i=branch.size()-1;i>=0;i--)
                {
                    if(branch[i].second!=-1)
                    cout << branch[i].second << endl << branch[i].first << endl;
                }
                if (branch.empty())
                {
                    cout << endl;
                }
            }
        }
        if (opt=="checkout")
        {
            int num;
            cin >> num;
            if (master==1)
            {
                if (num<git.size() && git[num].second!=-1)
                {
                    pm=num;
                    cout << "Anda berada di commit " << git[pm].first << endl;
                }
                else
                {
                    cout << "ID tidak ditemukan" << endl;
                }
            }
            else
            {
                if (num<branch.size() && branch[num].second!=-1)
                {
                    pb=num;
                    cout << "Anda berada di commit " << branch[pb].first << endl;
                }
                else
                {
                    cout << "ID tidak ditemukan" << endl;
                }
            }
        }
        if (opt=="status")
        {
            if (master==1)
            {
                cout << "Anda berada di commit " << git[pm].first << endl;
            }
            else
            {
                cout << "Anda berada di commit " << branch[pb].first << endl;
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
            int del=0;
            if (master==1)
            {
                int flag=0;
                if (!git.empty())
                {
                	for (int j=git.size()-1;j>=0;j--)
                	{
                		for (int i=branch.size()-1;i>=0;i--)
		                {
		                	//cout << git[j].first << " " << branch[i].first << endl;
		                    if (git[j].first==branch[i].first)
		                    {
		                    	del=branch.size()-i-1;
		                    	flag=1;
		                        break;
		                    }
		                }
						if (flag==1)
						{
							break;	
						}	
					}
					for (int i=del;i>0;i--)
	                {
	                    branch.pop_back();
	                    mc--;
	                }
				}
            }
            else
            {
            	int flag=0;
                if (!branch.empty())
                {
                	for (int j=branch.size()-1;j>=0;j--)
                	{
                		for (int i=git.size()-1;i>=0;i--)
		                {
		                    if (branch[j].first==git[i].first)
		                    {
		                    	del=git.size()-i-1;
		                    	flag=1;
		                        break;
		                    }
		                }
						if (flag==1)
						{
							break;	
						}	
					}
	                for (int i=del;i>0;i--)
	                {
	                    git.pop_back();
	                    mc--;
	                }
				}
            }
    	}
    }
}
