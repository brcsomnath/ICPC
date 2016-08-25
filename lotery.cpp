//Title of this code
//g++  4.9.2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,x,y) for(ll i=x;i<y;i++)
#define MOD 1000000007
ll store[100005];
ll c[100005];
ll d[100005];
ll C1(ll n,ll k)
{
    ll f=1,f1=1;
    REP(i,n-k+1,n+1)
        f=(f%MOD*i%MOD)%MOD;
    REP(i,2,k)
        f1=f1*i;
    return ((f/f1)%MOD);
}
ll gcd(ll a, ll b) {
    ll t=a;
    a=a>b?a:b;
    b=(a==t)?b:t;
    if(!b) return 1;
    while (a%b) {
        ll temp = a%b;
        a = b;
        b = temp;
    }
    if(!b) b=1;
    return b;
}
int main()
{
    cout<<gcd(50568956,100100999);
    memset(store,0,sizeof(store));
    ll t;
    cin>>t;
    ll n,k,a,b,m;
    cin>>n>>k;
    cin>>a>>b>>m;
    REP(i,0,t-1)
    {
        cin>>c[i];
    }
    REP(i,0,t-1)
    {
        cin>>d[i];
    }
    ll ans=0;
    REP(i,0,t)
    {
        if(i!=0)
        {
            n=1+(a*ans+c[i-1])%m;
            k=1+(b*ans+d[i-1])%n;
        }
        ll g=n,M=1;
        REP(j,1,k+1)
        {
            if(j==1||j==n)
                store[j]=n;
            else
                store[j]=C1(n,j);
            if(j<=(n/2+1))
            {
                g=gcd(M,store[j]);
                M=M/g;
                M=((M%MOD)*(store[j]%MOD))%MOD;
            }
        }
        ans=M;
        cout<<ans<<endl;
    }
}
