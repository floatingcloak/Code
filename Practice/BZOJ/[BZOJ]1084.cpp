#include <cstdio>
#include <cstring>
#include <iostream>
//Dp...
//By sssSSSay 
using namespace std;

const int Maxn = 110;

int a[Maxn][5], dp[Maxn][12][2], n, m, k;
int f[Maxn][Maxn][12], sum[Maxn][2];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			sum[i][j] = sum[i - 1][j] + a[i][j];
		}
	}
	if(m == 1) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= k; ++j) {
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
				dp[i][j][1] = max(dp[i - 1][j - 1][0] + a[i][1], dp[i - 1][j][1] + a[i][1]);
			}
		}
		printf("%d\n", max(dp[n][k][1], dp[n][k][0]));
	}
	else {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				for(int l = 1; l <= k; ++l) {
					f[i][j][l] = max(f[i - 1][j][l], f[i][j - 1][l]);
					for(int p = 1; p <= i; ++p) f[i][j][l] = max(f[i][j][l], f[i - p][j][l - 1] + sum[i][1] - sum[i - p][1]);
					for(int p = 1; p <= j; ++p) f[i][j][l] = max(f[i][j][l], f[i][j - p][l - 1] + sum[j][2] - sum[j - p][2]);
					if(i == j) {
						for(int p = 1; p <= i; ++p) {
							f[i][j][l] = max(f[i][j][l], f[i - p][j - p][l - 1] + sum[i][1] - sum[i - p][1] + sum[i][2] - sum[i - p][2]);	
						}
					}
				}
			}
		}
		printf("%d\n",f[n][n][k]);
	}
	return 0;
}

