#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <bitset>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
 
 
unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}
 
const int MaxK = 10;
 
struct Node {
	Node *left, *right;
	int size;
	int val;
	int cnts[MaxK];
	bool rev;
	Node(): left(NULL), right(NULL), size(1), val(-1), rev(false) { }
	inline Node *update() {
		size = (!left ? 0 : left->size) + 1 + (!right ? 0 : right->size);
		if(!left && !right) {
			mset(cnts, 0);
		} else if(!left || !right) {
			memcpy(cnts, (!left ? right : left)->cnts, sizeof(int) * MaxK);
		}else {
			memcpy(cnts, left->cnts, sizeof(int) * MaxK);
			ll *p = (ll*)cnts; const ll *q = (const ll*)right->cnts;
			p[0] += q[0];
			p[1] += q[1];
			p[2] += q[2];
			p[3] += q[3];
			p[4] += q[4];
		}
		++ cnts[val];
		return this;
	}
	inline void propagate() {
		if(rev) {
			if(left) left->rev = !left->rev;
			if(right) right->rev = !right->rev;
			swap(left, right);
			rev = false;
		}
	}
	inline Node *linkl(Node *c) {
		left = c;
		return update();
	}
	inline Node *linkr(Node *c) {
		right = c;
		return update();
	}
	inline Node *linklr(Node *l, Node *r) {
		left = l, right = r;
		return update();
	}
private:
	inline Node *derived() { return static_cast<Node*>(this); }
};
 
struct RBST {
	typedef Node *Ref;
	static int size(Ref t) { return !t ? 0 : t->size; }
	static const int MaxHeight = 32 * 4;
	static Ref join(Ref l, Ref r) {
		if(!l) return r;
		if(!r) return l;
		if((int)(xor128() % (l->size + r->size)) < l->size) {
			l->propagate();
			return l->linkr(join(l->right, r));
		}else {
			r->propagate();
			return r->linkl(join(l, r->left));
		}
	}
	typedef pair<Ref,Ref> RefPair;
	static RefPair split(Ref t, int k) {
		if(!t) return RefPair((Ref)NULL, (Ref)NULL);
		t->propagate();
		int s = size(t->left);
		if(k <= s) {
			RefPair p = split(t->left, k);
			return RefPair(p.first, t->linkl(p.second));
		}else {
			RefPair p = split(t->right, k - s - 1);
			return RefPair(t->linkr(p.first), p.second);
		}
	}
	template<typename It> static Ref fromList(It b, It e) {
		int n = e - b;
		if(n == 0) return NULL;
		It m = b + n / 2;
		Ref l = fromList(b, m);
		Ref r = fromList(m+1, e);
		return (*m).linklr(l, r);
	}
};
 
template<typename T>T gcd(T x, T y){if(y==0)return x;else return gcd(y,x%y);}
 
struct Query {
	int ty, l, r, x;
};
 
inline void bitShiftOr(unsigned *xs, int n, const unsigned *ys, int shift) {
	xs += shift / 32, n -= shift / 32, shift %= 32;
	if(n <= 0) return;
	if(shift == 0) {
		for(int i = n - 1; i >= 0; -- i)
			xs[i] |= ys[i];
		return;
	}
	xs[n - 1] |= ys[n - 1] << shift;
	for(int i = n - 2; i >= 0; -- i) {
		unsigned y = ys[i];
		xs[i] |= y << shift;
		xs[i + 1] |= y >> (32 - shift);
	}
}
 
int main() {
	int N, Q;
	while(~scanf("%d%d", &N, &Q)) {
		vector<int> initws(N);
		for(int i = 0; i < N; ++ i)
			scanf("%d", &initws[i]);
		vector<Query> queries(Q);
		rep(ii, Q) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int i, x;
				scanf("%d%d", &i, &x), -- i;
				Query q = { ty, i, i + 1, x };
				queries[ii] = q;
			} else if(ty == 2) {
				int l, r;
				scanf("%d%d", &l, &r), -- l;
				Query q = { ty, l, r, -1 };
				queries[ii] = q;
			} else if(ty == 3) {
				int l, r, W;
				scanf("%d%d%d", &l, &r, &W), -- l;
				Query q = { ty, l, r, W };
				queries[ii] = q;
			} else abort();
		}
		vi weights = initws;
		each(i, queries) if(i->ty == 1)
			weights.push_back(i->x);
 
		sort(weights.begin(), weights.end());
		weights.erase(unique(weights.begin(), weights.end()), weights.end());
 
		int K = weights.size();
		if(K > 10) return 1;
 
		vector<Node> nodes(N);
		rep(i, N) {
			int w = lower_bound(weights.begin(), weights.end(), initws[i]) - weights.begin();
			nodes[i].val = w;
			nodes[i].update();
		}
		Node *t = RBST::fromList(nodes.begin(), nodes.end());
		rep(ii, Q) {
			Query q = queries[ii];
			int ty = q.ty;
			if(ty == 1) {
				int i = q.l, x = lower_bound(weights.begin(), weights.end(), q.x) - weights.begin();
				RBST::RefPair p = RBST::split(t, i+1);
				RBST::RefPair q = RBST::split(p.first, i);
				q.second->val = x;
				q.second->update();
				t = RBST::join(RBST::join(q.first, q.second), p.second);
			} else if(ty == 2) {
				int l = q.l, r = q.r;
				RBST::RefPair p = RBST::split(t, r);
				RBST::RefPair q = RBST::split(p.first, l);
				q.second->rev = !q.second->rev;
				t = RBST::join(RBST::join(q.first, q.second), p.second);
			} else if(ty == 3) {
				int W = q.x;
				vpii cnts;
				{
					int l = q.l, r = q.r;
					RBST::RefPair p = RBST::split(t, r);
					RBST::RefPair q = RBST::split(p.first, l);
					rep(k, MaxK) if(q.second->cnts[k] > 0)
						cnts.push_back(mp(weights[k], q.second->cnts[k]));
					t = RBST::join(RBST::join(q.first, q.second), p.second);
				}
				unsigned dp[100000 / 32 + 2], t[100000 / 32 + 2];
				int B = (W + 32) / 32;
				memset(dp, 0, B * 4);
				dp[0] = 1;
				each(i, cnts) {
					int x = i->first, n = i->second;
					memcpy(t, dp, B * 4);
					int s = x, u = x;
					while(1) {
						if(n & 1) {
							bitShiftOr(dp, B, t, u);
							u += s;
							if(u > W) break;
						}
						n >>= 1;
						if(n > 0) {
							if(s <= W) {
								bitShiftOr(t, B, t, s);
								s *= 2;
							}
						} else {
							break;
						}
					}
				}
				bool ans = dp[W / 32] >> (W % 32) & 1;
				puts(ans ? "Yes" : "No");
			} else {
				abort();
			}
		}
	}
	return 0;
}
