#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1010100;

typedef long long ll;

map <ll, int> hs;

struct node {
	ll v, x;
} a[Maxn];

ll n, tCnt[Maxn];
ll tSum[Maxn], ans;

bool comp1(node a, node b) {return a.v < b.v;}

bool comp2(node a, node b) {return a.x < b.x;}

ll absmy(ll x) {return x > 0 ? x : -x;}

void AddCnt(ll x) {
	for(ll i = x; i <= n; i += (i & (-i))) ++tCnt[i];
}

void AddSum(ll x, ll s) {
	for(ll i = x; i <= n; i += (i & (-i))) tSum[i] += s;
}

ll QueryCnt(ll x,ll temp = 0) {
	for(ll i = x; i; i -= (i & (-i))) temp += tCnt[i];
	return temp;
}

ll QuerySum(ll x, ll temp = 0) {
	for(int i = x; i; i -= (i & (-i))) temp += tSum[i];
	return temp;
}

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].v, &a[i].x);
	sort(a + 1, a + n + 1, comp1);
	for(int i = 1; i <= n; ++i) hs[a[i].v] = i;
	sort(a + 1, a + n + 1, comp2);
	for(int i = 1; i <= n; ++i) {
		ll vv = hs[a[i].v];
		ll k = QueryCnt(vv); ll s = QuerySum(vv);
		ans += a[i].v * absmy(s - 1ll * k * a[i].x);
		AddCnt(vv); AddSum(vv, a[i].x);
	}
	memset(tCnt, 0, sizeof tCnt); memset(tSum, 0, sizeof tSum);
	for(int i = n; i >= 1; --i) {
		ll vv = hs[a[i].v];
		ll k = QueryCnt(vv - 1); ll s = QuerySum(vv - 1);
		ans += a[i].v * absmy(s - 1ll * k * a[i].x);
		AddCnt(vv); AddSum(vv, a[i].x);
	}
	printf("%lld\n", ans);
	// for(;;);
	return 0;
}