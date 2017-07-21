#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 51;

typedef long long ll;

bool map[Maxn][Maxn];
int n, m, sx, st;
ll dp[Maxn][Maxn];
int dx[9] = {0, 1, -1, 2, -2, 1, -1, 2, -2};
int dy[9] = {0, 2, 2, 1, 1, -2, -2, -1, -1};

int main() {
	scanf("%d%d%d%d" , &n, &m, &sx, &st);
	++n, ++m, ++sx, ++st;
	map[sx][st] = 1;
	for(int i = 1; i <= 8; ++i) map[sx + dx[i]][st + dy[i]] = 1;
	dp[0][1] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(!map[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	printf("%lld\n", dp[n][m]);
	return 0;
}
