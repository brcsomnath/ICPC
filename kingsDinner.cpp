#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void GraphColor(vector<int> v[],ll j, int *f,int color[],int cnt[])
{
	int i,k;
	color[j]=0;
	queue<int> q;
	q.push(j);
	cnt[0]++;
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		for(i=0;i<v[k].size();i++)
		{
			if(color[v[k][i]]==-1)
			{
				color[v[k][i]]=1-color[k];
				q.push(v[k][i]);
				cnt[1-color[k]]++;
			}
			else if(color[v[k][i]]==color[k])
			{
				*f=1;
				return;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		ll n;
		cin>>n;
		vector<int> Graph[n+1];
		for(ll j=1;j<=n;j++)
		{
			ll x; cin>>x;
			while(x--)
			{
				ll y; cin>>y;
				Graph[j].push_back(y);
			}
		}
		int color[n+1]; int f=0; int cnt[]={0,0};
		memset(color,-1,sizeof(color));
		for(ll j=1;j<=n;j++)
		{
			if(color[j]==-1)
			{
				GraphColor(Graph,j,&f,color,cnt);
			}
		}
		cout<<"Case "<<i<<": ";
		if(f==0)
		{
			cout<<"1 "<<min(cnt[0],cnt[1])<<" "<<max(cnt[0],cnt[1])<<endl;
		}
		else
		cout<<"0 0 0"<<endl;
	}
}
