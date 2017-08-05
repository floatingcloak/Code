#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101010;

int n, m, v, x, y, ans = 1000000009, x4[Maxn], y4[Maxn];
bool vis[Maxn];

void Dfs(int x3, int y3, int now, int sum) {
	if(x3 == x && y3 == y) {
		ans = min(ans, sum);
		return;
	}
	int xx = x4[now], yy = y4[now];
	int num = (xx - 1) * m + yy;
	if(vis[num]) return;
	int temp = abs(x3 - xx) * v;
	vis[num] = 1;
	Dfs(xx, yy, num, sum + temp);
	vis[num] = 0;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &v, &x, &y);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int num = (i - 1) * m + j;
			scanf("%d%d", &x4[num], &y4[num]);
		}
	}
	for(int j = 1; j <= m; ++j) {
		vis[j] = 1;
		Dfs(1, j, j, 0);
		vis[j] = 0;
	}
	if(ans == 1000000009) puts("impossible");
	else printf("%d\n", ans);
	// for(;;);
	return 0;
}