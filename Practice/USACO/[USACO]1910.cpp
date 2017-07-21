#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 2010, N = 101;

int dp[Maxn][Maxn];
int n, m, x, v[N], c[N], w[N];

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &v[i], &c[i], &w[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = m; j >= 0; --j) {
			for(int k = x; k >= 0; --k) {
				if(j >= c[i] && k >= w[i]) {
					dp[j][k] = max(dp[j][k], dp[j - c[i]][k - w[i]] + v[i]);
				}
			}
		}
	}
	printf("%d\n", dp[m][x]);
	return 0;
}
