#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2010;

int n, m, x10[Maxn], y10[Maxn], x20[Maxn], y20[Maxn], x, y;

struct node {
	string s;
	int a, b;
} ans[Maxn];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d%d%d%d", &x10[i], &y10[i], &x20[i], &y20[i]);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y); ans[i].s = "NO";
		for(int j = 1; j <= n; ++j) {
			if(x >= x10[j] && x <= x20[j] && y >= y10[j] && y <= y20[j]) {
				ans[i].s = "YES"; ans[i].a = j; ++ans[i].b;
			}
		}
	}
	for(int i = 1; i <= m; ++i) {
		cout << ans[i].s;
		if(ans[i].s == "YES") {
			printf(" %d %d", ans[i].b, ans[i].a);
		} puts("");
	}
	return 0;
}
