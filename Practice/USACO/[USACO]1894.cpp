#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1100;

struct node {
	int v, next;	
} e[Maxn];

int n, m, h[Maxn], tot, link[Maxn], ans;
bool vis[Maxn];

void Add(int u, int v) {
	e[++tot].v = v; e[tot].next = h[u];
	h[u] = tot;	
}

bool find(int u) {
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(vis[v] == 0) {
			vis[v] = 1;
			if(!link[v] || find(link[v])) {
				link[v] = u;
				return 1;	
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int s; scanf("%d", &s);
		for(int j = 1; j <= s; ++j) {
			int x; scanf("%d", &x);
			Add(i, x);		
		}
	}
	for(int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		if(find(i)) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}
