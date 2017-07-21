#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10100;

int l, n, x, y, a[Maxn], b[Maxn], ans;

int main() {
	scanf("%d%d", &l, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &x, &y);
		a[x]++; b[y]++;
	}
	int temp = 0;
	for(int i = 1; i <= l; ++i) {
		temp += a[i];
		if(temp == 0) ++ans;
		temp -= b[i];
	}
	printf("%d\n", ans);
	return 0;
}
