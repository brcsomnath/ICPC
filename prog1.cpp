#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	ll u=m+1>n?n:m+1;
	ll l=m-1>1?m-1:1;
	ll uc=n-u;
	ll lc=l-1;
	if(uc>lc)
		cout<<u;
	else if(uc<lc)
		cout<<l;
	else
	{
		if(l!=m)
			cout<<l;
		else
			cout<<u;
	}
}