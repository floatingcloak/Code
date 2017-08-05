#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101010;

struct node {
	int next, v, cap;
} e[Maxn];

int h[Maxn], tot = 1, n, x, y, z, S, T;

void Add(int u, int v, int c) {
	e[++tot] = (node){h[u], v,  c}; h[u] = tot;
	e[++tot] = (node){h[v], u, -c}; h[v] = tot;
}

int Bfs() {
	queue <int> Q;
	for(int i = S; i <= T; ++i) {
		dis[i] = INF; vis[i] = 0;
	}
	vis[S] = 1; dis[S] = 0; Q.push(S);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].v;
			if(dis[v] == INF && e[i].cap) {
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
	}
	return dis[T] != INF;
}

int Dfs(int u, int Min) {
	if(u == T) return Min;
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(e[i].cap && dis[v] == dis[u] + 1) {
			int w = Dfs(v, min(Min, e[i].cap));
			if(w) 
			used += w;
		}
}

int main() {
	scanf("%d", &n); T = 2000;
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		Add(y + 500, z + 1000, 1);
		Add(x, y + 500, 1);
		if(!map[x]) {Add(S, x, INF); map[x] = 1;}
		if(!map[z + 1000]) {Add(z + 1000, T, INF); map[z + 1000] = 1;}
	}
	while(Bfs()) ans += Dfs(S, INF);
	printf("%d\n", ans);
	return 0;
}