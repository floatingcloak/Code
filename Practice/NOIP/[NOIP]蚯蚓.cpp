#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 1000000000000007ll

using namespace std;

const int Maxn = 10101000;

typedef long long ll;

int n, m, tt, h[4], t[4];
ll c[Maxn], a[4][Maxn], u, v, q;

bool comp(ll a, ll b) {return a > b;}

int main() {
	// freopen("earthworm.in", "r", stdin);
	// freopen("earthworm.out", "w", stdout);
	scanf("%d%d%lld%lld%lld%d", &n, &m, &q, &u, &v, &tt);
	for(int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	sort(c + 1, c + n + 1, comp);
	for(int i = 1; i <= n; ++i) a[2][i] = c[i];
	h[1] = 1, h[2] = 1, h[3] = 1, t[1] = 0, t[2] = n, t[3] = 0;
	for(int i = 1; i <= m; ++i) {
		ll temp = -INF; int k = 0;
		for(int j = 1; j <= 3; ++j) if(h[j] <= t[j] && a[j][h[j]] > temp) temp = a[j][h[j]], k = j;
		if(i % tt == 0) printf("%lld ", temp + (1ll * i - 1) * q);
		ll l = (ll)((temp + (1ll * i - 1) * q) * u / v) - 1ll * i * q;
		ll r = temp + (1ll * i - 1) * q - (ll)(((temp + (1ll * i - 1) * q) * u / v)) - 1ll * i * q; 
		a[1][++t[1]] = l; a[3][++t[3]] = r; ++h[k];
	}
	puts("");
	for(int i = 1; i <= n + m; ++i) {
		ll temp = -INF; int k = 0;
		for(int j = 1; j <= 3; ++j) if(h[j] <= t[j] && a[j][h[j]] > temp) temp = a[j][h[j]], k = j;
		if(i % tt == 0) printf("%lld ", temp + 1ll * m * q);
		++h[k];
	}
	// for(;;);
	return 0;
}