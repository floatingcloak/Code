#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 101000;

typedef long long ll;

struct node {
	int to,next;	
} e[Maxn * 2];

int n,m,x,y,tot,lim = 10,h[Maxn];
ll dp[Maxn][12][5],q;

void Add(int u,int v) {
	e[++tot].to = v;
	e[tot].next = h[u];
	h[u] = tot;	
}

ll Get(ll x) {return x == 0 ? 0 : x % q ? x % q : x;}

void Dfs(int u,int fa) {
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(v != fa) Dfs(v,u);
	}
	for(int i = 0; i <= lim; ++i)dp[u][i][0] = 1;
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(v != fa) {
			for(int j = 0; j <= lim; ++j) {
				ll t,f1 = !j ? 0 : dp[v][j - 1][0] + dp[v][j - 1][1] + dp[v][j - 1][2];
				ll f2 = dp[v][j][0] + dp[v][j][1];
				t = dp[u][j][2] * f1 + dp[u][j][1] * f2;
				dp[u][j][2] = Get(t);
				t = dp[u][j][1] * f1 + dp[u][j][0] * f2;
				dp[u][j][1] = Get(t);
				t = dp[u][j][0] * f1;
				dp[u][j][0] = Get(t);
			}
		}
	}
}

int main() {
	scanf("%d%d%lld",&n,&m,&q);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d",&x,&y);
		Add(x,y); Add(y,x);	
	}
	if(m < n - 1) {printf("-1\n-1\n"); return 0;}
	Dfs(1,0); ll sum = 0;
	for(int i = 0; i <= lim; ++i) {
		if(sum = dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) {
			printf("%d\n%lld\n",i,sum % q);
			return 0;
		}
	}
	return 0;
}
