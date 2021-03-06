#include<bits/stdc++.h>
using namespace std;
#define sz 200002
#define pb(a) push_back(a)
#define ll long long
#define ull unsigned long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<29)
#define mem(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
vector<int>prime;
bool isPrime[31624],flag[sz];
void sieve(){
   mem(isPrime,true);
   for(int i=4;i<=31623;i+=2){
      isPrime[i]=false;
   }
   isPrime[1]=false;
   for(int i=3;i<=31623;i+=2){
      if(isPrime[i]){
         for(int j=i*i;j<=31623;j+=i){
            isPrime[j]=false;
         }
      }
   }
   prime.push_back(2);
   for(int i=3;i<=31623;i+=2){
      if(isPrime[i]) {
         prime.push_back(i);
      }
   }
}
ll segment_sieve(ll A,ll B){
   mem(flag,true);
   ll sq=sqrt(B)+2,s,cnt=0;
   if(A==2) cnt++;
   if(A<=2) A=3;
   for(ll i=3;i<=sq;i+=2){
      if(isPrime[i]){
        if(i>=A) s=2*i;
        else {
            s=(A/i)*i;
            if(s<A || s==i) s+=i;
        }
        for(ll j=s;j<=B;j+=i){
            flag[j-A]=false;
        }
      }
   }
   for(ll i=(A%2==0?A+1:A);i<=B;i+=2){
      cnt+=flag[i-A];
   }
   return cnt;
}
int main(){
   sieve();
   int t;
   ll A,B,ans,power_[10]={2,4,6,10,12,16,18,22,28,30};
   cin>>t;
   while(t--){
     cin>>A>>B;
     ans=segment_sieve(A,B);
     for(int i=0;i<prime.size() && (ll)prime[i]*prime[i]<=B;i++){
        for(int j=0;j<10;j++){
            ll tmp=(ll)pow((ll)prime[i],power_[j]);
            if(tmp>B) break;
            if(tmp>=A && tmp<=B){
                ans++;
            }
        }
     }
     cout<<ans<<endl;
   }
   return 0;
}
