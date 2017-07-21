#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
//莫比乌斯反演 + 容斥原理。。(省选出发前夜，为了平复自己退役的心情做了一些不会的题QAQ)
//By sssSSSay 
using namespace std;

const int Maxn = 100001;

typedef long long ll;

ll n, vis[Maxn], mu[Maxn], pri[Maxn];

void Mu() {
	mu[1] = 1;
	for(ll i = 2; i < Maxn; ++i) {
		if(!vis[i]) {
			pri[++pri[0]] = i;
			mu[i] = -1;
		}
		for(ll j = 1; j <= pri[0] && pri[j] * i < Maxn; ++j) {
			vis[pri[j] * i] = 1;
			if(i % pri[j] == 0) {
				mu[i * pri[j]] = 0;
				break;
			}
			else mu[i * pri[j]] = -mu[i];
		}
	}
}

ll Check(ll x) {
	ll s = 0; ll m = (ll)sqrt(x);
	for(ll i = 1; i <= m; ++i) s += mu[i] * (x /(i * i));
	return s;
}

ll Get(ll k) {
	ll l = 0, r = 2 * k, ans = 0;
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(Check(mid) < k) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return ans + 1;
}

int main() {
	scanf("%lld", &n);
	Mu();
	while(n--) {
		ll k;
		scanf("%lld", &k);
		printf("%lld\n", Get(k));
	}
	return 0;
}
