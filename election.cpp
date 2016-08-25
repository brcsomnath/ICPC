#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m,max=0,k=0;
	cin>>n>>m;
	int a[n];
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++)
	{
		max=0,k=0;
		for(int j=0;j<n;j++)
		{
			ll x;
			cin>>x;
			if(x>max)
			{
				max=x;
				k=j;
			}
		}
		a[k]++;
	}
	max=0,k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			k=i;
		}
	}
	cout<<k+1;
}