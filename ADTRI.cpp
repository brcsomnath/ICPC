#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll a[100005];
  memset(a,0,sizeof(a));
  a[0]=0;a[1]=1;
  ll i;
  for(i=2;i;i++)
  {
    a[i]=a[i-1]+a[i-2];
    if(a[i]>1000000)
    break;
  }
  cout<<a[11];
  map<int,int> b;
  b[5]=1;
  b[10]=1;
  ll k=4;
  while(2*k<=i)
  {
    b[a[2*k-1]]=1;
    k++;
  }
  ll t;
  //cin>>t;
  while(t--)
  {
    ll n;
  }
}
