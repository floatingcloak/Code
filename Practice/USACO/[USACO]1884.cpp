#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 15;

int x1[Maxn], x2[Maxn], y1[Maxn], y2[Maxn], n, ans;
bool map[Maxn][Maxn];

int Get(int x, int y) {
	int dx = min(x2[x], x2[y]) - max(x1[x], x1[y]);
	int dy = min(y1[x], y1[y]) - max(y2[x], y2[y]);
	return (dx >= 0 && dy >= 0) ? dx * dy : 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		ans += (x2[i] - x1[i]) * (y1[i] - y2[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i != j) {
				if(!map[i][j] && !map[j][i]) {
					int k = Get(i, j);
					ans -= k;
					map[i][j] = map[j][i] = 1;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
