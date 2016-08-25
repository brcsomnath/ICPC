#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,l=0;
	cin>>n;
	unordered_map<int> a;
	int a1[n];
	int a2[n];
	memset(a2,0,sizeof(a2));
	for(int i=0;i<n;i++)
	{
		cin<<a1[i];
	}
	for(int i=0;i<n;i++)
	{
		if(!a[a1[i]]||a1[i]>n)
		{
			a[a1[i]]=1;
			a2[i]=a1[i];
		}
		else
		{
			for(int j=l;j<=n;j++)
			{
				if(!a[j])
				{
					a[j]=1;
					a2[i]=j;
					l=j+1;
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<a1[i]<<" ";
}