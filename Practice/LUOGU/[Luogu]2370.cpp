#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101010;

int t, n, p, s, w[Maxn], lim, v[Maxn], dp[Maxn], c[Maxn], b[Maxn];

inline char NC(void) {
	static char buf[100000], *p1 = buf, *p2 = buf;
	if (p1 == p2) {
		p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
		if (p1 == p2) return EOF;
	}
	return *p1++;
}
 
inline int read() {
    static char c; c = NC(); int x;
    static int minus; minus = 1;
    for (x = 0; !(c >= '0' && c <= '9'); c = NC()) if(c == '-') minus = -1;
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = NC()); x *= minus;
    return x;
}

bool Check(int x) {
	t = 0;
	for(int i = 1; i <= n; ++i) {
		if(w[i] <= x) b[++t] = w[i], c[t] = v[i];
	}
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= t; ++i) {
		for(int j = s; j >= b[i]; --j) {
			dp[j] = max(dp[j], dp[j - b[i]] + c[i]);
		}
	}
	if(dp[s] >= p) return true;
	else return false;
}

int main() {
	scanf("%d%d%d", &n, &p, &s);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &w[i], &v[i]);
		lim = max(lim, w[i]);
	}
	int l = 0, r = lim, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(Check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	if(ans == 0) puts("No Solution!");
	else printf("%d\n", ans);
	// for(;;);
	return 0;
}