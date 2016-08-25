//Title of this code
//g++  4.9.2

#include <bits/stdc++.h>
#define gc getchar()
#define pc putchar
#define MOD 1000000007
#define REP(i,x,y) for(ll i=x;i<y;i++)
using namespace std;
typedef long long ll;

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
ll eqvcal(ll n)
{
	while(n>10)
	{
		ll s=0;
		while(n)
		{
			s+=(n%10);
			n=n/10;
		}
		n=s;
	}
	return n;
}
int main()
{
    ll t;
    read(t);
    while(t--)
    {
        ll a,d,l,r;
        read(a);read(d);read(l);read(r);
        ll al=a+(l-1)*d;
        ll aleq=eqvcal(al);
        ll deq=eqvcal(d);
        ll sum9=aleq,a1=aleq;
        REP(i,0,8)
        {
        	if((a1+deq)%9)
        		sum9+=(a1+deq)%9;
        	else
        		sum9+=9;
        	a1=(a1+deq)%9;
        }
        ll req=(r-l+1)%9;
        ll sumr=aleq;a1=aleq;
        if(req==0)
        	sumr=0;
        REP(i,0,req-1)
        {
        	if((a1+deq)%9)
        		sumr+=(a1+deq)%9;
        	else
        		sumr+=9;
        	a1=(a1+deq)%9;
        }
        req=(r-l+1);
        ll f=sum9*(req/9)+sumr;
        print(f);
    }
}
