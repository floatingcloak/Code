#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 26;

int n, a[Maxn], map[Maxn][Maxn], temp[Maxn], ans[Maxn], b[Maxn], m, res = 100;

inline char NC(void) {
	static char buf[1000001], *p1 = buf, *p2 = buf;
	if (p1 == p2) {
		p2 = (p1 = buf) + fread(buf, 1, 1000001, stdin);
    	if (p1 == p2) return EOF;
	}
	return *p1++;
}

inline void read(int &x) {
    static char c; c = NC();
    static int minus; minus = 1;
    for (x = 0; !(c >= '0' && c <= '9'); c = NC()) if(c == '-') minus = -1;
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = NC()); x *= minus;
}

void Dfs(int x, int sum) {
	if(sum >= res) return;
	int pd = 1;
	for(register int i = 1; i <= n; ++i) {
		if(temp[i] < a[i]) {
			pd = 0;
			break;
		}
	}
	if((x == m + 1) || (pd == 1)) {
		int pd = 1;
		for(register int i = 1; i <= n; ++i) {
			if(temp[i] < a[i]) {
				pd = 0;
				break;
			}
		}
		if(pd == 1) {
			if(sum < res) {
				res = sum;
				for(register int i = 1; i <= sum; ++i) ans[i] = b[i];
			}
		}
		return;
	}
	b[sum + 1] = x;
	for(register int i = 1; i <= n; ++i) temp[i] += map[x][i];
	Dfs(x + 1, sum + 1);
	for(register int i = 1; i <= n; ++i) temp[i] -= map[x][i];
	Dfs(x + 1, sum);
}

int main() {
	// freopen("t.in", "r", stdin);
	// scanf("%d", &n);
	read(n);
	for(register int i = 1; i <= n; ++i) read(a[i]);
	read(m);
	for(register int i = 1; i <= m; ++i) {
		for(register int j = 1; j <= n; ++j) read(map[i][j]);
	}
	Dfs(1, 0);
	printf("%d ", res);
	for(register int i = 1; i <= res; ++i) printf("%d ", ans[i]);
	// while(1);
	// cin >> n;
	return 0;
}