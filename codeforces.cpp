#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	while(m--)
	{
		ll i=0,x,c1=0,sum=0;
		char c;
		cin>>x;
		cin>>c;
		s[x-1]=c;
		for(i=0;i<n;i++)
		{
			if(s[i]!='.')
			{
				if(c1!=0)
				sum+=c1-1;
				c1=0;
			}
			else
			c1++;
		}
		if(c1!=0)
		sum+=(c1-1);
		cout<<sum<<endl;
	}
}
