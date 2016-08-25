#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll OK,ans;
void backtrack(int rw,int ld,int rd)
{
	if(rw==OK){ans++;return;}
	int pos=OK&(~(rw|ld|rd));
	while(pos)
	{
		int p=pos&-pos;
		pos-=p;
		backtrack((rw|p),(ld|p)<<1,(rd|p)>>1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		OK=(1<<n)-1;ans=0;
		backtrack(0,0,0);
		cout<<ans<<endl;
	}
}

