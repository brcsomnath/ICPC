#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
ll gcd(ll a, ll b)
{
  if (a == 0)
    return b;
  return gcd(b%a, a);
 
}
inline ll in()
{
  ll n=0;
  char c=getchar_unlocked();
  while(c<'0' || c>'9')
  c=getchar_unlocked();
  while(c<='9' && c>='0')
  {
  n=(n<<1)+(n<<3)+c-'0';
  c=getchar_unlocked();
  }
  return n;
}

inline void in2(ll &n)  //pass an integer by value
{
  n = 0;
  ll ch = getchar_unlocked();
  ll sign = 1;
 
  while (ch<'0' || ch>'9')  // if the input character is not a digit
  {
    if (ch == '-')
    {
      sign = -1;
    }
    ch = getchar_unlocked();
  }
 
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';  //multiply by 10
    ch = getchar_unlocked();
  }
  
  n *= sign;  // for negative numbers
}
 
int main(){
 
  ll t,n,a[100002][3],i,ans,count,m,count0,count1,k,x[100002];
  double s[100002],index[100002],y[100002];
  t=in();
  while(t--){
    n=in();
    count0=count1=0;
    for(i=0;i<n;i++){
      in2(a[i][0]);
      in2(a[i][1]);
      in2(a[i][2]);
      ans=__gcd(__gcd(a[i][0],a[i][1]),a[i][2]);
      a[i][0]/=ans;
      a[i][1]/=ans;
      a[i][2]/=ans;
    }
    k=0;
    for(i=0;i<n;i++){
      if(a[i][1]!=0){
          s[k]=double(double((a[i][0])*-1)/double(a[i][1]));
          k++;
      }
    }
    k=0;
    for(i=0;i<n;i++){
      if(a[i][1]!=0){
          index[k]=double(double((a[i][2])*-1)/double(a[i][1]));
          k++;  
      }
    }
    
    vector<pair<double,double> >v;
    for(i=0;i<k;i++){
      v.push_back(make_pair(s[i],index[i]));
    }
    sort(v.begin(),v.end());
    /*for(i = 0; i < n; i++)
  {
      cout << v[i].first << ", " << v[i].second << endl;
  }*/
    count=1;m=-1;
    for(i=0;i<k-1;i++)
    {
      if(v[i].first==v[i+1].first)
      {
        if(v[i].second!=v[i+1].second)
          count++;
      }
      else
      {
        if(m<count)
          m=count;
        count=1;
      }
    }
    if(m<count)
          m=count;
    k=0;
    for(i=0;i<n;i++){
      if(a[i][1]==0){
        y[k]=double(double(a[i][2])/double(a[i][0]));
        //cout<<y[k]<<endl;
        k++;
      }
    }
    sort(y,y+k);
    count0=1;
    for(i=0;i<k-1;i++){
    cout<<y[i]<<" ";
      if(y[i]!=y[i+1])
        count0++;
    }
   
    //cout<<m<<" "<<k<<endl;
  }
}
