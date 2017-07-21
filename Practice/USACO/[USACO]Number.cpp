#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Maxn = 13;

int vis[Maxn], n, sum, a[Maxn];
int b[15][30];

void Dfs(int x, int temp) {
	if(temp > sum) return;
	if(x == n + 1 && temp == sum) {
		for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
		puts("");
		exit(0);
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			vis[i] = 1;
			a[x] = i;
			Dfs(x + 1, temp + a[x] * b[n][x]);
			vis[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &sum);
	b[1][1] = 1;
	for(int i = 2; i <= 12; ++i) {
		for(int j = 1; j <= i - 1; ++j) b[i][j] = b[i - 1][j];
		for(int j = 1; j <= i - 1; ++j) b[i][j + 1] += b[i - 1][j];
	}
	Dfs(1, 0);
	return 0;
}
