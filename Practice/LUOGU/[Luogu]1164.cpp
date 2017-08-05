#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10100;

typedef long long ll;

int n, m, a[Maxn];
ll dp[Maxn];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	dp[0] = 1ll;
	for(int i = 1; i <= n; ++i) {
		for(int j = m; j >= a[i]; --j) {
			dp[j] += dp[j - a[i]];
		}
	}
	printf("%lld\n", dp[m]);
	// for(;;);
	return 0;
}