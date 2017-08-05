#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 10100;

struct node {
	int x, y;
} a[Maxn];

int n, m, u[Maxn], v[Maxn], fa[Maxn], ans1[Maxn], ans2[Maxn], tot;

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

bool comp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) scanf("%d%d", &u[i], &v[i]);
	for(int kk = 1; kk <= m; ++kk) {
		for(int i = 1; i <= n; ++i) fa[i] = i;
		for(int i = 1; i <= m; ++i) {
			if(kk != i) {
				int r1 = find(u[i]), r2 = find(v[i]);
				if(r1 != r2) fa[r1] = r2;
			}
		}
		int temp = 0;
		for(int i = 1; i <= n; ++i) if(fa[i] == i) ++temp;
		if(temp >= 2) {
			a[++tot].x = min(u[kk], v[kk]);
			a[tot].y = max(u[kk], v[kk]);
		}
	}
	sort(a + 1, a + tot + 1, comp);
	for(int i = 1; i <= tot; ++i) printf("%d %d\n", a[i].x, a[i].y);
	// for(;;);
	return 0;
}