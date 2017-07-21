#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 110;

int n, tot, root, l[Maxn], r[Maxn], fa[Maxn], ans[Maxn];

void Dfs(int u) {
	// printf("%d ", u);
	if(!r[u]) {
		if(u == root) {
			if(!l[l[u]] && !r[l[u]]) {
				int v = l[u];
				ans[++tot] = v;
				l[u] = 0;
				return;	
			}
			else {
				ans[++tot] = root;
				root = l[u];
				return;
			}
		}
		else if(!l[u]) {
			ans[++tot] = u;
			l[fa[u]] = 0;
			return;
		}
		else if(!l[l[u]] && !r[l[u]]) {
			int v = l[u];
			ans[++tot] = v;
			l[u] = 0;
			return;
		}
		else {
			l[fa[u]] = l[u];
			fa[l[u]] = fa[u];
			ans[++tot] = u;
			return;
		}
	}
	Dfs(l[u]);
	swap(l[u], r[u]);
}

int main() {
	// freopen("heap.in", "r", stdin);
	// freopen("heap.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if(x >= 100) r[x - 100] = i, fa[i] = x - 100;
		else l[x] = i, fa[i] = x;
	}
	root = 0;
	for(int k = 1; k <= n + 1; ++k) {
		Dfs(root);
		// puts("");
		// for(int i = 0; i <= n; ++i) printf("l[%d] = %d r[%d] = %d\n", i, l[i], i, r[i]);
		// puts("");
	}
	for(int i = tot; i >= 2; --i) printf("%d ", ans[i]);
	printf("%d", ans[1]);
	// Dfs(0);
	// while(1);
	return 0;
}