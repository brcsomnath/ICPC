#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int a[5000005];
int b[5000005];
void markMultiples(ll a1)
{
    ll i = 2, num;
    while ( (num = i*a1)<=5000000 )
    {
        a[ num-1 ] = 1;
        ++i;
    }
}
void markMultiples1(ll a1)
{
    ll i = 2, num;
    while ( (num = i*a1)<=5000000 )
    {
        b[ num ] = 1;
        ++i;
    }
}
void SieveOfEratosthenes()
{
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (ll i=1; i<=5000000; ++i)
        {
            if ( a[i] == 0 )
            {
                markMultiples(i+1);
                if(i>=4&&(i+1)%4==1)
                {
                    b[i+1]=1;
                    markMultiples1(i+1);
                }
            }
        }
}

int main()
{
    ofstream myfile;
    myfile.open ("output.cpp");
    SieveOfEratosthenes();
    myfile<<"#include <bits/stdc++.h>"<<endl;
    myfile<<"using namespace std;"<<endl;
    myfile<<"typedef long long ll;"<<endl;
    myfile<<"int main(){"<<endl;
    myfile<<"int a[]={"<<endl;
    for(ll i=2;i<=5000000;i++)
    {
        if(!a[i])
        myfile<<i<<",";
    }
    myfile<<"1};"<<endl;
    myfile<<"ll t;"<<endl;
    myfile<<"cin>>t;"<<endl;
    myfile<<"while(t--){"<<endl;
    myfile<<"ll n;"<<endl;
    myfile<<"cin>>n;"<<endl;
    myfile<<"if(a[n])"<<endl;
    myfile<<"cout<<\"YES\"<<endl;"<<endl;
    myfile<<"else"<<endl;
    myfile<<"cout<<\"NO\"<<endl;"<<endl;
    myfile<<"}"<<endl;
    myfile<<"}"<<endl;
    myfile.close();
}
