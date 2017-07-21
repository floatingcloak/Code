#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10100;

int n, m, cnt[15];

void Deal(int x) {
	while(x) {
		++cnt[x % 10];
		x /= 10;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = n; i <= m; ++i) Deal(i);
	for(int i = 0; i <= 9; ++i) printf("%d ", cnt[i]);
	// while(1);
	return 0;
}