#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 30100, M = 5010;

struct node {
	int x, y;	
} a[M];

int n, m, q, ans;

bool comp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &q);
	a[2].x = 0; a[2].y = 0;
	a[1].x = 0; a[1].y = m;
	a[3].x = n; a[3].y = 0;
	a[4].x = n; a[4].y = m;
	q += 4;
	for(int i = 5; i <= q; ++i) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a + 1, a + q + 1, comp);
	for(int i = 1; i <= q; ++i) {
		int u = 0, d = m;
		for(int j = i + 1; j <= q; ++j)	{
			if(a[i].x == a[j].x || a[j].y < u || a[j].y > d) continue;
			ans = max(ans, (d - u) * (a[j].x - a[i].x));
			if(a[j].y > u && a[j].y <= a[i].y) u = a[j].y;
			if(a[j].y < d && a[j].y >= a[i].y) d = a[j].y;
			if(u >= d) break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
