#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101;

int n, m, ans, c[Maxn], b[Maxn];
bool a[Maxn][Maxn];

void Dfs(int x, int sum) {
	if(sum + n - x + 1 <= ans) return;
	if(x == n + 1) {
		if(sum > ans) {
			ans = sum;
			for(int i = 1; i <= n; ++i) c[i] = b[i];
		}
		return;
	}
	int pd = 1;
	for(int i = 1; i <= x - 1 && pd; ++i) {
		if(b[i] && a[i][x]) pd = 0;
	}
	if(pd == 1) {
		b[x] = 1;
		Dfs(x + 1, sum + 1);
		b[x] = 0;
	}
	Dfs(x + 1, sum);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
		a[u][v] = a[v][u] = 1;
	}
	Dfs(1, 0);
	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i) printf("%d ", c[i]);
	puts("");
	// for(;;);
	return 0;
}