#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 2000000009

using namespace std;

const int Maxn = 210;

typedef long long ll;

struct data {
	int x; ll s;
};

struct node {
	int v, next; ll c;	
} e[Maxn];

int Case, n, m, h[Maxn], tot, jud;
ll dis[Maxn][21000], T, d;
bool vis[Maxn], f[Maxn][21000];

void Add(int u, int v, ll c) {
	e[++tot].v = v; e[tot].c = c;
	e[tot].next = h[u]; h[u] = tot;	
}

//void Spfa() {
//	for(int i = 1; i <= n; ++i) {
//		dis[i] = INF;
//		vis[i] = 0;
//	}
//	vis[1] = 1; dis[1] = 0ll;
//	int he = 1, t = 1; q[he] = 1;
//	while(he <= t) {
//		int u = q[he]; vis[n] = 0;
//		for(int i = h[u]; i; i = e[i].next) {
//			int v = e[i].v;
//			if(dis[u] + e[i].c < dis[v]) {
//				dis[v] = dis[u] + e[i].c;
//				if(!vis[v]) {
//					q[++t] = v;
//					vis[v] = 1;	
//				}
//			}
//		}
//		++he;
//	}
//}

void Spfa() {
	queue <data> Q;
	Q.push((data){1, 0});

	dis[1][0] = 0; f[1][0] = 1;
	while(!Q.empty()) {
		data qq = Q.front(); Q.pop();
		int u = qq.x; ll ss = qq.s; f[u][ss] = 0;
		for(int i = h[u]; i; i = e[i].next) {
			ll y = (ss + e[i].c) % d; int v = e[i].v;
			if(dis[u][ss] + e[i].c < dis[v][y]) {
				dis[v][y] = dis[u][ss] + e[i].c;
				if(f[v][y] == 0) {
					f[v][y] = 1;
					Q.push((data){v, y});	
				}
			}
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d", &Case);
	while(Case--) {
		memset(f, 0, sizeof f);
		memset(h, 0, sizeof h);
		memset(dis, 127, sizeof dis);
		scanf("%d%d%lld", &n, &m, &T); tot = 0;
		d = 200000007;
		for(int i = 1, x, y; i <= m; ++i) {
			ll z; scanf("%d%d%lld", &x, &y, &z);
			++x; ++y;
			Add(x, y, z); Add(y, x, z);	
			if(x == 1 || y == 1) d = min(d, z * 2);
		}
		if(d == 200000007) {
			puts("Impossible");	
			continue;
		}
		Spfa();
		if(dis[n][T % d] > T) puts("Impossible");
		else puts("Possible");
	}
	return 0;
}
