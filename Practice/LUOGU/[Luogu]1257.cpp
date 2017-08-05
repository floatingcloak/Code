#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10101;

int n;
double x[Maxn], y[Maxn];

double Dis(double xx1, double xx2, double yy1, double yy2) {
	return sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &x[i], &y[i]);
	}
	double ans = 1e100;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) ans = min(ans, Dis(x[i], x[j], y[i], y[j]));
	}
	printf("%.4lf\n", ans);
	// for(;;);
	return 0;
}