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
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)
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
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    ll t;
    read(t);
    ll arr[100005];
    while(t--)
    {
    	memset(arr,0,sizeof(arr));
    	map<pii,ll> D;
    	map<string,ll> E;
    	ll n,max1=0;
    	read(n);
    	ll c1=2,i=0;
        ll x=n;
    	while(x--)
    	{
    		ll a,b,c; i++;
    		read(a);read(b);read(c);
    		ll g=__gcd(__gcd(a,b),c);
    		a=a/g;b=b/g;c=c/g;
    		ll g1;
    		if(c!=0)
    		g1=__gcd(a,c);
    		else
    		g1=1;
    		string A=convertInt(a/g1);
    		string C=convertInt(c/g1);
    		string A1=convertInt(-a/g1);
    		string C1=convertInt(-c/g1);
    		A.append(C);
    		//cout<<A<<endl;
    		A1.append(C1);
    		if(!E[A]&&!E[A1])
    		{
    			//cout<<a<<" "<<c<<endl;
    			E[A]=1;E[A1]=1;
    			if(a==0)
    			arr[0]++,max1=max(max1,arr[0]);
    			else if(b==0)
    			arr[1]++,max1=max(max1,arr[1]);
    			else
    			{
                    ll gh=__gcd(a,b);
                    a=a/gh;b=b/gh;
                    pair<ll,ll> p,p1;
                    p=make_pair(a,b);
                    p1=make_pair(-a,-b);
                    //cout<<(i)<<" "<<a<<" "<<b<<"\n";
					if(!D[p]&&!D[p1])
					{
    					//debug;
						D[p]=c1;D[p1]=c1;
						arr[c1]++;
						max1=max(max1,arr[c1]);
						c1++;
						//cout<<c1<<endl;
					}
					else
					{
						arr[D[p]]++;
						max1=max(max1,arr[D[p]]);
					}
                    
                    //cout<<A<<" "<<m<<" "<<D[m]<<" "<<arr[D[m]]<<endl;
    			}
    		}
    	}
    	print(max1);
    }
} 
