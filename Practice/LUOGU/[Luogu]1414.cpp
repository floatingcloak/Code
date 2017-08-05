#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010000;

int n, a[Maxn], ans[Maxn], x, k, Max;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		++a[x]; Max = max(Max, x);
	}
	for(int i = 1; i <= Max; ++i) {
		int cnt = 0;
		for(int j = 1; i * j <= Max; ++j) {
			cnt += a[i * j];
		}
		for(int j = 1; j <= cnt; ++j) {
			ans[j] = max(ans[j], i);
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	// for(;;);
	return 0;
}