#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 210;

int m, v, n, a[Maxn], b[Maxn], c[Maxn], pre[Maxn][Maxn][Maxn], dp[Maxn][Maxn], tot[Maxn][Maxn];

int main() {
	scanf("%d%d%d", &m, &v, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = m; j >= a[i]; --j) {
			for(int k = v; k >= b[i]; --k) {
				if(dp[j - a[i]][k - b[i]] + c[i] > dp[j][k]) {
					dp[j][k] = dp[j - a[i]][k - b[i]] + c[i];
					tot[j][k] = tot[j - a[i]][k - b[i]] + 1;
					for(int l = 1; l <= tot[j - a[i]][k - b[i]]; ++l) pre[j][k][l] = pre[j - a[i]][k - b[i]][l];
					pre[j][k][tot[j][k]] = i;
				}
			}
		}
	}
	printf("%d\n", dp[m][v]);
	for(int i = 1; i <= tot[m][v]; ++i) {
		printf("%d ", pre[m][v][i]);
	}
	return 0;
}