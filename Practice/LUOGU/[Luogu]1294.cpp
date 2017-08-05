#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1000000007

using namespace std;

const int Maxn = 1010;

int n, m, map[Maxn][Maxn], ans;
bool vis[Maxn];

void Dfs(int x, int sum) {
	ans = max(ans, sum);
	// cout << x << ' ' << sum << endl;
	for(int i = 1; i <= n; ++i) {
		if(map[x][i] && !vis[i]) {
			vis[i] = 1;
			Dfs(i, sum + map[x][i]);
			vis[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x,  y, z; scanf("%d%d%d", &x, &y, &z);
		map[x][y] = map[y][x] = z;
	}
	for(int i = 1; i <= n; ++i) {
		vis[i] = 1;
		Dfs(i, 0);
		vis[i] = 0;
		// cout << endl;
	}
	// for(int k = 1; k <= n; ++k) {
	// 	for(int i = 1; i <= n; ++i) {
	// 		if(map[i][k] != -INF) {
	// 			for(int j = 1; j <= n; ++j) {
	// 				if(map[k][j] != -INF) {
	// 					map[i][j] = max(map[i][j], map[i][k] + map[k][j]);
	// 					ans = max(ans, map[i][j]);
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	printf("%d\n", ans);
	// for(;;);
	return 0;
}