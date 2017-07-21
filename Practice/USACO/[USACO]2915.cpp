#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 20100;

int n, k, ans, a[Maxn];
int dp[Maxn][1 << 17];
bool vis[Maxn];

void Dfs(int x, int last) {
	if(x == n + 1) {
		++ans;
		return;
	}
	for(int i = 1; i <= n; ++i) {
		if(vis[i] == 0 && (last == -1 || (abs(last - a[i]) <= k))) {
			vis[i] = 1;
			Dfs(x + 1, a[i]);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("test.in", "r", stdin);
	scanf("%d%d", &n, &k);
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= all; ++j) {
			if(dp[i - 1][j]) {
				for(int l = 1; l <= n; ++l) {
					if()
				}
			}
		}
	}
	return 0;	
}
