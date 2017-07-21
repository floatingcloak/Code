#include <cstdio>
#include <cstring>
#include <iostream>

#define mod 100000000ll

using namespace std;

const int Maxn = 15;

typedef long long ll;

int n, m, all, a[Maxn][Maxn];
ll dp[Maxn][4500];

bool Check(int level, int s) {
	for(int i = 1; i < m; ++i) {
		int k = s & (1 << (i - 1));
		int k1 = s & (1 << (i));
		if(k != 0 && a[level][i] == 0) return false;
		if(k1 != 0 && a[level][i + 1] == 0) return false;
		if(k != 0 && k1 != 0) return false;
	}
	return true;
}

bool Can(int l, int s, int w) {
	if(!Check(l - 1, s)) return false;
	if(!Check(l, w)) return false;
	for(int i = 1; i <= m; ++i) {
		int k1 = s & (1 << (i - 1));
		int k2 = w & (1 << (i - 1));
		if(k1 != 0 && k2 != 0) return false;	
	}
	return true;
}

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d", &n, &m);
	all = (1 << m) - 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);	
	}
	if(n == 1 && m == 1) {
		cout << 1 << endl;
		return 0;	
	}
	dp[0][0] = 1ll;
	for(int k = 1; k <= n; ++k) {
		for(int i = 0; i <= all; ++i) {
			for(int j = 0; j <= all; ++j) {
				if(Can(k, i, j)) {
					(dp[k][j] += dp[k - 1][i]) %= mod;
				}
			}
		}
	}
//	for(int i = 0; i <= all; ++i) {
//		printf("dp[%d][%d] = %d\n", 1, i, dp[1][i]);
//	}
//	cout << Can(2, 2, 2) << endl;
	ll ans = 0;
	for(int i = 0; i <= all; ++i) (ans += dp[n][i]) %= mod;
//	for(int i = 0; i <= all; ++i) ans = max(ans, dp[n + 1][i]);
	printf("%lld\n", ans);
	return 0;
}
