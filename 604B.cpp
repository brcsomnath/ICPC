#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k,max;
	cin>>n>>k;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	max=a[n-1];
	if(k>=n)
		cout<<a[n-1];
	else
	{
		ll j=2*(n-k);
		for(ll i=0;i<j;i++)
		{
			max=max>(a[i]+a[j-i-1])?max:(a[i]+a[j-i-1]);
		}
		cout<<max;
	}
}
