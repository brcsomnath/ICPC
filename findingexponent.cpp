#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	for(ll cs=1;cs<=t;cs++)
	{
		ll x,y,e;
		scanf("%lld %lld",&x,&y);
		ll temp=y,len=0;
		while(temp)
			temp/=10,len++;
		long double p=log10(x);
		long double z=p;
		for(e=1;;e++)
		{
			//cout<<"*";
			z=e*p;
			if((ll)(powl(10.0L,z-floor(z)+len-1))==y)break;
		}
		cout<<"Case "<<cs<<": "<<e<<endl;
	}
}
