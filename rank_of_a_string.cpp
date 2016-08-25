#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000003
#define fore(i,n) for(ll i=1;i<n;i++)
#define forn(i,n) for(ll i=0;i<n;i++)
ll fact(ll n)
{
  ll f=1;
  fore(i,n)
  f=f*i;
  return f;
}
ll findRank(string s)
{
  ll n=s.length(),rank=1;
  map<char,int> a;
  forn(i,n)
  {
    ll k=0;
    for(int j=i+1;j<n;j++)
    {
      if(s[j]<s[i])
      k++;
    }
    rank=(rank+k*fact(n-i-1))%MOD;
  }
  return rank;
}
int main()
{
  cout<<findRank("baa");
}
