#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		printf("%d\n", x - (x / 7) - (x / 70) - (x / 700) - (x / 7000) - (x / 70000) - (x / 700000) - (x / 7000000) - (x / 70000000) - (x / 700000000));
	}
	return 0;
}
