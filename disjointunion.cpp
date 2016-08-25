#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define gc getchar()
#define pc putchar
ll parent[100001]={0},size[100001]={0};
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
ll findParent(ll y) {
	while(y!=parent[y]) {
		y=parent[y];
	}
	return y;
}
void unionNodes(ll a,ll b,ll size[])
{
    ll parent_a=findParent(a),parent_b=findParent(b);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])//the larger connected component eats up the smaller one
    {
         size[parent_a]=(size[parent_a]+size[parent_b])%MOD;
         parent[parent_b]=parent_a;
         size[parent_b]=0;
    }
    else
    {
         size[parent_b]=(size[parent_b]+size[parent_a])%MOD;
         parent[parent_a]=parent_b;
         size[parent_a]=0;
    }
    return;
}
 
int main()
{
 
    ll N,M,i,a,b,t;
    read(t);
    while(t--)
	{
		read(N);read(M);
		for(i=1;i<=N;i++)
		{
		    parent[i]=i;
		    size[i]=1;
		}
	 
		for(i=1;i<=M;i++)
		{
		    //scan each edge and merge the connected components of the two nodes
		    read(a);read(b);
		    unionNodes(a,b,size);
		}
		ll p=1;
		ll nos=0;
		for(i=1;i<=N;i++)
		{
		    if(size[i])
		    {
		    	nos++;
		    	p=(p%MOD)*(size[i]%MOD)%MOD;
		    }
		}
		cout<<nos<<" "<<p<<endl;
 	}
    return 0;
}
