#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5000005
bool v[MAX];
int len, sp[MAX];

void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (ll i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

int main(){
	Sieve();
	for (int i = 2; i < 5000005; i++)	cout << sp[i] << " ";

    return 0;
}
