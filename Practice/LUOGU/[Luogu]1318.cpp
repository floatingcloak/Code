#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10010;

int n, i, a[Maxn], ans;

int main() {
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(i = 0; i <= n;) {
		int now = i;
		while(a[now] == a[now + 1] && now <= n) ++now;
		while(a[now + 1] < a[now] && now <= n) ++now;
		while(a[now] == a[now + 1] && now <= n) ++now;
		while(a[now] < a[now + 1] && now <= n) ++now;
		int lim = min(a[i], a[now]);
		for(int j = i + 1; j < now; ++j) {
			ans += max(0, lim - a[j]);
			a[j] = lim;
		}
		int cc = now;
		if(a[now] < a[i]) {
			int h = -1, kk = 0;
			while(now <= n) {
				if(a[now] <= a[i] && a[now] > lim) {
					if(a[now] > h) {
						h = a[now];
						kk = now;
					}
				}++now;
			}
			if(h != -1) {
				for(int j = i + 1; j < kk; ++j) ans += max(0, a[kk] - a[j]);
				now = kk;
			}
			else now = cc;
		}
		i = now;
	}
	printf("%d\n", ans);
	return 0;
} 