#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 2000000009

using namespace std;

const int Maxn = 1100;

struct node {
	int v, next, c;	
} e[101000];

struct data {
	int v, next, c;	
} ee[101000];

int n, m, t, h[Maxn], hh[Maxn], tot, tt;
int dis[Maxn], dis2[Maxn];
bool vis[Maxn], vis2[Maxn];

void Add(int u, int v, int c) {
	e[++tot].v = v; e[tot].c = c;
	e[tot].next = h[u]; h[u] = tot;
}

void Add2(int u, int v, int c) {
	ee[++tt].v = v; ee[tt].c = c;
	ee[tt].next = hh[u]; hh[u] = tt;	
}

void Spfa() {
	queue <int> Q;
	for(int i = 1; i <= n; ++i) dis[i] = INF;
	dis[t] = 0; vis[t] = 1; Q.push(t);
	while(!Q.empty()) {
		int u = Q.front(); vis[u] = 0; Q.pop();
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].v;
			if(dis[u] + e[i].c < dis[v]) {
				dis[v] = dis[u] + e[i].c;
				if(vis[v] == 0) {
					vis[v] = 1;
					Q.push(v);	
				}
			}
		}
	}
}
void Spfa2() {
	queue <int> Q;
	for(int i = 1; i <= n; ++i) dis2[i] = 2000000007;
	dis2[t] = 0; vis2[t] = 1; Q.push(t);
	while(!Q.empty()) {
		int u = Q.front(); vis2[u] = 0; Q.pop();
		for(int i = hh[u]; i; i = ee[i].next) {
			int v = ee[i].v;
			if(dis2[u] + ee[i].c < dis2[v]) {
				dis2[v] = dis2[u] + ee[i].c;
				if(vis2[v] == 0) {
					vis2[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}
int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		Add(x, y, z); Add2(y, x, z);
	}
	Spfa(); Spfa2(); int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(dis[i] != INF && dis2[i] != INF) {
			ans = max(ans, dis[i] + dis2[i]);
		}
//		cout << i << ' ' << dis[i] << ' ' << dis2[i] << endl;
	}
	printf("%d\n", ans);
	return 0;
}
