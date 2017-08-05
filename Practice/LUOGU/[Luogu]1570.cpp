#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define eps 1e-5

using namespace std;

const int Maxn = 1010;

double d[Maxn], c[Maxn];
int v[Maxn], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
	for(int i = 1; i <= n; ++i) {
		scanf("%lf", &c[i]);
		d[i] = c[i];
	}
	double l = 0, r = 10000.0, ans = 0.0;
	while(r - l > eps) {
		double mid = (l + r) / 2.0;
		for(int i = 1; i <= n; ++i) d[i] = d[i] * mid - 1.0 * v[i];
		sort(d + 1, d + n + 1);
		double temp = 0;
		for(int i = 1; i <= m; ++i) temp += d[i];
		if(temp >= 0) r = mid, ans = mid;
		else l = mid;
		for(int i = 1; i <= n; ++i) d[i] = c[i];
	}
	printf("%.3lf\n", ans);
	// for(;;);
	return 0;
}