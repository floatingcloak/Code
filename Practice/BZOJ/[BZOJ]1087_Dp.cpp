#include <cstdio>
#include <cstring>
#include <iostream>
//²»ËãÄÑµÄ×´Ñ¹Dp
//By sssSSSay 
using namespace std;

const int Maxn = 520;

typedef long long ll;

int n, k, all, sum[Maxn];
ll dp[Maxn][10][Maxn], ans;
bool vis[Maxn], sur[Maxn][Maxn];

inline int lowbit(int x) {return x & (-x);}

inline bool Can(int x) {
	for(int i = 1; i < n; ++i) {
		int l = x & (1 << i),r = x & (1 << (i - 1));
		if(l && r) return 0;
	}
	return 1;
}

inline bool Judge(int x, int y) {
	for(int i = 0; i < n; ++i) {
		if(x & (1 << i)) {
			int l = y & (1 << (i + 1)), m = y & (1 << i), r = (i != 0) ? (y & (1 << (i - 1))) : 0;
			if(l || m || r) return 0;
		}
	}
	return 1;
}

inline void In() {
	for(int i = 0; i <= all; ++i) {
		for(int j = 0 ; j <= all; ++j) {
			if(Judge(i, j)) sur[i][j] = 1;
		}
	}
	for(int i = 0; i <= all; ++i) {
		if(Can(i)) vis[i] = 1;	
	}
	for(int i = 0; i <= all; ++i) {
		int w = i;
		while(w) {
			++sum[i];	
			w -= lowbit(w);
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);
	all = (1 << n) - 1; In();
	for(int i = 0; i <= all; ++i) if(vis[i]) dp[1][sum[i]][i] = 1ll;
	for(int i = 2; i <= n; ++i) {
		for(int p = 0; p <= k; ++p) {
			for(int j = 0; j <= all; ++j) {
				if(vis[j]) {
					for(int l = 0; l <= all; ++l) {
						if(sur[j][l] && p >= sum[j] && vis[l]) {
							dp[i][p][j] += dp[i - 1][p - sum[j]][l];
						}
					}
				}
			}
		}
	}
	for(int i = 0; i <= all; ++i) {
		if(vis[i]) ans += dp[n][k][i];	
	}
	printf("%lld\n",ans);
	return 0;
}
