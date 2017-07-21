#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

int n, s, a[Maxn];

int main() {
	scanf("%d%d", &n, &s);
	int nn = 0;
	for(int i = s + 1; ; ++i) {
		int cnt = 0;
		for(int j = 2; j <= 10; ++j) {
			int tot = 0, x = i;
			while(x) {
				a[++tot] = x % j;
				x /= j;
			}
			int pd = 0;
			for(int k = 1; k <= (tot >> 1); ++k) {
				if(a[k] != a[tot - k + 1]) {
					pd = 1; break;
				}
			}
			if(pd == 0) ++cnt;
		}
		if(cnt >= 2) {
			printf("%d\n", i);
			++nn;
			if(n == nn) return 0;
		}
	}
	return 0;
}
