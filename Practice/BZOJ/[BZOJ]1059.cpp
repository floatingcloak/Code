#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int T,n,x,tot,ans;
int li[210],h[210],map[210][210];
bool v[210];

bool Dfs(int u) {
	for(int i = 1; i <= n; ++i) {
		if(!v[i] && map[u][i]) {
			v[i] = 1;
			if(!li[i] || Dfs(li[i])) {
				li[i] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	 freopen("qmatrix.in","r",stdin);
	 freopen("qmatrix.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		ans = 0;tot = 0;int pd = 0;
		memset(map,0,sizeof(map));
		memset(li,0,sizeof(li));
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				scanf("%d",&x);
				if(x == 1) map[i][j] = 1;
			}
		}
		for(int i = 1; i <= n; ++i) {
			memset(v,0,sizeof(v));
			if(!Dfs(i)) {
				pd = 1;
				break;
			}
		}
		if(pd == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
