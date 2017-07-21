#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 1000000000

using namespace std;

const int Maxn = 101000;

int n, m, a[Maxn];

bool Check(int x) {
	int tot = 0, now = INF;
	for(int i = 1; i <= n; ++i) {
		now += a[i] - a[i - 1];
		if(now >= x) {
			++tot;
			now = 0;
		}
	}
	if(tot >= m) return 1;
	else return 0;
}

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 0, r = INF, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(Check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
