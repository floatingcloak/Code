#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 201000;

int n, m, k, fa[Maxn], sum[Maxn], w[Maxn], t, dp[Maxn];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1, x, y; i <= k; ++i) {
		scanf("%d%d", &x, &y);
		int r1 = find(x), r2 = find(y);
		if(r1 != r2) {
			fa[r2] = r1;
		}
	}
	for(int i = 1; i <= n; ++i) ++sum[find(i)];
	for(int i = 1; i <= n; ++i) {
		if(sum[i]) w[++t] = sum[i];
	}
	for(int i = 1; i <= t; ++i) {
		for(int j = 2 * m; j >= w[i]; --j) dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
	}
	if(dp[m] == m) {
		printf("%d\n", m);
		return 0;
	}
	for(int i = 1; i <= m; ++i) {
		if(dp[m - i] == m - i) {
			printf("%d\n", m - i);
			return 0;
		}
		if(dp[m + i] == m + i) {
			printf("%d\n", m + i);
			return 0;
		}
	}
	// for(;;);
	return 0;
}