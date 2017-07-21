#include <cstdio>
#include <cstring>
#include <iostream>

#define mod 1e9 + 7

using namespace std;

const int Maxn = 80;

typedef long long ll;

int k, n, a[Maxn];
ll c[Maxn][Maxn];
ll f[Maxn];

void Solve() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j == 0) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i) {
		scanf("%d", &a[i]);
		n += a[i];
	}
	Solve();
	f[0] = 1;
	for(int i = 1; i <= n; ++i) f[i] = (f[i - 1] * i) % mod;
	ll all = f[n];
	ll ans = 0;
	for(int i = 1; i <= k; ++i) {
		ll now = c[a[i]][2] * (n - c[i] + 1) * (n - c[i]);
	}
	return 0;
}
