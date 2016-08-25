#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fore(n) for(int i=0;i<n;i++)
ll fact(ll n)
{
  ll f=0;
  for(int i=1;i<=n;i++)
  f=f+i;
  return f;
}
int main()
{
  ll a[100005];
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,c=0,sum=0,k=0;
    cin>>n;
    fore(n)
    {
      cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
      if(a[i]>=a[i-1])
      {
        c++;
      }
      else
      {
        sum+=fact(c);
        c=0;
      }
    }
    sum+=fact(c);
    cout<<(sum+n)<<endl;
  }
}
