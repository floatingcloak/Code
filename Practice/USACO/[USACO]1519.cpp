#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 100000007

using namespace std;

const int Maxn = 110;

struct node {
	int x, y, s;
};

queue <node> Q;

int n, m, dis[Maxn][Maxn];
int dx1[5] = {0, 0, 0, -1, 1};
int dy1[5] = {0, 1, -1, 0, 0};
int dx[5] = {0, 0, 0, -2, 2};
int dy[5] = {0, 2, -2, 0, 0};
char map[Maxn][Maxn], ch;

int main() {
	scanf("%d%d", &m, &n);
	n = 2 * n + 1; m = 2 * m  + 1;
	++n; ++m;
	for(int i = 1; i <= n; ++i) gets(map[i] + 1);
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j <= m; ++j) {
			map[i][j] = map[i + 1][j];
			dis[i][j] = INF;
		}
	}
	--n;
	// for(int i = 1; i <= n; ++i) {
	// 	cout << (map[i] + 1) << endl;
	// }
	for(int i = 1; i <= n; ++i) {
		if((bool)(map[i][m]) == 0 || (map[i][m] == ' ')) Q.push((node){i, m, 0});
	}
	for(int i = 1; i <= m; ++i) {
		if((bool)(map[n][i] == 0) || (map[n][i] == ' ')) Q.push((node){n, i, 0});
	}
	while(!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int s = Q.front().s;
		Q.pop();
		// cout << x << ' ' << y << endl;
		for(int i = 1; i <= 4; ++i) {
			int xx = x + dx[i], x3 = x + dx1[i];
			int yy = y + dy[i], y3 = y + dy1[i];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && ((bool)(map[xx][yy]) == 0 || (map[xx][yy] == ' ')) && ((bool)(map[x3][y3]) == 0 || (map[x3][y3] == ' '))) {
				if(dis[xx][yy] > s + 1) {
					dis[xx][yy] = s + 1;
					Q.push((node){xx, yy, s + 1});
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(dis[i][j] != INF) ans = max(ans, dis[i][j]);
			// if(dis[i][j] != INF) printf("%-4d", dis[i][j]);
			// else cout << "INF" << ' ';
		}
		// cout << endl;
	}
	// cout << (map[5][10]) << endl;
	printf("%d\n", ans);
	// while(1);
	return 0;
}