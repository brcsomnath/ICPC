#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t;
  cin>>t;
  while (t--) {
    ll n;
    cin>>n;
    if(n==1)
    cout<<"2"<<endl;
    else if(((n+1)&n)==0)
    {
      cout<<(n/2)<<endl;
    }
    else
    cout<<"-1"<<endl;
  }
}
