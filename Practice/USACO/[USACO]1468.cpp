#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 301;

char str[Maxn], s[201000], a[Maxn][Maxn];
bool dp[201000];
int n, b[Maxn];

int main() {
	// freopen("[USACO]1468.txt", "w", stdout);
	while(true) {
		scanf("%s", (str + 1));
		if(str[1] == '.') break;
		b[++n] = strlen(str + 1);
		for(int i = 1; i <= b[n]; ++i) {
			a[n][i] = str[i];
		}
	}
	int len = 0;
	while(scanf("%s", (str + 1)) != EOF) {
		int ll = strlen(str + 1);
		// printf("@%s\n", (str + 1));
		for(int i = 1; i <= ll; ++i) s[++len] = str[i];
		// memset(str, 0, sizeof str);
	}
	// cin >> (s + 1);
	// int len = strlen(s + 1);
	dp[0] = 1;
	for(int i = 0; i <= len; ++i) {
		if(dp[i] == 1) {
			for(int j = 1; j <= n; ++j) {
				if(i + b[j] > len) continue;
				int l = i + 1, r = 1, pd = 0;
				while(r <= b[j] && i <= len) {
					if(s[l] != a[j][r]) {
						pd = 1;
						break;
					}
					++l, ++r;
				}
				if(pd == 0) dp[i + b[j]] = 1;
			}
		}
	}
	int ans = 0;
	// printf("%s\n", (s + 1));
	for(int i = 1; i <= len; ++i) if(dp[i] == 1) ans = i;
	printf("%d\n", ans);
	// while(1);
	return 0;
}