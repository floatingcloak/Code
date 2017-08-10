#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

struct node {
	int x, y, s;
};

queue <node> Q;

int n, m, m1, m2, map[Maxn][Maxn], sx, sy, ex, ey, dx[10], dy[10];
bool vis[Maxn][Maxn];

int main() {
	scanf("%d%d%d%d", &n, &m, &m1, &m2);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> map[i][j];	
			if(map[i][j] == 3) sx = i, sy = j;
			if(map[i][j] == 4) ex = i, ey = j;
		}
	}
	dx[1] = dx[2] = m1; dx[3] = dx[4] = m2; dx[5] = dx[6] = -m1; dx[7] = dx[8] = -m2;
	dy[1] = m2; dy[2] = -m2; dy[3] = -m1; dy[4] = m1; dy[5] = m2; dy[6] = -m2; dy[7] = m1; dy[8] = -m1;
	Q.push((node){sx, sy, 0}); vis[sx][sy] = 1;
	while(!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int s = Q.front().s;
		Q.pop();
		// cout << x << ' ' << y << endl;
		if(x == ex && y == ey) {
			printf("%d\n", s);
			// for(;;);
			return 0;
		}
		for(int i = 1; i <= 8; ++i) {
			int xx = x + dx[i], yy = y + dy[i];
			// cout << "@" << dx[i] << ' ' << dy[i] << ' ' << xx << ' ' << yy << endl;
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && (map[xx][yy] == 1 || map[xx][yy] == 4) && vis[xx][yy] == 0) {
				vis[xx][yy] = 1;
				Q.push((node){xx, yy, s + 1});
			}		
		}
	}
	// cout << '!';
	// for(;;);
	return 0;
}
