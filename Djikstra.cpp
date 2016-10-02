#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
int V, E, a, b, s, w;

void djikstra(int s)
{
	vi dist(V, 10000000); dist[s] = 0;
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while(!pq.empty())
	{
		ii front = pq.top(); pq.pop();
		int d= front.first, u =front.second;
		if(d > dist[u]) continue;
		for(int i=0; i<AdjList[u].size(); i++)
		{
			ii v= AdjList[u][i];
			if(v.second + dist[u] < dist[v.first])
			{
				dist[v.first]= dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}

	for (int i = 0; i < V; i++)
    printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
}

int main()
{
	scanf("%d %d", &V, &E);
	AdjList.assign(V, vii());

	for(int i=0; i<E; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		AdjList[a].push_back(ii(b, w));
	}
	scanf("%d", &s);
	djikstra(s);
}