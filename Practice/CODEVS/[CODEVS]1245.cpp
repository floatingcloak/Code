#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 101001;

struct node {
	int c, l, r;
};

map <int, map<int, int> > vis; 

priority_queue <node> Q;

int n, a[Maxn], b[Maxn];

bool operator < (node a,node b) {
	return a.c > b.c;
}

inline char NC(void) {
	static char buf[1000000], *p1 = buf, *p2 = buf;
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
	n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	for(int i = 1; i <= n; ++i) b[i] = read();
	sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
	Q.push((node){a[1] + b[1], 1, 1});
	while(n--) {
		node t = Q.top(); Q.pop();
		printf("%d ", t.c);
		if(!vis[t.l + 1][t.r]) {
			Q.push((node){a[t.l + 1] + b[t.r], t.l + 1, t.r});
			vis[t.l + 1][t.r] = 1;
		}
		if(!vis[t.l][t.r + 1]) {
			Q.push((node){a[t.l] + b[t.r + 1], t.l, t.r + 1});
			vis[t.l][t.r + 1] = 1;
		}
	}
	return 0;
}
