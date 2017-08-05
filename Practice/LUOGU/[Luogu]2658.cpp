#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 100000009

using namespace std;

const int Maxn = 710;

struct node {
	int x, y;
};

int n, m, map[Maxn][Maxn], b[Maxn][Maxn], mx, sx, sy, dis[Maxn][Maxn];
bool vis[Maxn][Maxn];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

bool Check(int x) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			dis[i][j] = INF;
			vis[i][j] = 0;
		}
	}
	queue <node> Q;
	vis[sx][sy] = 1; Q.push((node){sx, sy});
	while(!Q.empty()) {
		int ux = Q.front().x;
		int uy = Q.front().y;
		Q.pop(); vis[ux][uy] = 0;
		for(int i = 1; i <= 4; ++i) {
			int xx = ux + dx[i];
			int yy = uy + dy[i];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && (abs(map[ux][uy] - map[xx][yy]) <= x) && dis[xx][yy] == INF) {
				dis[xx][yy] = 0;
				if(!vis[xx][yy]) {
					vis[xx][yy] = 1;
					Q.push((node){xx, yy});
				}
			}
		}
	}
	int pd = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(b[i][j] == 1 && dis[i][j] == INF) {
				pd = 1;
				break;
			}
		}
	}
	if(pd == 0) return true;
	else return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &map[i][j]);
			mx = max(mx, map[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &b[i][j]);
			if(b[i][j] == 1) {
				sx = i; sy = j;
			}
		}
	}
	int l = 0, r = mx, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(Check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	// while(1);
	return 0;
}