#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define LSOne(S) (S & (-S))
ll B1[100005], B2[100005];
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
int N;
ll query(ll* ft, int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}
void update(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}

void range_update(int i, int j, ll v)	{
	update(B1, i, v);
	update(B1, j + 1, -v);
	update(B2, i, v * (i - 1));
	update(B2, j + 1, -v * j);
}

int main()  {
	ll n,m,k;
	read(n);read(m);read(k);
	
    return 0;
}
