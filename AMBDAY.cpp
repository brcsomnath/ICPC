#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define gc getchar()
#define pc putchar
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
	ll a[100005];
	memset(a,1,sizeof(a));
	a[0]=1;
	for(ll i=1;i<=5000;i++)
	{
		a[i]=((a[i-1]%MOD)*26)%MOD;
	}
	ll t;
	read(t);
	while(t--)
	{
		ll n,sum=0;
		read(n);
		for(ll i=1;i<=n;i++)
		{
			sum=(sum+a[i]*(1+2*i*(n-i)))%MOD;
		}
		print(sum);
	}
}
