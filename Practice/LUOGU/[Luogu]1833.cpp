#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

int h1, m1, m, n, dp[Maxn][Maxn], h2, m2, t[Maxn], v[Maxn], k[Maxn];

int main() {
	scanf("%d:%d", &h1, &m1); scanf("%d:%d", &h2, &m2);
	int m = h2 * 60 + m2 - h1 * 60 - m1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d%d%d", &t[i], &v[i], &k[i]);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			dp[i][j] = dp[i - 1][j];
			if(k[i] != 0) {
				for(int l = 1; l * t[i] <= j && l <= k[i]; ++l) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - l * t[i]] + l * v[i]);
				}
			}		
			else {
				for(int l = 1; l * t[i] <= j; ++l) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - l * t[i]] + l * v[i]);
				}
			}
		}
	}
	cout << dp[n][m] << endl;
	// for(;;);
	return 0;
}