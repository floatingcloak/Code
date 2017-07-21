#include <cstdio>
#include <cstring>
#include <iostream>
//环套树！基环外向树！每个联通块有且仅有一个环，所以只找出来环直接DP 
using namespace std;

const int Maxn = 1111000;

typedef long long ll;

struct node {
	int to,next,from;
} e[Maxn * 2];

int n,tot = 1,h[Maxn],back,vis[Maxn];
ll a[Maxn],dp[Maxn][2],ans;

void Add(int u,int v) {
	e[++tot].to = v;
	e[tot].from = u;
	e[tot].next = h[u];
	h[u] = tot;
}

void Dfs(int u,int last) {
	vis[u] = 1;
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(i != last) {
			if(vis[v]) back = i;
			else Dfs(v,i ^ 1);	
		}
	}
}

ll Dp(int u,int last,int k) {
	if(dp[u][k])return dp[u][k];
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(i != last && i != back && i != (back ^ 1)) {
			if(!k) {
				dp[u][k] += max(Dp(v,i ^ 1,0) , Dp(v,i ^ 1,1) + a[v]);
			}
			else dp[u][k] += Dp(v,i ^ 1,0);//沙茶写成了last ^ 1然后就RE了... 
		}
	}
	return dp[u][k];
}

int main() {
//	freopen("bzoj_1040.in","r",stdin);
//	freopen("bzoj_1040.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%lld%d",&a[i],&x);
		Add(i,x);Add(x,i);
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			Dfs(i,0);
			ll maxx = 0;
			memset(dp,0,sizeof(dp));
			maxx = max(maxx,Dp(e[back].from,0,0));//强制其不选的方案、、 
			memset(dp,0,sizeof(dp));
			maxx = max(maxx,Dp(e[back].to,0,0));
			ans += maxx;
		}
	}
	
	printf("%lld\n",ans);
	return 0;
}

