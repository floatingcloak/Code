#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10100;

typedef long long ll;

ll b, pd = -1;
int n, c[Maxn], vv[Maxn], s, tot, cnt = 1, st;
int vis[140000];

void print(int x) {
	int d[65] = {0}, t = 0;
	while(x) {
		++t;
		printf("%d\n", x & 1);
		x >>= 1;
	}	
	if(t < n) {
		for(int i = 1; i <= n - t; ++i) cout << 0 << endl;		
	}
}

void print2(int x) {
	int d[65] = {0}, t = 0;
	while(x) {
		++t;
		printf("%d ", x & 1);
		x >>= 1;
	}
if(t < n) {
		for(int i = 1; i <= n - t; ++i) cout << 0 << ' ';		
	}
	cout << endl;
}

int main() {
	freopen("test.in", "r", stdin);
	scanf("%d%lld", &n, &b);
	memset(vis, -1, sizeof(vis));
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		s |= (1 << (i - 1)) * x;
	}
//	print2(s);
	vis[s] = 0;
	vv[cnt] = s;
	ll cnt = 1;
	for(int i = 1; i <= b; ++i) {
		tot = 0;
		for(int j = 1; j <= n; ++j) {
			int v = s & (1 << (j - 1));
			if(v != 0) c[++tot] = (j == n) ? 1 : (j + 1);
		}
		for(int j = 1; j <= tot; ++j) {
			s ^= (1 << (c[j] - 1));
		}
//		print2(s);
		if(vis[s] != -1) {
			st = vis[s];
			pd = i;
			break;
		}
		vv[++cnt] = s;
		vis[s] = i;
	}
	if(pd == -1) {
		print(s);	
	}
	else {
		pd -= (st);
		ll id = (b - st) % (pd);
//		cout << cnt << endl;	
//		cout << '!';
		print(vv[st + id + 1]);
//		for(int i = 1; i <= cnt; ++i) {
//			print2(vv[i]);
//		}
	}
	return 0;
}
