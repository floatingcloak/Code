#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 2000000007

using namespace std;

const int Maxn = 110, M = 101000;

struct node {
	int next, v;	
} e[M];

int dx[5] = {0, -1, 0, 0, 1};
int dy[5] = {0, 0, -1, 1, 0};
int n, tot, dis[M], tt, h[M], pre[M], st, ed;
int x1[M], y1[M], num[Maxn][Maxn];
bool vis[M];

void Add(int u, int v) {
	e[++tt].v = v; e[tt].next = h[u];
	h[u] = tt;
}

void Spfa() {
	queue <int> Q;
	for(int i = 0; i <= tot; ++i) dis[i] = INF;
	Q.push(st); dis[st] = 0; vis[st] = 1;
	while(!Q.empty()) {
		int u = Q.front(); vis[u] = 0; Q.pop();
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].v, c;
			if(v == u) continue;
			if(u == st) {
				c = 0;
			}
			else {
				int kk = pre[u];
				if(x1[kk] == x1[u]) {
					if(x1[v] == x1[kk]) c = 0;
					else if(y1[v] == y1[u]) c = 1;
//					else cout << '1';
				}
				else if(y1[kk] == y1[u]){
					if(y1[v] == y1[kk]) c = 0;
					else if(x1[v] == x1[u]) c = 1;
//					else cout << '!';
				}
//				else cout << '!';
			}
//			cout << c << endl;
			if(dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				pre[v] = u;
				if(!vis[v]) {
					vis[v] = 1;
					Q.push(v);	
				}
			}
		}
	}
}

//char map[Maxn][Maxn];

int main() {
//	freopen("test.in", "r", stdin);
	memset(pre, -1, sizeof pre);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			char ch; cin >> ch; 
//			map[i][j] = ch;
			if(ch != 'x') {
				num[i][j] = ++tot;
				x1[tot] = i; y1[tot] = j;
				if(ch == 'A') st = tot;
				if(ch == 'B') ed = tot;
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int k = num[i][j];
			if(k) {
				for(int l = 1; l <= 4; ++l) {
					int xx = i + dx[l], yy = j + dy[l];
					if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && num[xx][yy] != 0) {
						Add(k, num[xx][yy]);
					}
				}
			}
		}
	}
	Spfa();
	if(dis[ed] != INF) printf("%d\n", dis[ed]);
	else printf("-1\n");
//	int now = ed;
//	while(now != st) {
//		map[x1[now]][y1[now]] = '@';
//		now = pre[now];	
//	}
//	for(int i = 1; i <= n; ++i) {
//		for(int j = 1; j <= n; ++j) cout << map[i][j] << ' ';
//		cout << endl;	
//	}
	return 0;
}
