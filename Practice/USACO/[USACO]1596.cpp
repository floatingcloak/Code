#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 51;

struct node {
	int x, y;
};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};
int n, m, ans;
char map[Maxn][Maxn];
bool vis[Maxn][Maxn];

void Bfs(int i, int j) {
	queue <node> Q;
	Q.push((node){i, j});
	while(!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop(); map[x][y] = '.';
		for(int i = 1; i <= n; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && map[xx][yy] == 'M' && !vis[xx][yy]) {
				Q.push((node){xx, yy});
				vis[xx][yy] = 1;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) cin >> map[i][j];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(map[i][j] == 'W') {
				++ans;
				vis[i][j] = 1;
				Bfs(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}