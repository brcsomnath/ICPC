#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,x,y,z;
	cin>>a>>b>>c;
	cin>>x>>y>>z;
	if(x>a)
	{
		for(ll i=0;i<(x-a);i++)
		{
			if(b>c)
			b-=2;
			else
			c-=2;
		}
	}
	if(y>b)
	{
		for(ll i=0;i<(y-b);i++)
		{
			if(a>c)
			a-=2;
			else
			c-=2;
		}
	}
	if(z>c)
	{
		for(ll i=0;i<(z-c);i++)
		{
			if(b>a)
			b-=2;
			else
			a-=2;
		}
	}
	if(a>=x&&b>=y&&c>=z)
	cout<<"Yes";
	else
	cout<<"No";
}
