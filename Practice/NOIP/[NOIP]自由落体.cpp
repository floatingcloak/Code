#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define eps 1e-4

using namespace std;

double h, s1, v, l, k;
int ans = 0, n;

int main() {
	// freopen("freefaller.in", "r", stdin);
	// freopen("freefaller.out", "w", stdout);
    scanf("%lf%lf%lf%lf%lf", &h, &s1, &v, &l, &k);
	cin >> n;
    double should = (h - k);
    for(int i = 0; i < n; ++i) {
        double t = sqrt((2 * should) / 10.0);
		double t1 = (s1 - (double)i) / v;
        double now = s1 - t * v;
		double delta = 5.0 * t1 * t1;
        double l1 = now, r1 = now + l;
		double pos = h - delta;
		// cout << l1 << ' ' << r1 << ' ' << pos << endl;
		// cout << l2 << ' ' << r2 << endl;
        if((i >= l1 - eps && i <= r1 + eps) || (pos >= -eps && pos <= k + eps)) ++ans;
    }
    cout << ans << endl;
    // cin >> ans;
	// for(;;);
    return 0;
}