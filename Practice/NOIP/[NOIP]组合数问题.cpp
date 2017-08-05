#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 2001;

int ans[Maxn][Maxn], n[10001], m[10001], lim, t, k, lim2;
int C[Maxn][Maxn];

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

int main() {
	freopen("problem.in", "r", stdin);
	freopen("problem.out", "w", stdout);
	t = read(); k = read();
	for(register int i = 1; i <= t; ++i) {
		n[i] = read(); m[i] = read();
		lim = max(lim, n[i]); lim2 = max(lim2, m[i]);
	}
	int temp = 0;
	for(register int i = 0; i <= lim; ++i) {
		temp = 0;
		for(register int j = 0; j <= i; ++j) {
			if(j == 0) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
			temp += (C[i][j] == 0);
			ans[i][j] = ans[i - 1][j] + temp;
		}
		for(register int j = i + 1; j <= lim2; ++j) ans[i][j] = ans[i - 1][j] + temp;
	}
	for(register int i = 1; i <= t; ++i) printf("%d\n", ans[n[i]][m[i]]);
	return 0;
}