#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define mod 12345678

using namespace std;

const int Maxn = 155;

int n,m,c,dp[Maxn * 2][Maxn][25][25];

int main(){
	scanf("%d%d%d",&n,&m,&c);
	dp[0][0][0][0] = 1;
	for(int i = 0;i <= n + m; ++i) {
		for(int j = 0;j <= n; ++j) {
			for(int k = 0;k <= c; ++k) {
				for(int l = 0;l <= c; ++l) {
					if(dp[i][j][k][l]) {
						if(j + 1 <= n && k + 1 <= c) {
							(dp[i + 1][j + 1][k + 1][max(0,l - 1)] += dp[i][j][k][l]) %= mod;
						}
						if(i - j + 1 <= m && l + 1 <= c) {
							(dp[i + 1][j][max(0,k - 1)][l + 1] += dp[i][j][k][l]) %= mod;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= c; ++i) {
		for(int j = 0;j	<= c; ++j) {
			(ans += dp[n + m][n][i][j]) %= mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
