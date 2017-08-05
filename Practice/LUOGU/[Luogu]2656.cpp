#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101010;

struct node {
	int u, next, v, c;
	double d;
} e[Maxn];

struct data {
	int next, v, c;
} ee[Maxn];

int n, m, h[Maxn], hh[Maxn], tot, tot1, dfn[Maxn], tim, low[Maxn], s[Maxn], top, ans, bel[Maxn], sum[Maxn], dis[Maxn];
int cnt;
bool vis[Maxn], ins[Maxn];

void Add1(int u, int v, int c) {
	ee[++tot1] = (data){hh[u], v, c}; hh[u] = tot1;
}

void Add(int u, int v, int c, double d) {
	e[++tot] = (node){u, h[u], v, c, d}; h[u] = tot; 
}

void Tarjan(int u) {
	dfn[u] = low[u] = ++tim; s[++top] = u; ins[u] = 1;
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		int t = -1; ++cnt;
		while(t != u) {
			t = s[top--];
			bel[t] = cnt;
			ins[t] = 0;
		}
	}
}

void Spfa(int st) {
	queue <int> Q;
	Q.push(st); vis[st] = 1;
	while(!Q.empty()) {
		int u = Q.front(); vis[u] = 0; Q.pop();
		for(int i = hh[u]; i; i = ee[i].next) {
			int v = ee[i].v;
			if(dis[v] < dis[u] + ee[i].c) {
				dis[v] = dis[u] + ee[i].c;
				ans = max(ans, dis[v]);
				if(!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x, y, z; double d;
		scanf("%d%d%d%lf", &x, &y, &z, &d);
		Add(x, y, z, d);
	}
	int str; scanf("%d", &str);
	for(int i = 1; i <= n; ++i) if(!dfn[i]) Tarjan(i);
	for(int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v;
		if(bel[u] == bel[v]) {
			int w = e[i].c;
			while(w) {
				sum[bel[u]] += w;
				w = (int)((double)w * e[i].d);
			}
		}
	}
	// for(int i = 1; i <= cnt; ++i) cout << sum[i] << ' ';
	// cout << endl;
	// cout << cnt << endl;
	for(int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v;
		if(bel[u] != bel[v]) {
			Add1(bel[u], bel[v], e[i].c + sum[bel[v]]);
			// cout << bel[u] << ' ' << bel[v] << ' ' << e[i].c + sum[bel[v]] << endl;
		}
	}
	int st = bel[str];
	// cout << st << endl;
	Spfa(st);
	ans += sum[st];
	printf("%d\n", ans);
	// for(;;);
	return 0;
}