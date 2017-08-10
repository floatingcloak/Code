#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1000000007

using namespace std;

const int Maxn = 1010;

int n, m, c, s[Maxn][Maxn], a[Maxn][Maxn], sum = -INF, ansx, ansy;

int main() {
	scanf("%d%d%d", &n, &m, &c);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	for(int i = 1; i <= n - c + 1; ++i) {
		for(int j = 1; j <= m - c + 1; ++j) {
			int l = i + c - 1, r = j + c - 1;
			int temp = s[l][r] - s[i - 1][r] - s[l][j - 1] + s[i - 1][j - 1];
			if(temp > sum) {
				sum = temp;
				ansx = i;
				ansy = j;
			}
		}
	}
	printf("%d %d\n", ansx, ansy);
	for(;;);
	return 0;
}