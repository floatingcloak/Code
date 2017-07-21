#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 310;

int m, c, s, b[Maxn], a[Maxn], cnt = 0, temp;

int main() {
	scanf("%d%d%d", &m, &s, &c);
	for(int i = 1; i <= c; ++i) {
		int x; scanf("%d", &x);
		b[x] = 1;
	}
	for(int i = 1; i <= s; ++i) {
		if(temp != 0 && b[i] == 1) {
			a[++cnt] = temp;
			temp = 0;
		}
		if(b[i] == 0) ++temp;
		// printf("%d\n", temp);
	}
	int now = cnt + 1;
	if(b[1] != 1) --now;
	// printf("@@@%d\n", now);
	int ans = c; if(cnt != 1) a[1] = 40000000;
	// for(int i = 1; i <= cnt; ++i) printf("%d ", a[i]);
	// puts("");
	sort(a + 1, a + cnt + 1); a[0] = 0;
	// for(int i = 1; i <= cnt; ++i) printf("%d ", a[i]);
	// puts("");
	for(int i = 1; i <= cnt; ++i) a[i] += a[i - 1];
	if(now > m) printf("%d\n", ans + a[now - m]);
	else printf("%d\n", ans);
	// while(1);
	return 0;
}
