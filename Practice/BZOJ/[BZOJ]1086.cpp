#include <cstdio>
#include <cstring>
#include <iostream>
// Ê÷·Ö¿é
//By sssSSSay 
using namespace std;

const int Maxn = 1010;

struct node {
	int to, next;	
} e[Maxn * 2];

int n, b, tot, h[Maxn];
int rt[Maxn], belong[Maxn], top, res, sta[Maxn];

inline void Add(int u, int v) {
	e[++tot].to = v; e[tot].next = h[u];
	h[u] = tot;
}

void Dfs(int u, int fa) {
	int now = top;
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(fa != v) {
			Dfs(v, u);
			if(top - now >= b) {
				rt[++res] = u;
				while(top != now) {
					belong[sta[top--]] = res;
				}
			}
		}
	}
	sta[++top] = u;
}

int main() {
//	freopen("bzoj_1086.in", "r", stdin);
//	freopen("bzoj_1086.out", "w", stdout);
	scanf("%d%d", &n, &b);
	if(n < b) {
		puts("0"); return 0;	
	}
	for(int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		Add(x, y); Add(y, x);
	}
	Dfs(1, 0);
	while(top) belong[sta[top--]] = res;
	printf("%d\n", res);
	for(int i = 1; i <= n; ++i) printf("%d ",belong[i]);
	putchar('\n');
	for(int i = 1; i <= res; ++i) printf("%d ", rt[i]);
	putchar('\n');
	return 0;
}
