#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

int map[Maxn][Maxn], n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	for(int i = n - 1; i >= 1; --i) {
		for(int j = 1; j <= i; ++j) {
			map[i][j] += max(map[i + 1][j], map[i + 1][j + 1]);
		}
	}
	printf("%d", map[1][1]);
	return 0;
}
