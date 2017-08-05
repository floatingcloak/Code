#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1010107777

using namespace std;

const int Maxn = 5100;

int n, s, p[Maxn], t[Maxn], v[Maxn], f[Maxn], g[Maxn], w[Maxn];

int main() {
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; ++i) {
		f[i] = INF;
		scanf("%d%d", &t[i], &v[i]);
		w[i] = w[i - 1] + t[i];
		p[i] = p[i - 1] + v[i];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < i; ++j) {
			f[i] = min(f[i], f[j] + s * (p[n] - p[j]) + w[i] * (p[i] - p[j]));
		}
	}
	printf("%d\n", f[n]);
	// for(;;);
	return 0;
}