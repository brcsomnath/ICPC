#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string lcs(string A,string B)
{
	ll i=0,j=0;
	string l="";
	while(i<A.length()&&j<B.length())
	{
		if(A[i]==B[j])
		{
			l=l+A[i];
			i++;j++;
		}
		else
		{
			i++;
		}
	}
	string l1="";
	i=0,j=0;
	while(i<A.length()&&j<B.length())
	{
		if(A[i]==B[j])
		{
			l1=l1+A[i];
			i++;j++;
		}
		else
		{
			j++;
		}
	}
	if(l1.length()>l.length())
	return l1;
	else
	return l;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string A,B,l;
	cin>>A>>B;
	l=lcs(A,B);
	cout<<l<<endl;
	
	/*ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n;
		string arr[n];
		string l="a";
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			m=arr[i].length();
			if(l.length()&&i)
			{
				if(i==1)
				l=lcs(arr[i],arr[i-1]);
				else
				l=lcs(l,arr[i]);
			}
		}
		ll a=0,b=0;
		for(ll i=0;i<l.length();i++)
		{
			if(l[i]=='a')
			a++;
			else
			b++;
		}
		if(max(a,b)==1&&min(a,b)==0&&m==2)
		cout<<"1"<<endl;
		else
		cout<<min(a,b)<<endl;
	}*/
}
