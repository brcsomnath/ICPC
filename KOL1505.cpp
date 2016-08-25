#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;;
	cin>>t;
	while(t--)
	{
		string S,T;
		cin>>S>>T;
		string s="",t="";
		s+=S[0];t+=T[0];
		for(ll i=1;i<S.length();i++)
		{
			if(S[i]!=S[i-1])
			{
				s+=S[i];
			}
		}
		for(ll i=1;i<T.length();i++)
		{
			if(T[i]!=T[i-1])
			{
				t+=T[i];
			}
		}
		//cout<<s<<" "<<t<<endl;
		if(s.compare(t)==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
