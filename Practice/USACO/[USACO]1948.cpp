#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 1000000007

using namespace std;

const int Maxn = 201000;

typedef long long ll;

struct node {
	int next, v; ll c;	
} e[Maxn];

int n, m, k, tot, dis[Maxn], h[Maxn];
bool vis[Maxn];
ll lim;

void Add(int u, int v, ll c) {
	e[++tot].v = v; e[tot].c = c;
	e[tot].next = h[u]; h[u] = tot;
}

int Spfa(ll mid) {
	queue <int> Q;
	for(int i = 1; i <= n; ++i) {
		dis[i] = INF;
		vis[i] = 0;
	}
	Q.push(1); vis[1] = 1; dis[1] = 0;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = 0;
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].v, c = (e[i].c > mid) ? 1 : 0;
			if(dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				if(!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
//	cout << mid << ' ' << dis[n] << endl;
	return dis[n];
}

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, x, y; i <= m; ++i) {
		ll z; scanf("%d%d%lld", &x, &y, &z);
		Add(x, y, z); Add(y, x, z); 
		lim = max(lim, z);
	}
	ll l = 0, r = lim, ans = 0;
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(Spfa(mid) > k) l = mid + 1;
		else r = mid - 1, ans = mid;
	}
	if(ans != 0) printf("%lld\n", ans);
	else puts("-1");
	return 0;
}
