//Title of this code
//g++  4.9.2

#include <bits/stdc++.h>
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
typedef pair <int, int> pii;
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
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
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
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    ll t;
    read(t);
    while(t--)
    {
    	ll n1,n2,m,s,ans;
    	read(n1);read(n2);read(m);
    	if(m&1)
    		s=m*((m+1)/2);
    	else
    		s=(m/2)*(m+1);
    	if(s>=min(n1,n2))
 			ans=max(n1,n2)-min(n1,n2);
 		else
 			ans=n1+n2-2*s;
 		print(ans);   	
    }
}
