#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

struct node {
	int u, v, c;
} e[Maxn * Maxn];

int n, c, x[Maxn], y[Maxn];

int Dis(int i, int j) {return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);}

int main() {
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			e[++tot] = (node){i, j, Dis(i, j)};
		}
	}
	sort(e + 1, e + tot + 1, comp);
	for(int i = 1; i <= tot; ++i) {
		if(e[i].c < c) continue;
		int r1 = find(e[i].u), r2 = find(e[i].v);
		if(r1 != r2) {
			fa[r1] = r2;
			ans += e[i].c;	
		}
	}
	cout << ans << endl;
	return 0;
}
