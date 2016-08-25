#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll a[100005];
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,max=0;
    cin>>n;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    for(int i=0;i<n+1;i++)
    {
      cin>>a[i];
    }
    ll c=0;
    for(int i=0;i<n;i++)
    {
      if(s1[i]==s2[i])
      {
        c++;
        if(a[c]>max)
        max=a[c];
      }
      if(s1[i]!=s2[i])
      {
        max=(max>a[0])?max:a[0];
      }
    }
    if(c==n)
    max=a[n];
    cout<<max<<endl;
  }
}
