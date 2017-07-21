#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010000;

int n, T, a[Maxn], g[Maxn], f[Maxn], ans, sum;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		memset(g, 0, sizeof g); sum = 0;
		memset(f, 0, sizeof f); ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j < i; ++j) {
				if(a[i] > a[j]) {
					
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(f[i] == ans) ++sum;
//			cout << f[i] << ' ';
		}
		puts("");
		printf("%d %d\n", ans, sum);
	}
	return 0;
}
