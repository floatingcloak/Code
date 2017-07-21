#include <cstdio>
#include <cstring>
#include <iostream>
//¼ÇÒä»¯ËÑË÷
//By sssSSSay 
#define INF 2139062143

using namespace std;

const int Maxn = 110;

int n, dp[Maxn][Maxn];
char s[Maxn];

int Cal(int x) {
	int tot = 0;
	while(x) x /= 10, ++tot;
	return tot;	
}

bool Sur(int a, int b, int l, int r) {
	int i = a, j = l;
	while(i <= b) {
		if(s[i] != s[j]) return 0;
		++i, ++j;
	}
	return 1;
}

bool Judge(int a, int b, int r) {
	int len = (b - a + 1), pd = 1;
	for(int i = a; i + len - 1 <= r; i += len) {
		int j = i + len - 1;
		if(Sur(a, b, i, j) == 0) {pd = 0; break;}
	}
	return pd;
}

int Dp(int l, int r) {
	if(l == r) return 1;
	if(dp[l][r] != INF) return dp[l][r];
	dp[l][r] = r - l + 1;
	for(int k = l; k < r; ++k) {
		dp[l][r] = min(dp[l][r], Dp(l, k) + Dp(k + 1, r));
		if(((r - l + 1) % (k - l + 1)) == 0 && Judge(l,k,r)) dp[l][r] = min(dp[l][r], Dp(l, k) + Cal((r - l + 1) / (k - l + 1)) + 2);
	}
	return dp[l][r];
}

int main() {
	memset(dp, 127, sizeof(dp)); 
//	cout<<dp[0][0];
	scanf("%s", (s + 1));
	n = strlen(s + 1);
	printf("%d\n", Dp(1, n));
	return 0;
}
// NEERCYESYESYESNEERCYESYESYES
