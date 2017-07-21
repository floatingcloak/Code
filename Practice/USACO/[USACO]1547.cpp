#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 20100;

int n, m, h[Maxn], ans, fa[Maxn];

struct node {
	int u, v, c;
} e[Maxn];

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

bool comp(node a, node b) {return a.c < b.c;}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		e[i].u = x; e[i].v = y; e[i].c = z;
	}
	sort(e + 1, e + m + 1, comp);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		int r1 = find(e[i].u), r2 = find(e[i].v);
		if(r1 != r2) {
			fa[r1] = r2;
			ans = max(ans, e[i].c);
		}
	}
	printf("%d\n", ans);
	// while(1);
	return 0;
}