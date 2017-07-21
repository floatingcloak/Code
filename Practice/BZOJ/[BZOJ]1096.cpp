#include <cstdio>
#include <cstring>
#include <iostream>
//Ð±ÂÊDp 
//By sssSSSay 
using namespace std;

const int Maxn = 1010000;

typedef long long ll;

ll dp[Maxn], G[Maxn], S[Maxn], p[Maxn], x[Maxn], c[Maxn];
ll n, q[Maxn];

inline char NC(void) {
	static char buf[100000], *p1 = buf, *p2 = buf;
	if (p1 == p2) {
		p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
		if (p1 == p2) return EOF;
	}
	return *p1++;
}

inline ll read() {
    static char c; c = NC(); ll x;
    static ll minus; minus = 1;
    for (x = 0; !(c >= '0' && c <= '9'); c = NC()) if(c == '-') minus = -1;
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = NC()); x *= minus;
    return x;
}

ll Slope(ll j, ll i) {
	return ((dp[i] + G[i]) - (dp[j] + G[j])) / (S[i] - S[j]);
}

int main() {
//	freopen("storage.in", "r", stdin);
//	freopen("storage.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; ++i) {
		x[i] = read(); p[i] =read(); c[i] = read();
	}
	for(int i = 1; i <= n; ++i) {
		S[i] = S[i - 1] + p[i];
		G[i] = G[i - 1] + p[i] * x[i];
	}
	int h = 1, t = 1;
	for(int i = 1; i <= n; ++i)  {
		while(h < t && Slope(q[h], q[h + 1]) < x[i]) ++h;
		dp[i] = dp[q[h]] + c[i] + x[i] * (S[i - 1] - S[q[h]]) - (G[i - 1] - G[q[h]]);
		while(h < t && Slope(q[t], i) < Slope(q[t - 1], q[t])) --t;
		q[++t] = i;
	}
	printf("%lld\n", dp[n]);
	return 0;
}
