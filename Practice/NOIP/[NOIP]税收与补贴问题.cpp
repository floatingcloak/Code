#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 10000007

using namespace std;

const int Maxn = 101000;

int n, m = 0, c[Maxn], d[Maxn], re, mx, mi, yy;

int main() {
	// freopen("t.in", "r", stdin);
	// freopen("t.out", "w", stdout);
	scanf("%d%d%d", &n, &c[0], &yy);
	d[c[0]] = yy;
	int x, y; scanf("%d%d", &x, &y);
	while(x != -1 && y != -1) {
		c[++m] = x; d[x] = y; scanf("%d%d", &x, &y);
	}
	sort(c + 0, c + m + 1); mi = c[0], mx = c[m];
	for(int i = 0; i < m; ++i) {
		int delta = (d[c[i + 1]] - d[c[i]]) / (c[i + 1] - c[i]);
		int temp = d[c[i]] + delta;
		for(int j = c[i] + 1; j < c[i + 1]; ++j) {
			d[j] = temp;
			temp += delta;
		}
	}
	scanf("%d", &re); int ll = 0;
	for(int i = mx + 1; ; ++i) {
		if(d[mx] - (i - mx) * re <= 0) {
			ll = i;
			break;
		}
		d[i] = d[mx] - (i - mx) * re;
	}
	for(int ii = 0; ; ++ii) {
		int i = ii;
		int ans = -INF, k = 0;
		for(int j = mi; j <= ll; ++j) {
			if((j + i - c[0]) * d[j] >= ans) {
				ans = (j + i - c[0]) * d[j];
				k = j;
			}
		}
		if(k == n) {
			printf("%d\n", ii);
			// while(1);
			return 0;
		}
		i = -ii;
		ans = -INF, k = 0;
		for(int j = mi; j <= ll; ++j) {
			if((j + i - c[0]) * d[j] >= ans) {
				ans = (j + i - c[0]) * d[j];
				k = j;
			}
		}
		if(k == n) {
			printf("-%d\n", ii);
			// while(1);
			return 0;
		}
	}
	puts("NO SOLUTION");
	// while(1);
	return 0;
}
/*
4011
1 799990
7999 10
-1 -1
10
*/