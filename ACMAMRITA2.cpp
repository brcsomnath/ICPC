#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	ll a[100005];
	while(t--)
	{
		ll N,M,X;
		cin>>N>>M>>X;
		ll b[M+1+X];
		ll pre[M+X+1];
		memset(b,0,sizeof(b));
		memset(pre,0,sizeof(pre));
		for(ll i=0;i<N;i++)
		{
			cin>>a[i];
			a[i]=a[i]%M;
			b[a[i]]++;
		}
		pre[0]=b[0];
		for(ll i=1;i<M+X;i++)
		{
			pre[i]=b[i]+pre[i-1];
			cout<<pre[i]<<" ";
		}
		ll ans=0;
		for(ll i=0;i<M;i++)
		{
			if(i<=X)
				ans+=b[i]*pre[X-i];
			else
				ans+=b[i]*(pre[M-i+X]-pre[M-i-1]);
		}
		cout<<ans<<endl;
	}
}
