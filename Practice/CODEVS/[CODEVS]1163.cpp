#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 210;

queue <int> Q;

int sum[Maxn], q[Maxn], fa[Maxn], lt[Maxn], rt[Maxn], s, tot, res, ls[Maxn], rs[Maxn], dp[Maxn][Maxn * 10], n, a[Maxn], cnt;
bool vis[Maxn];

void Read(int u, int cur) {
	int x, p; ++tot;
	scanf("%d%d", &x, &p);
	fa[tot] = u; if(tot == 1) s -= 2 * x;
	if(cur) ls[u] = tot, lt[u] = x;
	else rs[u] = tot, rt[u] = x;
	if(p == 0) {
		int w = tot;
		Read(w, 1); Read(w, 0);
	}
	else {
		sum[tot] = p; q[++res] = tot;
	}
}

int main() {
	freopen("test.in", "r", stdin);
	scanf("%d", &s);
	tot = 0; Read(tot, 1); s+=2;
	n = tot; Q.push(1);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		a[++cnt] = u;
		if(ls[u])Q.push(ls[u]); 
		if(rs[u])Q.push(rs[u]);
	}
	for(int i = 1; i <= res; ++i) {
		int u = q[i];
		for(int j = sum[u] * 5; j <= s; ++j) dp[u][j] = sum[u];
	}
	for(int i = cnt; i >= 1; --i) {
		int u = a[i];
		for(int j = 0; j <= s; ++j) {
			if(j - rt[u] * 2 >= 0) dp[u][j] = max(dp[u][j], dp[rs[u]][j - rt[u] * 2]);
			if(j - lt[u] * 2 >= 0) dp[u][j] = max(dp[u][j], dp[ls[u]][j - lt[u] * 2]);
			for(int k = 0;k <= j; ++k) {
				if(k - lt[u] * 2 >= 0 && j - k - rt[u] * 2 >= 0) dp[u][j] = max(dp[u][j], dp[ls[u]][k - lt[u] * 2] + dp[rs[u]][j - k - rt[u] * 2]);
			}
		}
	}
	printf("%d\n", dp[1][s]);
	return 0;
}
