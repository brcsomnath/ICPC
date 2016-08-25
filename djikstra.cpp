#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fore(i,n) for(int i=0;i<n;i++)
vector<vii> AdjList;
int main()
{
  int V,E,a,b,w;
  cin>>V>>E;
  AdjList.assign(V,vii());
  vi dist(V,10000000000);
  fore(i,E)
  {
    cin>>a>>b>>w;
    AdjList[a].push_back(ii(b,w));
    AdjList[b].push_back(ii(a,w));
  }
  cout<<"Select the source"<<endl;
  int s;
  cin>>s;
  dist[s]=0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push(ii(0,s));
  while(!pq.empty())
  {
    ii v=pq.front;
    pq.pop();
    int d=v.first; int m=v.second;
    if(d>dist[m]) continue;
    fore(i,AdjList[m])
    {
      ii k=AdjList[m][i];
      if(dist[m]+k.second<dist[k.first])
      {
        dist[k.first]=dist[m]+k.second;
      }
    }
  }
}
