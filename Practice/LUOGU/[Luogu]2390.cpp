#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 1000000007

using namespace std;

typedef long long ll;

const int Maxn = 101111;

ll t, n, t1, t2, a[Maxn], b[Maxn], c[Maxn], sc[Maxn], sb[Maxn];

bool Check(ll x, ll temp = INF) {
	for(ll r = 0; r <= min(t2, x); ++r) {
		ll l = x - r; if(l > t1) continue;
		if(r == 0) temp = min(temp, b[l]);
		else if(r == x) temp = min(temp, c[r]);
		else temp = min(temp, b[l] + c[r] + min(b[l], c[r]));
	}
	return temp <= t;
}

bool comp(ll a, ll b) {return a > b;}

int main() {
	scanf("%lld%lld", &t, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if(a[i] < 0) b[++t1] = a[i];
		else c[++t2] = a[i];
	}
	sort(b + 1, b + t1 + 1, comp);
	sort(c + 1, c + t2 + 1);
	for(int i = 1; i <= t1; ++i) b[i] = -b[i];
	ll l = 1, r = n, ans = 0;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		if(Check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	for(;;);
	return 0;
}