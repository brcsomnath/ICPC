#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll price[25][25];
ll memo[201][25];
ll shop
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll N;
	cin>>N;
	while(N--)
	{
		ll M,C;
		cin>>M>>C;
		for(ll i=0;i<C;i++)
		{
			cin>>price[i][0];
			for(ll j=1;j<=price[i][0];j++)
				cin>>price[i][j];
		}
		memset(memo,-1,sizeof(memo));
		ll ans=shop(M,C);
		if(ans<0)
		cout<<"no solution"<<endl;
		else
		cout<<ans<<endl;
	}
}
