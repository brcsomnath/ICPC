#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t,j=0;
  cin>>t;
  ll a[100005];
  ll b[100005];
  while(t--)
  {
    j++;
    ll n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
      sum+=a[i]*b[n-i-1];
    }
    cout<<"Case #"<<j<<": "<<sum<<endl;
  }
}
