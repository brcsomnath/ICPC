#include <bits/stdc++.h>
using namespace  std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,n;
	cin>>t;
	ll fact[100005];
	ll der[100005];
	fact[0]=1,fact[1]=1;
	der[0]=1,der[1]=0;
	for(ll i=2;i<100005;i++)
	{
		fact[i]=i*fact[i-1];
		cout<<fact[i]<<" ";
		der[i]=(i-1)*(der[i-1]+der[i-2]);
	}
	while(t--)
	{
		cin>>n;
		printf("%lld/%lld \n",der[n],fact[n]);
	}
	return 0;
}
