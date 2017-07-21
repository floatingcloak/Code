#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

int L, n, ans1, ans2;

int main() {
	scanf("%d", &L);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		int d1 = x, d2 = L + 1 - x;
		ans1 = max(ans1, min(d1, d2));
		ans2 = max(ans2, max(d1, d2));
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
