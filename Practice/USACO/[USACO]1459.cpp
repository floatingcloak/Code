#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101;

int n, ans, b[Maxn];

int main() {
	scanf("%d", &n);
	for(int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		if(x == 1) ans += b[2] + b[3];
		else if(x == 2) ans += b[3];
		++b[x];
	}
	printf("%d\n", ans);
	while(1);
	return 0;
}