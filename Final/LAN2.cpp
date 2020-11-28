#include <bits/stdc++.h>
using namespace std;
set<string> needs;

struct servers
{
  string id;
  int s_floor;
  vector<string> s_data;
};

struct routers
{
  int r_floor;
  vector<string> r_data;
};
struct everything //genius ass krisna class on class omega lol
{
  public:
  vector<routers> r;
  vector<servers> s;
  public:
  void server_insert(string id,int n,int floor)
  {
    servers s_stream;
    vector<string> datastream;
    for (int i=0;i<n;i++)
    {
      //cout << i << endl;
      string in;
      cin >> in;
      datastream.push_back(in);
    }
    s_stream = {id,floor,datastream};
    s.push_back(s_stream);
  }

  void router_insert(int n,int floor)
  {
    routers r_stream;
    vector<string> datastream;
    for (int i=0;i<n;i++)
    {
      string in;
      cin >> in;
      datastream.push_back(in);
      needs.insert(datastream[i]);
    }
    r_stream = {floor,datastream};
    r.push_back(r_stream);
  }
};



int main()
{
  everything lan;
  int n,m;
  cin >> n;
  for (int i=0;i<n;i++)
  {
    string id;
    int n_data,floor;
    cin >> id >> n_data >> floor;
    lan.server_insert(id,n_data,floor);
  }

  cin >> m;
  for (int i=0;i<m;i++)
  {
    int n_data,floor;
    cin >> n_data >> floor;
    lan.router_insert(n_data,floor);
  }
  map<string,set<pair<string,int> > > done;
  set<pair<string,int> > temp;
  for (auto x = needs.begin();x != needs.end();x++) // cuz no string
  {
    temp.clear();
    for (auto y = lan.s.begin();y < lan.s.end();y++)
    {
      for (auto z = y->s_data.begin();z != y->s_data.end();z++)
      {
        if (*z==*x)
        {
          temp.insert(make_pair(y->id,y->s_floor));
        }
      }
    }
    done.insert({*x,temp});
  }
  //process all the data
  int client=1;
  int connections=0;
  for (auto x = lan.r.begin();x < lan.r.end();x++)
  {
    temp.clear();
    int r_height= x->r_floor;
    set<pair<int, string> > order;
    set<string> con;
    for (auto y = x->r_data.begin(); y!=x->r_data.end();y++)
    {
      int delta = INT_MAX;
      temp=done[*y];
      for (auto z = temp.begin();z != temp.end();z++)
      {
        delta = min(delta, abs(z->second - x->r_floor));
        con.insert(z->first);
      }
      order.insert(make_pair(delta, *y));
    }
    cout <<"Client " << client << ":" << endl;
    for (auto it = order.begin(); it!=order.end();it ++)
    {
      cout << (*it).second << endl;
    }
    connections += con.size();
    client++;
  } 
  cout << "Total Koneksi: " << connections << endl;
  
  return 0;
}
