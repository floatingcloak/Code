#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 10100;

int n, k, dp[Maxn], ans[Maxn], res, b[Maxn];

int Cal(int x, int sum) {
	memset(dp, 127, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= x; ++i) {
		for(int j = b[i]; j <= n * sum; ++j) {
			dp[j] = min(dp[j], dp[j - b[i]] + 1);
		}
	}
	for(int i = 0; i <= n * sum; ++i) {
		if(dp[i] > n) return i - 1;
	}
	return n * sum;
}

void Dfs(int x, int l, int r, int sum) {
	if(x == k + 1) {
		if(r > res) {
			res = r;
			for(int i = 1; i <= k; ++i) ans[i] = b[i];
		}
		return;
	}
	for(int i = l + 1; i <= r + 1; ++i) {
		b[x] = i;
		Dfs(x + 1, i, Cal(x, sum + i), sum + i);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	Dfs(1, 0, 0, 0);
	sort(ans + 1, ans + k + 1);
	for(int i = 1; i <= k; ++i) printf("%d ", ans[i]);
	printf("\nMax=%d\n", res);
	// for(;;);
	return 0;
}