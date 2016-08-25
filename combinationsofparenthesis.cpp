#include <bits/stdc++.h>
using namespace std;
void _printparenthesis(int pos,int n,int open,int close)
{
  static char s[1000];
  if(close==n)
  {
    printf("%s\n", s);
    return;
  }
  else
  {
    if(open>close)
    {
      s[pos]='}';
      _printparenthesis(pos+1,n,open,close+1);
    }
    if(open<n)
    {
      s[pos]='{';
      _printparenthesis(pos+1,n,open+1,close);
    }
  }
}
void printparenthesis(int n) {
  if(n>0)
  _printparenthesis(0,n,0,0);
  else
  return;
}
int main()
{
  int n;
  cin>>n;
  printparenthesis(n);
}
