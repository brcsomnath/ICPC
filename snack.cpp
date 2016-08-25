//g++  4.9.3

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        
        ll pos=0,neg=0;
        ll a[n];
        ll b[n];
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            if(x>=0)
            {
                a[pos++]=x;
            }
            else
            {
                b[neg++]=-x;
            }
        }
        sort(a,a+pos);
        sort(b,b+neg);
        ll prod=1;
        ll i=pos-1,j=neg-1;
        ll k1=k;
        if(k&1==1&&k>pos)
        {
            i=0;j=0;
            while(k>0)
            {
                ll pp=MOD,pn=MOD;
                //cout<<a[i]<<" "<<b[j]<<endl;
                
                if(k==1)
                {
                    if(i>=0)
                        pp=a[i],i--;
                    else
                        pp=-b[0],j--;
                }
                else
                {
                    if(i+1<pos)
                        pp=a[i]*a[i+1];
                    else
                        pp=MOD;
                    
                    if(j+1<neg)
                        pn=b[j]*b[j+1];
                    else
                        pn=MOD;
                    
                    if(pp<pn)
                        i+=2;
                    else
                        j+=2;
                }
                
                
                pp=pp<pn?pp:pn;
                prod=(((pp+MOD)%MOD)*(prod%MOD)+MOD)%MOD;
                //cout<<pp<<endl;
                k-=2;
            }
            if(pos==0)
            {
                prod=1;
                for(ll z=0;z<k1;z++)
                    prod=((-b[z])%MOD*prod%MOD)%MOD;
                
            }
        }
        else
        {
            while(k>0)
            {
                ll pp=-MOD,pn=-MOD;
                //cout<<a[i]<<" "<<b[j]<<endl;
                
                if(k==1)
                {
                    if(i>=0)
                        pp=a[i],i--;
                    else
                        pp=-b[0],j--;
                }
                else
                {
                    if(i-1>=0)
                        pp=a[i]*a[i-1];
                    else
                        pp=-MOD;
                    
                    if(j-1>=0)
                        pn=b[j]*b[j-1];
                    else
                        pn=-MOD;
                    
                    if(pp>pn)
                        i-=2;
                    else
                        j-=2;
                }
                
                
                pp=pp>pn?pp:pn;
                prod=(((pp+MOD)%MOD)*(prod%MOD)+MOD)%MOD;
                //cout<<pp<<endl;
                k-=2;
            }
        }
        cout<<((prod+MOD)%MOD)<<endl;
    }
}