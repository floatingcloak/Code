#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 500010;

struct node {int to,next;}e[Maxn];

int deep[Maxn],fa[Maxn],a[Maxn],q[Maxn],low[Maxn],dfn[Maxn],h[Maxn],f[Maxn],n,m,ans,tot,tim;

int read(){
	int x=0; char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x;
}

void Add(int u,int v){e[++tot].to = v;e[tot].next = h[u];h[u] = tot;}

void Solve(int u,int v){
	int cnt = deep[v] - deep[u] + 1,he = 1,t = 1;q[1] = 1;
	for(int i = v;i != u;i = fa[i])a[cnt--] = f[i];
	a[1] = f[u];
	cnt = deep[v] - deep[u] + 1;
	for(int i = 1;i <= cnt;i++)a[i + cnt] = a[i];
	for(int i = 2;i <= cnt + (cnt >> 1);i++){
		if(i - q[he] > (cnt >> 1))he++;
		ans = max(ans,a[i] + a[q[he]] + i - q[he]);
		while(he <= t && a[q[t]] - q[t] <= a[i] - i)t--;
		q[++t] = i;
	}
	for(int i = 2;i <= cnt;i++)f[u] = max(f[u],a[i] + min(i - 1,cnt - i + 1));
}

void Dfs(int u){
	dfn[u] = low[u] = ++tim;
	for(int i = h[u];i;i = e[i].next){int v = e[i].to;
		if(v == fa[u])continue;
		if(!dfn[v]){
			deep[v] = deep[u] + 1;
			fa[v] = u;Dfs(v);
		}low[u] = min(low[u],low[v]);
		if(low[v] > dfn[u]){ans = max(ans,f[u] + f[v] + 1);f[u] = max(f[u],f[v] + 1);}
	}
	for(int i = h[u];i;i = e[i].next){int v = e[i].to;
		if(fa[v] != u && dfn[v] > dfn[u])Solve(u,v);
	}
}

int main(){
	n = read();m = read();
	for(int i = 1;i <= m;i++){
		int k,last = 0;k = read();
		for(int j = 1;j <= k;j++){
			int now;now = read();
			if(last != 0){Add(last,now);Add(now,last);}last = now;
		}
	}Dfs(1);
	printf("%d\n",ans);
	return 0;
}
