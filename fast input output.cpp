#include<bits/stdc++.h>
#define gc getchar()
#define pc putchar
#define mod 1000000007
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
	pc(' ');
}

int main()
{
    ll t,n,k,sum=0;
    read(t);
    read(k);
    while(t--)
    {
        ll n;
        read(n);
        if(n%k==0)
         sum++;
    }
    print(sum);
    return 0;
}
