#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//第一问直接减标号lis
//第二问利用定理暴力枚举断点转移
//By sssSSSay 
#define INF (1ll << 50)

using namespace std;

typedef long long ll;

const int Maxn = 30100;

struct node {
	int to,next;	
} e[Maxn];

int n,h[Maxn],tot;
ll a[Maxn],b[Maxn],c1[Maxn],c2[Maxn],c[Maxn],g[Maxn],f[Maxn],ans;

void Add(int u,int v) {
	e[++tot].to = v;
	e[tot].next = h[u];
	h[u] = tot;	
}

bool comp(ll a,ll b) {return a <= b;}

int main() {
//	freopen("sequencec.in","r",stdin);
//	freopen("sequencec.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld",&a[i]);
		b[i] = a[i] - i;
	}
	a[++n] = INF;
	b[n] = a[n] - n;
	for(int i = 1; i <= n; ++i)c[i] = g[i] = INF;
	for(int i = 1; i <= n; ++i) {
		int k = lower_bound(g + 1,g + n + 1,b[i],comp) - g;
		f[i] = (ll)k;
		g[k] = b[i];
		ans = max(ans , f[i]);
	}
	printf("%lld\n",(ll)n - ans);
	b[0] = -INF;
	Add(0,0);
	for(int i = 1; i <= n; ++i) {
		int u = f[i] - 1;
		for(int j = h[u]; j; j = e[j].next) {
			int v = e[j].to;
			if(b[i] < b[v]) continue;
			c1[v - 1] = c2[v - 1] = 0;
			for(int k = v; k <= i; ++k) {
				c1[k] = abs(b[v] - b[k]);
				c2[k] = abs(b[k] - b[i]);
			}
			for(int k = v; k <= i; ++k) {
				c1[k] = c1[k - 1] + c1[k];
				c2[k] = c2[k - 1] + c2[k];	
			}
			for(int k = v; k <= i; ++k) {
				ll now = c1[k] - c1[v] + c2[i] - c2[k];
				c[i] = min(c[i] , c[v] + now);
			}
		}
		Add(f[i],i);
	}
	cout<<c[n]<<endl;
	return 0;
}
	
