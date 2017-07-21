#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF -2139062144

using namespace std;

const int Maxn = 2050;

typedef long long ll;

ll a[Maxn], n, ans, f[Maxn][Maxn], g[Maxn][Maxn], h[Maxn][Maxn];

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
//	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		++f[i][a[i]];
		for(int j = 0; j < 1024; ++j) {
			f[i][j] += f[i - 1][j];
			f[i][j ^ a[i]] += f[i - 1][j];
		}
	}
	for(int i = n; i >= 1; --i) {
		++g[i][a[i]];
		++h[i][a[i]];
		for(int j = 0; j < 1024; ++j) {
			g[i][j] += g[i + 1][j];
			g[i][j & a[i]] += g[i + 1][j];
			h[i][j & a[i]] += g[i + 1][j];
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 1024; ++j) {
			ans += f[i][j] * h[i + 1][j];
		}
	}
	cout << ans << endl;
	return 0;
}
