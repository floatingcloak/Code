#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 200000007

using namespace std;

const int Maxn = 110;

int n, a[Maxn], dp1[Maxn][Maxn], dp2[Maxn][Maxn];

int DfsMin(int l, int r) {
	if(l == r) return a[l];
	if(dp1[l][r] != INF) return dp1[l][r];
	int temp = INF;
	for(int i = l; i < r; ++i) {
		temp = min(temp, DfsMin(l, i) + DfsMin(i + 1, r));
	}
	return dp1[l][r] = temp;
}

int DfsMax(int l, int r) {
	if(l == r) return a[l];
	if(dp2[l][r] != 0) return dp2[l][r];
	int temp = 0;
	for(int i = l; i < r; ++i) {
		temp = max(temp, DfsMax(l, i) + DfsMax(i + 1, r));
	}
	return dp2[l][r] = temp;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) dp1[i][j] = INF;
	}
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	printf("%d\n%d\n", DfsMin(1, n), DfsMax(1, n));
	for(;;);
	return 0;
}