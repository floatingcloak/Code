#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1000000;

int n, m, a[Maxn];

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= m; ++i) printf("%d\n", a[i]);
	return 0;
}
