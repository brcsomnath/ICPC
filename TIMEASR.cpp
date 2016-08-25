#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
    ll h1,h2;
    double d,m1,m2;
    ll min1,min2;
    cin>>d;
    map<double,int> a;
    map<int,int> b;
    for(double i=0;i<60;i++)
    {
      a[i]=1;
    }
    //30h-5.5m=d
    for(int i=0;i<12;i++)
    {
      if(30*i-d>=0)
      {
        m1=(30*i-d)/5.5;
        if(a[m1])
        {

          h1=i%12;
          min1=m1;
          min1=min1%60;
          min2=(60-min1);
          h2=(11-h1+min2/60)%12;
          min2=min2%60;
          b[h1]=min1+1000;
          b[h2]=min2+1000;
          if(h1==h2&&min1==min2)
          {
            cout<<(h1/10)<<(h1%10)<<":"<<(min1/10)<<(min1%10)<<endl;
          }
          else
          {
            ll t1=h1*60+min1;
            ll t2=h2*60+min2;
            if(t1<t2)
            {
              cout<<(h1/10)<<(h1%10)<<":"<<(min1/10)<<(min1%10)<<endl;
              cout<<(h2/10)<<(h2%10)<<":"<<(min2/10)<<(min2%10)<<endl;
            }
            else
            {
              cout<<(h2/10)<<(h2%10)<<":"<<(min2/10)<<(min2%10)<<endl;
              cout<<(h1/10)<<(h1%10)<<":"<<(min1/10)<<(min1%10)<<endl;
            }
          }
        }
      }
    }
    d=360-d;
    for(int i=0;i<12;i++)
    {
      if(30*i-d>=0)
      {
        m1=(30*i-d)/5.5;
        h1=i%12;
        min1=m1;
        min1=min1%60;
        min2=(60-min1);
        h2=(11-h1+min2/60)%12;
        min2=min2%60;
        if(a[m1]&&b[h1]!=min1+1000&&b[h2]!=min2+1000)
        {
          b[h1]=min1+1000;
          b[h2]=min2+1000;
          cout<<"*";
          if(h1==h2&&min1==min2)
          {
            cout<<(h1/10)<<(h1%10)<<":"<<(min1/10)<<(min1%10)<<endl;
          }
          else
          {
            ll t1=h1*60+min1;
            ll t2=h2*60+min2;
            cout<<t1;
            if(t1<t2)
            {
              cout<<(h1/10)<<(h1%10)<<":"<<(min1/10)<<(min1%10)<<endl;
              cout<<(h2/10)<<(h2%10)<<":"<<(min2/10)<<(min2%10)<<endl;
            }
            else
            {
              cout<<(h2/10)<<(h2%10)<<":"<<(min2/10)<<(min2%10)<<endl;
              cout<<(h1/10)<<(h1%10)<<":"<<(min1/10)<<(min1%10)<<endl;
            }
          }
        }
      }
    }
  }
}
