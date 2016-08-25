#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
string lcs( string X, string Y)
{
   int m=X.length();
   int n=Y.length();
   
   int L[m+1][n+1];
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 	
   // Following code is used to print LCS
   int index = L[m][n];
   cout<<index<<endl;
   // Create a character array to store the lcs string
   string lcs; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   return lcs;
}
 
/* Driver program to test above function */
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	string arr[100];
	while(t--)
	{
		ll n;
		cin>>n;
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		string l=lcs(arr[0],arr[1]);
		for(ll i=2;i<n;i++)
		{
			l=lcs(l,arr[i]);
		}
		ll a=0,b=0;
		for(ll i=0;i<l.length();i++)
		{
			if(l[i]=='a')
			a++;
			else
			b++;
		}
		cout<<l<<endl;
	}
	return 0;
}
