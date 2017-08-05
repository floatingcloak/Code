#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101010;

int n, a[Maxn], ans, sum;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i < n; ++i) {
		if(a[i] + 1 == a[i + 1]) {
			if(sum == 0) sum = 2;
			else ++sum;
		}
		else sum = 0;
		ans = max(ans, sum);
	}
	printf("%d\n", ans == 0 ? 1 : ans);
	// for(;;);
	return 0;
}