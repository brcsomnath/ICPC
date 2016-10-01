#include <bits/stdc++.h>
typedef long long ll;

typedef pair <int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;

int a, b, V, E, s;

int main()
{
	scanf("%d %d", &V, &E);

	AdjList.assign(V, vii());
	vi dist(V, 10000000);

	for(int i=0; i<E; i++)
	{
		scanf("%d %d", &a, &b);
		AdjList[a].push_back(ii(b, 0));
		AdjList[b].push_back(ii(a, 0));
	}
	scanf("%d ", &s);
	vi prev;
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	int layer = -1;


	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(dist[u] != layer) layer = dist[u];
		cout<<"\n Layer "<<layer<<": ";
		cout<<"visit "<<u<<" ";
		for(int i=0; i<AdjList[u].size(); i++)
		{
			ii v = AdjList[u][i];
			if(dist[v.first] == 10000000)
			{
				dist[v.first] = dist[u] + 1;
				prev[v.first] = u;
				q.push(v.first);
			}
		}
	}
}