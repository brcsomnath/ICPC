#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define fore(i,n) for(int i=0;i<n;i++)
vector<vii> AdjList;
vi p;
int V,E;
int main()
{
  int a,b,s;
  cin>>V>>E;
  AdjList.assign(V,vii());
  fore(i,E)
  {
    cin>>a>>b;
    AdjList[a].push_back(ii(b,0));
    AdjList[b].push_back(ii(a,0));
  }
  cout<<"Enter the source"<<endl;
  cin>>s;
  queue<int> q;
  q.push(s);
  vi dist(V,1000000000); dist[s]=0;
  p.assign(V,-1);
  int layer=-1;

  //BFS
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    if(dist[u]!=layer) printf("Layer %d \n",dist[u]);
    layer=dist[u];
    printf("Visit %d \n",u);
    fore(j,AdjList[u].size())
    {
      ii d=AdjList[u][j];
      if(dist[d.first]==1000000000)
      {
        dist[d.first]=dist[u]+1;
        p[d.first]=u;
        q.push(d.first);
      }
    }
  }
  return 0;
}
