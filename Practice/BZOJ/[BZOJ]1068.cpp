#include <cstdio>
#include <cstring>
#include <iostream>
//我想不出来的区间Dp
//By sssSSSay
using namespace std;

const int Maxn = 110;

int dp[Maxn][Maxn][2];
char s[Maxn];

bool Judge(int x,int y) {
	if((y - x + 1) & 1) return 0;
	int k = (x + y) >> 1;
	for(int i = x; i <= k; ++i) {
		int j = k + (i - x) + 1;
		if(s[i] != s[j]) return 0;
	}
	return 1;
}

int main() {
//	freopen("test.in","r",stdin);
	scanf("%s",(s + 1));
	int len = strlen(s + 1);
	for(int i = 1; i <= len; ++i) {
		for(int j = i; j >= 1; --j) {
			dp[j][i][1] = dp[j][i][0] = i - j + 1;
			for(int k = j; k < i; ++k) {
				dp[j][i][1] = min(dp[j][i][1], min(dp[j][k][1], dp[j][k][0]) + min(dp[k + 1][i][1], dp[k + 1][i][0]) + 1);
			}
			for(int k = j; k < i; ++k) {
				dp[j][i][0] = min(dp[j][i][0], dp[j][k][0] + i - k);	
			}
			if(Judge(j, i)) dp[j][i][0] = dp[j][(j + i) >> 1][0] + 1;
			if(i - j + 1 == 1) dp[j][i][1] = len + 1;
		}
	}
	printf("%d\n",min(dp[1][len][0], dp[1][len][1]));
	return 0;
}
