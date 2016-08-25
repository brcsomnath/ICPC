#include<bits/stdc++.h>
using namespace std;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
 
char str[1000][1000];
 
int dist(int x, int y)
{
    return (x+y);
}
 
int main()
{
    int N, i, j, k, l, m, ans;
 
    while(scanf("%d",&N)==1)
    {
        getchar();
 
        for(i=0;i<N;i++) 
            gets(str[i]);
 
        ans = 0;
 
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(str[i][j]=='1')
                {
                    m = 10000;
 
                    for(k=0;k<N;k++)
 
                        for(l=0;l<N;l++)
 
                            if(str[k][l]=='3')
 
                                m = MIN(m,dist(abs(i-k),abs(j-l)));
 
                    ans = MAX(ans,m);
                }
            }
        }
 
        printf("%d\n",ans);
 
    }
 
  return 0;
}
