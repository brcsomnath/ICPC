#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll A,B;
		cin>>A>>B;
		ll tmp1=A,max1=0,a1=0,i;
		while(tmp1)
		{
			max1=max(max1,tmp1%10);
			tmp1/=10;
		}
		ll tmp2=B,max2=0,b1=0;
		while(tmp2)
		{
			max2=max(max2,tmp2%10);
			tmp2/=10;
		}
		tmp1=A,i=1;
		if(max1!=9)
		{
			while(tmp1){
				a1+=i*(tmp1%10);
				i*=(max1+1);
				tmp1/=10;
			}
		}
		else
			a1=A;
		tmp1=B,i=1;
		if(max2!=9)
		{
			while(tmp1){
				b1+=i*(tmp1%10);
				i*=(max2+1);
				tmp1/=10;
			}
		}
		else
			b1=B;
		cout<<(a1+b1)<<endl;
	}
}
