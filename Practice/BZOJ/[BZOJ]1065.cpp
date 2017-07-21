#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 110;

int s[Maxn], n, m, tot, h[Maxn];
double k, c[Maxn], val[Maxn];

struct node {
	int v, next;
} e[Maxn];

void Add(int u, int v) {
	e[++tot].v = v; e[tot].next = h[u];
	h[u] = tot;
}

double Dfs(int x) {
	printf("%d\n", x);
	val[x] = c[x];
	for(int i = h[x]; i; i = e[i].next) {
		int v = e[i].v;
		val[x] += Dfs(v);
	}
	return val[x];
}

int main() {
	scanf("%d%d%lf", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &s[i]);
		Add(s[i], i);
	}
	for(int i = 1; i <= n; ++i) scanf("%lf", &c[i]);
	Dfs(1);
	for(int i = 1; i <= n; ++i) printf("%.2lf ", val[i]);
	return 0;
}