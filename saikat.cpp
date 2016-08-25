//Title of this code
//g++  4.9.2
 
#include <bits/stdc++.h>
#include <string> 
using namespace std;
 
typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <ll, ll> pii;
#define gc getchar()
#define pc putchar
#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define MAX 5000000
#define debug cout<<"A"<<endl
#define prnt(a) cout<<a<<endl
#define MOD 1000000009
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define FORr(i,a,b) for (ll i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
string convertInt(ll number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
 
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}
 
inline ll power(ll a, ll b)
{
	ll multiply=1;
	FOR(i,0,b)
	{
		multiply*=a;
	}
	return multiply;
}
//Fast Read
inline void read(ll & n)
{
	n = 0;
	char ch = gc; int sign = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') sign = -1; ch = gc; }
	while(ch >= '0' && ch<= '9')
	{
		n = n*10 + ch - '0';
		ch = gc;
	}
	n *= sign;
}
 
//Fast print
inline void print(ll n)
{
	char ch[15];
	int ind=0;
	if(n<0)
    {
        pc('-');
        n *= -1;
    }
	if(n == 0)
	{
		pc('0');
	}
	while(n > 0)
	{
		ch[ind] = n%10 + '0';
		n /= 10;
		ind++;
	}
	while(ind--) pc(ch[ind]);
	pc('\n');
}
int main()
{
 
  ll t,ans,m,c1,c0;
  ll a[100005][3];
  double s[100002];
  double index[100002];
  double y[100002];
  read(t);
  while(t--)
  {
  	ll n;
    read(n);
    c0=c1=0;
    FOR(i,0,n)
    {
      read(a[i][0]);read(a[i][1]);read(a[i][2]);
      ll g=__gcd(__gcd(a[i][0],a[i][1]),a[i][2]);
      a[i][0]/=g;
      a[i][1]/=g;
      a[i][2]/=g;
    }
    ll k=0;
    FOR(i,0,n)
    {
      if(a[i][1]!=0)
      {
          s[k]=double((a[i][0]*-1.0)/double(a[i][1]));
          k++;
      }
    }
    k=0;
    FOR(i,0,n)
    {
      if(a[i][1]!=0)
      {
          index[k]=double((a[i][2]*1.0)/double(a[i][1]));
          k++;  
      }
    }
    
    vector<pair<double,double> >v;
    FOR(i,0,k)
    {
      v.pb(MP(s[i],index[i]));
    }
    SORT(v);
    ll c=1;m=-1;
    FOR(i,0,k-1)
    {
      if(v[i].first==v[i+1].first)
      {
        if(v[i].second!=v[i+1].second)
          c++;
      }
      else
      {
        m=(m>c)?m:c;
        c=1;
      }
    }
    m=(m>c)?m:c;
    k=0;
    FOR(i,0,n)
    {
      if(a[i][1]==0)
      {
        y[k]=double(a[i][2]*1.0/double(a[i][0]));
        k++;
      }
    }
    sort(y,y+k);
    c0=1;
    FOR(i,0,k-1)
    {
      if(y[i]!=y[i+1])
        c0++;
    }
   
   cout<<max(m,c0)<<endl;
  }
}
