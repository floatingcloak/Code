#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 101010;

int n, m, x, a[Maxn];

map <int, int> hs;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &x);
		hs[x] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		if(hs[a[i]]) printf("%d ", a[i]);
	}
	puts("");
	// for(;;);
	return 0;
}