#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0;i<n;i++)
int main()
{

	map<ll, ll> M;
	ll ans,n,k,sum=0,m;
	ll A[100005];
	ll C[100005];
	ll D[100005];
	cin>>n>>k>>m;
	FOR(i,n)
	{
		cin>>A[i];
	}
	FOR(i,n)
	{
		cin>>C[i];
	}
	FOR(i,n)
	{
		cin>>D[i];
		sum+=(D[i]-C[i]);
	}
	
    M.clear();
    ans = 0LL;
    int j = 0,count=0;
     
    FOR(i, n) 
    {
        if(A[i]==m) count++;
        if(count == k) 
        {
             do {
                ans += n - i;
                //M[A[j]]--;
                if(A[j]==m) count--;
                j++;
            } while(m != A[j - 1]);
        }
     }
     if(sum>10*ans)
     {
  		cout<<ans<<" "<<(sum-10*ans)<<endl;
     }
     else
     {
   		cout<<ans<<" "<<"0"<<endl;
     }
}
