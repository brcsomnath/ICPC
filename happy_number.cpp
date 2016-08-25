#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
#define fore(i,n) for(int i=0;i<n;i++)
int main()
{
	map<pi, int> aa;
	string s;
	cin>>s;
	ll n=s.length();
	ll a=0,b=0,c=0,sum=0;
	aa[make_pair(0,0)]++;
	fore(i,n)
	{
		a+=s[i]=='A';
		b+=s[i]=='B';
		c+=s[i]=='C';
		sum+=aa[make_pair(a-b,a-c)];
		aa[make_pair(a-b,a-c)]++;
	}
	cout<<sum<<endl;
}