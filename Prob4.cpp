

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair<double,double> dd;
#define gc getchar()
#define pc putchar
#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 5000000
#define debug cout<<"A"<<endl
#define prnt(a) cout<<a<<endl
#define MOD 1000000009
#define epsilon 1e-6
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define FORr(i,a,b) for (ll i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define D(x) cout << #x " is " << x << endl

int d[1<<15], suiche[40];

int main()
{


    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=0, k, x; i<m; ++i){
      suiche[i] = 0;
      scanf("%d", &k);
      while (k--){
        scanf("%d", &x);
        suiche[i] |= (1 << x);
      }
    }

    for (int i=0; i<(1<<n); ++i) d[i] = INT_MAX;
    queue<int> q;
    d[0] = 0;
    q.push(0);

    while (q.size())
    {
      int u = q.front(); q.pop();
      for (int k=0; k<m; ++k)
      {
        int v = u ^ suiche[k]; //Toggles lights
        if (d[u] + 1 < d[v])
        {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }

    }

    int queries;
    scanf("%d", &queries);
    while (queries--)
    {
      int destiny = 0;
      char buf[16];
      scanf("%s", buf);
      for (int i=n-1; i>=0; --i)
      {

        int bit = buf[i] - '0';
        destiny |= (bit << (n - i - 1));
      }
      printf("%d\n", d[destiny] < INT_MAX ? d[destiny] : -1);
    }
  return 0;
}
