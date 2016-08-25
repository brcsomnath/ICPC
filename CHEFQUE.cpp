#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
#define pc putchar
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
bitset<2147483648> A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned int q,s,a,b; ll sum=0;
	cin>>q>>s>>a>>b;
	for(ll i=0;i<q;i++)
	{
		ll k=s>>1;
		if(s&1)
		{
			if(!A[k])
			{
				sum+=k;
				A.set(k);
			}
		}
		else
		{
			if(A[k])
			{
				sum-=k;
				A.reset(k);
			}
		}
		s=s*a+b;
	}
	print(sum);
}
