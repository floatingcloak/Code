#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1e9 + 7

using namespace std;

const int Maxn = 20;
const int N = 10100;

struct node {
	int next,val,to;
} e[6000010];

char s[Maxn];
bool vis[Maxn][Maxn];
int n,m,d,S,T,ans,tot = 1,dis[N],h[N],map[Maxn][Maxn];

int abs(int x) {return x < 0 ? -x : x;}

void Link(int u,int v,int c) {
	e[++tot].next = h[u];
	e[tot].to = v;
	e[tot].val = c;
	h[u] = tot;
}

void Add(int u,int v,int c) {Link(u,v,c); Link(v,u,0);}

int num(int i,int j,int k) {
	return ((k - 1) * n * m	) + (i - 1) * m + j;
}

void renum(int x) {
	if(x == S) printf("S\n");
	else if(x == T) printf("T\n");
	else {
		int k = x / (n * m) + 1;
		int i = ((x - (k - 1) * (n * m)) / m) + 1;
		int j = x - (((k - 1) * n * m) + (i - 1) * m);
		printf("%d %d %d\n",i,j,k);
	}
}

int Bfs() {
	queue <int> Q;
	memset(dis,0,sizeof(dis));
	dis[S] = 1; Q.push(S);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(!dis[v] && e[i].val) {
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
	}
	return dis[T];
}

int Dfs(int u,int p){
    if(u == T) return p;
    int w,used = 0;
    for(int i = h[u]; i; i = e[i].next){
        int v = e[i].to;
        if(e[i].val && dis[v] == dis[u] + 1){
            w = p - used;
            w = Dfs(v, min(w, e[i].val));
            used += w;
            e[i].val -= w;
            e[i ^ 1].val += w;
            if(used == p)return used;
        }
    }
	if(!used) dis[u] = 0;
    return used;
}

int main() {
//	freopen("t.in","r",stdin);
	scanf("%d%d%d",&n,&m,&d); T = n * m * 2 + 1;
	for(int i = 1; i <= n; ++i) {
		scanf("%s",(s + 1));
		for(int j = 1; j <= m; ++j) {
			int x = s[j] - '0';
			Add(num(i, j, 2), num(i, j, 1), x);
			map[i][j] = tot - 1;
			if(i - 1 < d || n - i < d || j - 1 < d || m - j < d) {
				Add(num(i, j, 1), T, INF);
//				vis[i][j] = 1;
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%s",(s + 1));
		for(int j = 1; j <= m; ++j) {
			if(s[j] == 'L') {
				++sum;
				Add(S, num(i, j, 2), 1);

			}				
			for(int k = 1; k <= n; ++k) {
				for(int l = 1; l <= m; ++l) {
					if(i == k && l == j) continue;
					if(abs(k - i) + abs(l - j) <= d) {
						Add(num(i, j, 1), num(k, l, 2), INF);
					}
				}
			}
		}
	}
//	printf("%d\n",sum);
	while(Bfs() != 0) {
//		for(int i = 1; i <= n; ++i) {
//			for(int j = 1; j <= m; ++j) {
//				int u = map[i][j];
//				printf("%5d",e[u].val);
//			}
//			printf("\n");
//		}
//		printf("\n");
		sum -= Dfs(S, INF);
	}
	printf("%d\n",sum);
	return 0;
}
