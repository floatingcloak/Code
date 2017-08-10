#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 101010;

struct node {
	int id, w;
} r[Maxn], c[Maxn];

int n, m, k, l, d, ansr[Maxn], ansc[Maxn];

bool comp(node a, node b) {return a.w > b.w;}

int main() {
	// freopen("t.in", "r", stdin);
	cin >> n >> m >> k >> l >> d;
	// scanf("%d%d%d%d%d", &n, &m, &k, &l, &d);
	// printf("%d %d\n", n, m);
	for(int i = 1; i <= d; ++i) {
		int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		if(xx == x) ++c[min(y, yy)].w;
		else ++r[min(x, xx)].w;
	}
	for(int i = 1; i < n; ++i) r[i].id = i;
	for(int i = 1; i < m; ++i) c[i].id = i;
	sort(r + 1, r + n, comp);
	sort(c + 1, c + m, comp);
	for(int i = 1; i <= k; ++i) ansr[i] = r[i].id;
	for(int i = 1; i <= l; ++i) ansc[i] = c[i].id;
	sort(ansr + 1, ansr + k + 1);
	sort(ansc + 1, ansc + l + 1);
	for(int i = 1; i <= k; ++i) printf("%d ", ansr[i]);
	puts("");
	for(int i = 1; i <= l; ++i) printf("%d ", ansc[i]);
	// for(;;);
	return 0;
}