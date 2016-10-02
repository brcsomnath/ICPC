#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int LCS(string a, string b)
{
	int m = a.length();
	int n = b.length();

	int lcs[m+1][n+1];

	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i == 0|| j== 0)
				lcs[i][j] = 0;
			else if(a[i-1] == b[j-1])
			{
				lcs[i][j] = 1 + lcs[i-1][j-1];
			}
			else
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
		}
	}
	return lcs[m][n];
}

int main()
{
	string a, b;
	cin>>a;
	cin>>b;
	cout<<LCS(a,b)<<endl;
}