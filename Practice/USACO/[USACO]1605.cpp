#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 21;

int map[Maxn][Maxn];
bool vis[Maxn][Maxn];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
int n, m, t, sx, sy, tx, ty, ans;

void Dfs(int x, int y) {
	if(x == tx && y == ty) {
		++ans;
		return;	
	}
	for(int i = 1; i <= 4; ++i) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(map[xx][yy] == 0 && xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy]) {
			vis[xx][yy] = 1;
			Dfs(xx, yy);
			vis[xx][yy] = 0;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	for(int i = 1; i <= t; ++i) {
		int x, y; scanf("%d%d", &x, &y);	
		map[x][y] = 1;
	}
	vis[sx][sy] = 1;
	Dfs(sx, sy);
	printf("%d\n", ans);
	return 0;
}
