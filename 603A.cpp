#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,c=0,l=0;
	cin>>n;
	string s;
	cin>>s;
	c=(s[0]=='1')?1:0;
	l=1;
	for(ll i=1;i<n;i++)
	{
		if(c==0&&s[i]=='1')
			l++,c=1;
		if(c==1&&s[i]=='0')
			l++,c=0;
	}
	cout<<min(n,l+2);
}
