#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1100;

struct node {
	int x, y;	
};

queue <node> Q;

char a[Maxn][Maxn];
bool vis[Maxn][Maxn];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int n, m, ans;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];		
			if(a[i][j] == 'o') Q.push((node){i, j});
		}
	}
	while(!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop(); ++ans; vis[x][y] = 1;
		for(int k = 1; k <= 4; ++k) {
			int xx = x + dx[k], yy = y + dy[k];
			if(k == 1 && a[xx][yy] == 'u' && !vis[xx][yy]) Q.push((node){xx, yy}), vis[xx][yy] = 1;
			if(k == 2 && a[xx][yy] == 'd' && !vis[xx][yy]) Q.push((node){xx, yy}), vis[xx][yy] = 1;
			if(k == 3 && a[xx][yy] == 'l' && !vis[xx][yy]) Q.push((node){xx, yy}), vis[xx][yy] = 1;
			if(k == 4 && a[xx][yy] == 'r' && !vis[xx][yy]) Q.push((node){xx, yy}), vis[xx][yy] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
