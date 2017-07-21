#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 9110;

int n, m, f[110], g[110];
bool dis[110][110];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		dis[x][y] = 1;
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			if(dis[i][k]) {
				for(int j = 1; j <= n; ++j) {
					if(i != k && i != j && j != k) {
						if(dis[i][k] && dis[k][j]) {
							dis[i][j] = 1;	
						}
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			if(dis[i][j] == 1) ++f[i], ++g[j];
			if(dis[j][i] == 1) ++g[i], ++f[j];
		}
	}
	int ans = 0;
//	for(int i = 1; i <= n; ++i) cout << ">>" << f[i] << ' ' << g[i] << endl;
	for(int i = 1; i <= n; ++i) if(f[i] + g[i] == (n - 1)) ++ans;
	printf("%d\n", ans);	
	return 0;
}
