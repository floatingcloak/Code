#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define eps 1e-10

using namespace std;

const int Maxn = 21;

int T, n, m, g[Maxn][Maxn], dp[1 << 20];
long double x[Maxn], y[Maxn];

bool Comp(long double a, long double b) {
	return fabs(b - a) < eps;
}

void Add(int &x, int w) {
	x |= (1 << (w - 1));
}

int main() {
	freopen("angrybirds.in", "r", stdin);
	freopen("angrybirds.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		memset(g, 0, sizeof g);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
		for(int i = 1; i <= n; ++i) Add(g[i][i], i);
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				long double y11 = y[i], y22 = y[j], x11 = x[i], x22 = x[j];
				long double a = (x22 * y11 - x11 * y22) / (x11 * x22 * (x11 - x22));
				long double b = (y11 - a * x11 * x11) / x11;
				if(a >= -eps) continue; // 这里必须卡一下
				for(int k = 1; k <= n; ++k) if(Comp(y[k], a * x[k] * x[k] + b * x[k])) Add(g[i][j], k);
			}
		}
		int all = (1 << n) - 1;
		for(int i = 1; i <= n; ++i) {
			for(int j = i; j <= n; ++j) g[i][j] ^= all;
		}
		memset(dp, 127, sizeof dp); dp[0] = 0;
		for(int s = 1; s <= all; ++s) {
			int t = 0, w = s, i = 0;
			while(w) {++t; if(w & 1) {i = t; break;} w >>= 1;}
			for(int j = 1; j <= i; ++j) dp[s] = min(dp[s & g[j][i]] + 1, dp[s]);
			for(int j = i; j <= n; ++j) dp[s] = min(dp[s & g[i][j]] + 1, dp[s]);
		}
		printf("%d\n", dp[all]);
	}
	// for(;;);
	return 0;
}