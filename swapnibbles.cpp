#include <bits/stdc++.h>
using namespace std;
int swapNibble(int n)
{
  int set1=(n&0xF0)>>4;
  int set2=(n&0x0F)<<4;
  return (set1|set2);
}
int main()
{
  int n;
  cin>>n;
  cout<<swapNibble(n);
}
