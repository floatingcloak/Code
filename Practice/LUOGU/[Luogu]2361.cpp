#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10;

int n, m, map[Maxn][Maxn];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

int main() {
	// freopen("test.in", "r", stdin);
	memset(map, -1, sizeof map);
	scanf("%d%d", &n, &m);
	int pd1 = n & 1, pd2 = m & 1;
	if(!pd1 && !pd2) puts("Second");
	else puts("First");
	if(!pd1 && !pd2) {
		int x, y, c;
		while(scanf("%d%d%d", &x, &y, &c) != EOF) {
			for(int i = 1; i <= 4; ++i) {
				int xx = x + dx[i], yy = y + dy[i];
				if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && (map[xx][yy] == (c ^ 1) || map[x][y] != -1)) {
					puts("Buwanle");
					for(;;);
					return 0;
				}
			}
			map[x][y] = c; int pd = 1;
			for(int i = 1; i <= n && pd; ++i) {
				for(int j = 1; j <= m && pd; ++j) {
					int p = 1;
					for(int k = 1; k <= 4; ++k) {
						int xx = i + dx[k], yy = j + dy[k];
						// cout << xx << ' ' << n << ' ' << yy << ' ' << m << endl;
						// cout << map[xx][yy] << ' ' << c << endl;
						if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && (map[xx][yy] == c)) {
							p = 0;
							// cout << '!';
						}
						// cout << xx << ' ' << yy << ' ' << map[xx][yy] << ' ' << p << ' ' << c << endl;
					}
					if(map[i][j] == -1 && p) {
						printf("%d %d %d\n", i, j, c ^ 1);
						map[i][j] = c ^ 1;
						pd = 0; break;
					}
				}
			}
		}
	}
	else {
		puts("1 1 1");
		map[1][1] = 1;
		int x, y, c;
		while(scanf("%d%d%d", &x, &y, &c) != EOF) {
			for(int i = 1; i <= 4; ++i) {
				int xx = x + dx[i], yy = y + dy[i];
				if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && (map[xx][yy] == (c ^ 1) || map[x][y] != -1)) {
					puts("Buwanle");
					for(;;);
					return 0;
				}
			}
			map[x][y] = c; int pd = 1;
			for(int i = 1; i <= n && pd; ++i) {
				for(int j = 1; j <= m && pd; ++j) {
					int p = 1;
					for(int k = 1; k <= 4; ++k) {
						int xx = i + dx[k], yy = j + dy[k];
						if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && (map[xx][yy] == c)) p = 0;
					}
					if(map[i][j] == -1 && p) {
						printf("%d %d %d\n", i, j, c ^ 1);
						map[i][j] = c ^ 1;
						pd = 0; break;
					}
				}
			}
		}
	}
	for(;;);
	return 0;
}