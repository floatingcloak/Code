#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 200100;

int g[Maxn][33], f[Maxn][32];

int n, m, a[Maxn];
int s = 0;
void St() {
	int lim = (int)log2(n);
	for(int i = 1; i <= n; ++i) f[i][0] = a[i], g[i][0] = a[i];
//	cout << lim << endl;
	for(int j = 1; j <= lim; ++j) {
		for(int i = 1; i <= n; ++i) {
			f[i][j] = f[i][j - 1];
			g[i][j] = g[i][j - 1];
			if(i + (1 << (j - 1)) <= n) {
				f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
				g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
}

int GetMin(int x, int y) {
	int m = (int)log2(y - x + 1);
	return min(f[x][m], f[y - (1 << m) + 1][m]);
}

int GetMax(int x, int y) {
	int m = (int)log2(y - x + 1);
	return max(g[x][m], g[y - (1 << m) + 1][m]);	
}

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d", &n, &m);
//	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);	
	}
	St();
	for(int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", GetMax(x, y) - GetMin(x, y));
	}
	return 0;
}
