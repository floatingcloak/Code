#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//Kruskal + 倍增
//By sssSSSay 
using namespace std;

const int Maxn = 301000;

struct node {
	int u, v, c;	
} e[Maxn];

struct data {
	int to, next, val;
} l[Maxn];

int n, m, k, tot, ff[Maxn], h[Maxn], cnt;
int fa[Maxn][33], res[Maxn][33], deep[Maxn];

void Add(int u, int v, int c) {
	l[++cnt].to = v; l[cnt].val = c;	
	l[cnt].next = h[u]; h[u] = cnt;
}

bool comp(node a, node b) {return a.c < b.c;}

int Get(int x) {return ff[x] == x ? x : ff[x] = Get(ff[x]);}

void Dfs(int u, int f, int d) {
	deep[u] = d;
	for(int i = 1; i <= 31; ++i) {
		if(!fa[fa[u][i - 1]][i - 1]) break;
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
		res[u][i] = max(res[u][i - 1], res[fa[u][i - 1]][i - 1]);	
	}
	for(int i = h[u]; i; i = l[i].next) {
		int v = l[i].to;
		if(f != v) {
			fa[v][0] = u;
			res[v][0] = l[i].val;
			Dfs(v, u, d + 1);
		}
	}
}

int Query(int a, int b) {
	int temp = 0;
	if(deep[a] > deep[b]) {
		for(int i = 31; i >= 0 && deep[a] != deep[b]; --i) {
			if(deep[fa[a][i]] >= deep[b]) {
				temp = max(temp, res[a][i]);
				a = fa[a][i];
			}
		}
	}
	if(a == b) return temp;
	if(deep[a] < deep[b]) {
		for(int i = 31; i >= 0 && deep[a] != deep[b]; --i) {
			if(deep[fa[b][i]] >= deep[a]) {
				temp = max(temp, res[b][i]);
				b = fa[b][i];
			}
		}
	}
	for(int i = 31; i >= 0; --i) {
		if(fa[a][i] != fa[b][i]) {
			temp = max(temp, max(res[a][i], res[b][i]));
			a = fa[a][i]; b = fa[b][i];
		}
	}
	if(a != b) {//两个都要取！！ 
		temp = max(temp, res[a][0]);
		temp = max(temp, res[b][0]);
	}
	return temp;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) ff[i] = i;
	for(int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		e[++tot].u = x, e[tot]. v = y; e[tot].c = z;
	}
	sort(e + 1, e + tot + 1, comp);
	for(int i = 1; i <= tot; ++i) {
		int r1 = Get(e[i].u), r2 = Get(e[i].v);
		if(r1 != r2) {
			ff[r1] = r2;
			Add(e[i].u, e[i].v, e[i].c);
			Add(e[i].v, e[i].u, e[i].c);
		}
	}
	Dfs(1, 0, 1);
	while(k--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", Query(a, b));
	}
	return 0;
}
