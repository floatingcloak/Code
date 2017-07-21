#include <cstdio>
#include <cstring>
#include <iostream>

#define INF -2139062144.0

using namespace std;

const int Maxn = 110;

int n, k, pre[Maxn];
double c[Maxn], dp[Maxn][42500];

int Add(int s, int x) {
	return s |= (1 << (x - 1));
}

int Get(int s, int x) {
	return s & (1 << (x - 1));
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1, x = 1; i <= k; ++i) {
		scanf("%lf", &c[i]);
		while(true) {
			scanf("%d", &x);
			if(x == 0) break;
			pre[i] = Add(pre[i], x);
		}
	}
	int all = (1 << k) - 1;
	for(int i = n; i >= 1; --i) {
		for(int s = 0; s <= all; ++s) {
			double &r = dp[i][s];
			for(int p = 1; p <= k; ++p) {
				if((pre[p] & s) == pre[p]) {
					r += max(dp[i + 1][s], dp[i + 1][Add(s, p)] + c[p]);
				}
				else r += dp[i + 1][s];
			}
			r /= (double)k;
		}
	}
	printf("%.6lf", dp[1][0]);
	// while(1);
	return 0;
}