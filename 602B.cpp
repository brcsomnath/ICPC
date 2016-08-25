#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll a[n];
	ll b[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	for(ll i=1;i<n;i++)
	b[i-1]=a[i]-a[i-1];//,cout<<b[i-1]<<" ";
	//cout<<endl;
	ll c=b[0],max=0,l=1;
	for(ll i=1;i<n-1;i++)
	{
		//cout<<c<<" "<<l<<endl;
		if(c==0)
			l++,c=b[i];
		else if(c==1)
			{
				if(b[i]==1)
				{
					c=b[i];
					max=(max>l)?max:l;
					l=1;
				}
				else
				{l++;if(b[i]!=0)c=b[i];}
			}
		else if(c==-1)
			{	
				if(b[i]==-1)
				{
					c=b[i];
					max=(max>l)?max:l;
					l=1;
				}
				else
				{l++;if(b[i]!=0)c=b[i];}
			}
	}
	max=(max>l)?max:l;
	cout<<(max+1);
}
