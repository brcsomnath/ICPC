//Title of this code
//g++  4.9.2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,p,q;
    cin>>n>>p>>q;
    string s;
    cin>>s;
    if(n==(p+q))
    {
        string s1,s2;
        s1=s.substr(0,p);
        s2=s.substr(p,q);
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    else if(n==2*p)
    {
        string s1,s2;
        s1=s.substr(0,p);
        s2=s.substr(p,p);
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    else if(n==2*q)
    {
        string s1,s2;
        s1=s.substr(0,q);
        s2=s.substr(q,q);
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
        
}
