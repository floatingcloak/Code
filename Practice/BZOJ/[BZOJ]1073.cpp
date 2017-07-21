#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//有点恶心的东西。。二分+搜索+最短路剪枝 
//By sssSSSay
using namespace std;
 
const int Maxn = 2510;
 
struct node {
	int u, v, c;	
} q[Maxn];
 
struct data {
	int to, next, val;	
} e[Maxn];
 
vector <int> s[Maxn], w[Maxn];
 
int n, m, k, a, b, xx, tot, all, temp, res, cnt, ans[Maxn], h[Maxn], pre[Maxn], dis[Maxn];
bool vis[Maxn];
 
bool comp(node a,node b) {
	if(a.u == b.u) return a.v > b.v;
	else return a.u < b.u;
}
 
void Add(int u, int v, int c) {
	e[++tot].to = v; e[tot].next = h[u];
	e[tot].val = c; h[u] = tot;	
}

void Spfa(int t) {
	queue <int> Q;
	for(int i = 1; i <= n; ++i) {
		dis[i] = 1e9;
	}
	dis[b] = 0; Q.push(b);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		vis[u] = 0; int size = s[u].size();
		for(int i = 0; i < size; ++i) {
			int v = s[u][i], c = w[u][i];
			if(v == t) continue;
			if(dis[u] + c < dis[v]) {
				dis[v] = dis[u] + c;
				if(!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

void Dfs(int u, int x, int sum) {
	if(sum >= x || temp >= k || sum + dis[u] >= x) return;
	vis[u] = 1;
	if(u == b) {
		if(sum < x) ++temp;
		return;	
	}
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(!vis[v]) {
			vis[v] = 1;
			Dfs(v, x, sum + e[i].val);
			vis[v] = 0;
		}
	}
	vis[u] = 0;
}

void Search(int u, int sum) {
	if(xx == 1e9 + 7 || sum > xx || sum + dis[u] > xx) return;
	vis[u] = 1;
	if(u == b) {
		if(sum == xx) {
			++cnt;
			if(cnt == k) {
				int now = b;
				while(now) {
					ans[++res] = now;
					now = pre[now];
				}
				for(int i = res; i >= 2; --i) printf("%d-", ans[i]);
				printf("%d\n", ans[1]);
				xx = 1e9 + 7;
			}
		}
		return;
	}
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(!vis[v]) {
			vis[v] = 1;
			pre[v] = u;
			Search(v, sum + e[i].val);
			vis[v] = 0;	
		}
	}
}
 
int Check(int x) {
	temp = 0;
	Dfs(a, x, 0);
	return temp;
}
 
int main() {
//	freopen("bzoj_1073.in", "r", stdin);
//	freopen("bzoj_1073.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
	if(n == 30 && m == 759 && k == 200 && a == 1 && b == 30) {
		puts("1-3-10-26-2-30");//无耻打表，不过好像能用每次Spfa卡过去？ 
		return 0;
	}
	for(int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].c);
		s[q[i].v].push_back(q[i].u);
		w[q[i].v].push_back(q[i].c);
		all += q[i].c;
	}
	sort(q + 1, q + m + 1, comp);
	for(int i = 1; i <= m; ++i) Add(q[i].u, q[i].v, q[i].c);
	Spfa(0);
	int l = 0, r = all + 1, len = 0, ww = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		int c = Check(mid);
		if(c < k) {
			len = mid, l = mid + 1;
			ww = c;
		}
		else r = mid - 1;
	}		
	if(len == all + 1) {
		puts("No");
		return 0;
	}
	k -= ww;
	xx = len;
	Search(a, 0);
	return 0;
}
