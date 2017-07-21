#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 500000000007ll

using namespace std;

const int Maxn = 10100;

typedef long long ll;

struct node {
	int v, next;
	ll c;
} e[Maxn];

int n, m, h[Maxn], tot = 1, pre[Maxn];
ll dis[Maxn], ans;
bool vis[Maxn];

void Add(int u, int v, ll c) {
	e[++tot].v = v; e[tot].next = h[u];
	e[tot].c = c; h[u] = tot;	
}

void Spfa(bool p) {
	queue <int> Q;
	for(int i = 1; i <= n; ++i) {
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[1] = 0ll; vis[1] = 1; Q.push(1);
	
	while(!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = 0;
//		cout << u << endl;
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].v;
//			cout << v << endl;
			if(dis[u] + e[i].c < dis[v]) {
				dis[v] = dis[u] + e[i].c;
				if(p == 1) pre[v] = i;
				if(!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x, y; ll z; scanf("%d%d%lld", &x, &y, &z);
		Add(x, y, z); Add(y, x, z);
	}
	Spfa(1); ll now = dis[n];
//	for(int i = 1; i <= n; ++i) printf("%d\n", pre[i]);
	for(int u = n; pre[u] != 0; u = e[pre[u] ^ 1].v) {
		int k = pre[u];
		e[k].c *= 2; e[k ^ 1].c *= 2;
		Spfa(0);
		ll x = dis[n] - now;
		ans = max(x, ans);
		e[k].c /= 2; e[k ^ 1].c /= 2;
	}
	printf("%lld\n", ans);
	return 0;
}
