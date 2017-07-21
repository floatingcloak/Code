#include <cstdio>
#include <cstring>
#include <iostream>
//状压Dp。。不是特别难？
//By sssSSSay 
using namespace std;

const int Maxn = 2010;

int T,d,dp[Maxn][Maxn],cnt[Maxn];
char str[Maxn];

int Jc(int x, int temp = 1) {for(int i = 2; i <= x; ++i) temp *= i; return temp;}

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(dp, 0, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		scanf("%s%d", &str, &d);
		int s = strlen(str);
		for(int i = 0; i < s; ++i) ++cnt[str[i]];
		int all = (1 << s) - 1;
		dp[0][0] = 1;
		for(int i = 0; i <= all; ++i) {
			for(int j = 0 ; j < d; ++j) {
				if(dp[i][j]) {
					for(int k = 0; k < s; ++k) {
						if(!(i & (1 << k))) {
							dp[i | (1 << k)][(j * 10 + (str[k] - '0')) % d]	+= dp[i][j];
						}
					}
				}
			}
		}
		for(int i = 0; i < s; ++i) {
			dp[all][0] /= Jc(cnt[str[i]]);
			cnt[str[i]] = 0;
		}
		printf("%d\n",dp[all][0]);
	}
	return 0;
}
