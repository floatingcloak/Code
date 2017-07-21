#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10;

int n, k;
long long ans;
int vis[Maxn][Maxn], b[Maxn][Maxn];

bool Judge(int x, int y, int z) {
	if(z == 0) return 1;
	else return (((y / 2) + (y & 1)) * ((x / 2) + (x & 1)) >= z);
}

void Dfs(int x, int lx, int ly) {
	if(x == k + 1) {
		++ans;
		return;	
	}
	if(!Judge(n - lx + 1, n, k - x + 1)) return;
	for(int i = lx; i <= n; ++i) {
		for(int j = (i == lx) ? ly : 1; j <= n; ++j) {
			if(vis[i][j] == 0 && i >= 1 && j >= 1) {
				b[i][j] = 1;
				vis[i][j]++;vis[i + 1][j]++;vis[i][j + 1]++;vis[i - 1][j]++;vis[i][j - 1]++;
				vis[i + 1][j + 1]++;vis[i - 1][j - 1]++;vis[i + 1][j - 1]++;vis[i - 1][j + 1]++;
				
				Dfs(x + 1, i, j);
				
				b[i][j] = 0;
				vis[i][j]--;vis[i + 1][j]--;vis[i][j + 1]--;vis[i - 1][j]--;vis[i][j - 1]--;
				vis[i + 1][j + 1]--;vis[i - 1][j - 1]--;vis[i + 1][j - 1]--;vis[i - 1][j + 1]--;
			}
		}
	}
}

int main() {
	for(n = 9; n <= 9; ++n) {
		for(k = 10; k <= n * n; ++k) {
			ans = 0;
			Dfs(1, 1, 1);
			printf("dp[%d][%d] = %lld\n", n, k, ans);
			if(ans == 0) break;
		}
	}
	return 0;
}
