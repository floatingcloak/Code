#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101000;

int Q[Maxn * 10], head = 1, tail = 0;
int n, m, x, tot, tim, low[Maxn], dfn[Maxn], sum[Maxn], in[Maxn], h[Maxn], top, vis[Maxn];
int s[Maxn], bel[Maxn], cnt, res, p[Maxn], dp[Maxn], g[Maxn];
bool ins[Maxn];

struct node {
	int u, v, next;
} e[Maxn * 20];

struct data {
	int v, next;
} l[Maxn * 20];

void Add(int u, int v) {
	e[++tot].v = v; e[tot].next = h[u];
	e[tot].u = u; h[u] = tot;
}

void Link(int u, int v) {
	l[++res].v = v; l[res].next = p[u];
	p[u] = res;
}

void Tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	ins[u] = 1; s[++top] = u;
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		int t = 0; ++cnt;
		while(t != u) {
			t = s[top--];
			++sum[cnt];
			bel[t] = cnt;
			ins[t] = 0;
		}
	}
}

void Dp() {
	for(int i = 1; i <= cnt; ++i) {
		if(in[i] == 0) Q[++tail] = i;
		dp[i] = sum[i]; g[i] = 1;
	}
	while(head <= tail) {
		int u = Q[head]; ++head;
		for(int i = p[u]; i; i = l[i].next) {
			int v = l[i].v; 
			--in[v];
			if(in[v] == 0) Q[++tail] = v;
			if(vis[v] == u) continue;
			if(dp[u] + sum[v] > dp[v]) {
				dp[v] = dp[u] + sum[v];
				g[v] = g[u];
			}
			else if(dp[u] + sum[v] == dp[v]) {
				(g[v] += g[u]) %= x;
			}
			vis[v] = u;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 1, q, w; i <= m; ++i) {
		scanf("%d%d", &q, &w);
		Add(q, w);
	}
	for(int i = 1; i <= n; ++i) if(!dfn[i]) Tarjan(i);
	// printf("%d\n", cnt);
	for(int i = 1; i <= tot; ++i) {
		int u = bel[e[i].u], v = bel[e[i].v];
		if(u != v) {
			Link(u, v);
			++in[v];
		}
	}
	Dp();
	int ans = 0, ans2 = 0;
	for(int i = 1; i <= cnt; ++i) {
		if(dp[i] > ans) {
			ans = dp[i];
			ans2 = g[i];
		}
		else if(dp[i] == ans) (ans2 += g[i]) %= x;
	}
	// for(int i = 1; i <= cnt; ++i) printf("%d ", dp[i]);
	// puts("");
	// for(int i = 1; i <= cnt; ++i) printf("%d ", g[i]);
	// puts("");
	// ans2 = 0;
	// for(int i = 1; i <= cnt; ++i) if(ans == dp[i]) ans2 += g[i];
	printf("%d\n%d\n", ans, ans2);
	// while(1);
	return 0;
}