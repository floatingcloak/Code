#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010100;

int n, m, a[Maxn], l[Maxn], r[Maxn], d[Maxn], b[Maxn], c[Maxn];

bool Check(int x) {
	int temp = 0; memcpy(b, c, sizeof c);
	for(int i = 1; i <= x; ++i) b[l[i]] -= d[i], b[r[i] + 1] += d[i];
	for(int i = 1; i <= n; ++i) {
		temp += b[i];
		// cout << temp << ' ';
		if(temp < 0) {
			// cout << endl;
			return false;
		}
	}
	// cout << endl;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i] - a[i - 1]; c[i] = b[i];
	}
	for(int i = 1; i <= m; ++i) scanf("%d%d%d", &d[i], &l[i], &r[i]);
	int l = 0, r = m, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(Check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	if(ans == m) puts("0");
	else printf("-1\n%d\n", ans + 1);
	for(;;);
	return 0;
}