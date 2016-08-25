#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		ll n;
		cin>>n;
		ll arr[2*n+1];
		map<ll,ll> A;
		map<ll,ll> B;
		for(ll j=0;j<2*n;j++)
		{
			cin>>arr[j];
			if(j<n)
			A[arr[j]]++;
			else
			B[arr[j]]++;
		}
		sort(arr,arr+2*n);
		ll sum=0,k=0,j=0;
		/*for(j=0;j<2*n;j++)
		{
			cout<<arr[j]<<" "<<A[arr[j]]<<endl;
		}*/
		while(k<2*n&&j<2*n)
		{
			//cout<<arr[k]<<" "<<arr[j]<<" "<<sum<<"\n";
			while(A[arr[k]]==0&&k<2*n)k++;
			while(B[arr[j]]==0&&j<2*n)j++;
			if(j>2*n||k>2*n)break;
			sum+=abs(arr[k]-arr[j]);
			A[arr[k]]--;
			B[arr[j]]--;
			k++,j++;
		}
		cout<<"Case "<<i<<": "<<sum<<"\n";
	}
}
