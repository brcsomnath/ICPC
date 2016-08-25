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
	string A,B;
	cin>>A>>B;
	cout<<lcs(A,B)<<endl;
}
