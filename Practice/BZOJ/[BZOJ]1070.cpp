#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
//拆点费用流。。思路挺奇葩的吧。
//By sssSSSay 
#define INF 2e9 + 7

using namespace std;

const int N = 73000;

struct node {
	int val, cap, next, to;	
} e[N];

int n, m, S, T, h[N], tot = 1, dis[N], pre[N], vis[N], a[200][200];

void Link(int u, int v, int c, int w) {
	e[++tot].to = v; e[tot].next = h[u];
	e[tot].cap = c; e[tot].val = w;
	h[u] = tot;
}

void Add(int u, int v, int c, int w) {
	Link(u, v, c, w);
	Link(v, u, 0, -w);	
}

int Bfs() {
	queue <int> Q;
	for(int i = S; i <= T; ++i) {
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[S] = 0; Q.push(S); vis[S] = 1;
	while(!Q.empty()) {
		int u = Q.front();Q.pop();vis[u] = 0;
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val && e[i].cap) {
				dis[v] = dis[u] + e[i].val;
				pre[v] = i;
				if(!vis[v]) {
					vis[v] = 1;
					Q.push(v);	
				}
			}
		}
	}
	return dis[T] != INF;
}

int Mcmf() {
	int temp = 0;
	while(Bfs()) {
		int s = INF;
		for(int j = pre[T]; j; j = pre[e[j ^ 1].to]) s = min(s, e[j].cap);
		for(int j = pre[T]; j; j = pre[e[j ^ 1].to]) e[j].cap -= s, e[j ^ 1].cap += s;
		temp += s * dis[T];
	}
	return temp;
}

int num(int x,int y) {
	return (x - 1) * m + y + m;
}

int main() {
//	freopen("scoi2007_repair.in", "r", stdin);
//	freopen("scoi2007_repair.out", "w", stdout);
	scanf("%d%d", &n, &m);
	T = (n + 1) * (m + 1);
	for(int i = 1; i <= m; ++i) {
		Add(S, i, 1, 0);
		for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) Add(num(i, j), T, 1, 0);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			for(int k = 1; k <= m; ++k) Add(j, num(i, k), 1, k * a[j][i]);
		}
	}
	printf("%.2lf\n", Mcmf() * 1.0 / m);
	return 0;
}
