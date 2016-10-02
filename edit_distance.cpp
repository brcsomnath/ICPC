#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll editDist(string a, string b)
{
	ll m= a.length(), n= b.length();

	ll edit[m+1][n+1];
	for(ll i=0; i<=m; i++)
		for(ll j=0; j<=n; j++)
		{
			if(i==0)
				edit[i][j] = j;
			else if(j == 0)
				edit[i][j] = i;
			else if( a[i-1] == b[j-1])
				edit[i][j] = edit[i-1][j-1];
			else
				edit[i][j] = 1 + min(edit[i-1][j], min(edit[i-1][j-1], edit[i][j-1]));
		}
	return edit[m][n];
}

int main()
{
	string a, b;
	cin>>a>>b;
	cout<<editDist(a,b)<<endl;
}