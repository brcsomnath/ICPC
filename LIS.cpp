//Title of this code
//g++  4.9.2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll  n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    set<ll> s;
    set<ll>::iterator it;
    s.clear();
    for(ll i=0;i<n;i++)
    {
        s.insert(a[i]);
        it=s.find(a[i]);
        it++;
        if(it!=s.end())
        {
            cout<<"Erase "<<*it<<" "<<i<<endl;
            s.erase(it);
        }
    }
    cout<<s.size()<<endl;
}
