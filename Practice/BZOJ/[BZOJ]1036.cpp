#include <cstdio>
#include <cstring>
#include <iostream>

#define lc (o << 1)
#define rc ((o << 1) + 1)
#define mid ((l + r) >> 1)
#define INF 1000000007

using namespace std;

const int Maxn = 35000;

struct node {int to,next;}e[Maxn * 3];

int n,h[Maxn],w[Maxn],q,vis[Maxn],son[Maxn],maxx[Maxn * 4],cnt,tot;
int top[Maxn],num[Maxn],bel[Maxn],deep[Maxn],sum[Maxn * 4],fa[Maxn];

void Add(int u,int v) {e[++tot].to = v; e[tot].next = h[u]; h[u] = tot;}

void Dfs1(int u) {
	son[u] = 1;vis[u] = 1;
	for(int i = h[u];i;i = e[i].next) {
		int v = e[i].to;
		if(!vis[v]) {
			deep[v] = deep[u] + 1;
			fa[v] = u; Dfs1(v);
			son[u] += son[v];
		}
	}
}

void Dfs2(int u,int c) {
	int k = 0;
	top[u] = c;
	num[u] = ++cnt;
	bel[cnt] = w[u];
	for(int i = h[u];i;i = e[i].next) {
		int v = e[i].to;
		if(deep[v] > deep[u] && son[v] > son[k]) k = v;
	}
	if(k == 0) return;
	Dfs2(k,c);
	for(int i = h[u];i;i = e[i].next) {
		int v = e[i].to;
		if(deep[v] > deep[u] && v != k) Dfs2(v,v);
	}
}

int Lca(int u,int v) {
	while(top[u] != top[v]) {
		deep[top[u]] < deep[top[v]] ? v = fa[top[v]] : u = fa[top[u]];
	}
	return deep[u] < deep[v] ? u : v;
}

void Update(int o) {
	sum[o] = sum[lc] + sum[rc];
	maxx[o] = max(maxx[lc] , maxx[rc]);	
}

void Build(int l,int r,int o) {
	if(l == r) {
		sum[o] = maxx[o] = bel[l];
		return;
	}
	Build(l,mid,lc);
	Build(mid + 1,r,rc);
	Update(o);
}

void Change(int l,int r,int o,int x,int c) {
	if(l == r) {
		sum[o] = maxx[o] = c;
		return;
	}
	if(x <= mid) Change(l,mid,lc,x,c);
	if(x > mid) Change(mid + 1,r,rc,x,c);
	Update(o);
}

int QueryMax(int l,int r,int o,int a,int b) {
	if(a <= l && b >= r) return maxx[o];
	if(b <= mid) return QueryMax(l,mid,lc,a,b);
	else if(a > mid) return QueryMax(mid + 1,r,rc,a,b);
	else return max(QueryMax(l,mid,lc,a,mid) , QueryMax(mid + 1,r,rc,mid + 1,b));
}

int QuerySum(int l,int r,int o,int a,int b) {
	if(a <= l && b >= r) return sum[o];
	if(b <= mid) return QuerySum(l,mid,lc,a,b);
	else if(a > mid) return QuerySum(mid + 1,r,rc,a,b);
	else return QuerySum(l,mid,lc,a,b) + QuerySum(mid + 1,r,rc,mid + 1,b);	
}

int SolveMax(int u,int v) {
	int Max = -INF;
	while(top[u] != top[v]) {
		if(deep[top[v]] > deep[top[u]]) {
			Max = max(QueryMax(1,cnt,1,num[top[v]],num[v]) , Max);
			v = fa[top[v]];
		}
		else {
			Max = max(QueryMax(1,cnt,1,num[top[u]],num[u]) , Max);
			u = fa[top[u]];
		}
	}
	if(deep[u] > deep[v])swap(u,v);
	return max(Max , QueryMax(1,cnt,1,num[u],num[v]));
}

int SolveSum(int u,int v) {
	int Sum = 0;
	while(top[u] != top[v]) {
		if(deep[top[v]] > deep[top[u]]) {
			Sum += QuerySum(1,cnt,1,num[top[v]],num[v]);
			v = fa[top[v]];
		}
		else {
			Sum += QuerySum(1,cnt,1,num[top[u]],num[u]);
			u = fa[top[u]];
		}
	}
	if(deep[u] > deep[v])swap(u,v);
	return Sum + QuerySum(1,cnt,1,num[u],num[v]);
}

int main(){
//	freopen("bzoj_1036.in","r",stdin);
//	freopen("bzoj_1036.out","w",stdout);
	scanf("%d",&n);
	
	for(int i = 1;i < n;++i) {
		int x,y;
		scanf("%d%d",&x,&y);	
		Add(x,y);
		Add(y,x);
	}
	
	Dfs1(1);
	for(int i = 1;i <= n;++i)scanf("%d",&w[i]);
	Dfs2(1,1);
	Build(1,cnt,1);
	
	scanf("%d",&q);
	
	for(int i = 1;i <= q;i++) {
		char s[7];int x,y;
		scanf("%s",s);
		scanf("%d%d",&x,&y);
		if(s[0] == 'C') Change(1,n,1,num[x],y);
		else if(s[0] == 'Q' && s[1] == 'M') {
			printf("%d\n",SolveMax(x,y));
		}
		else {
			printf("%d\n",SolveSum(x,y));
		}
	}
	
	return 0;
}
