#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 110;

int fa[Maxn],n,m,T;

int find(int x){return fa[x] == x ? x :fa[x] = find(fa[x]); }

int main(){
	freopen("HWnetbar.in","r",stdin);
	freopen("HWnetbar.out","w",stdout);
	scanf("%d",&T);
	while(T--){int ans = 0;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++)fa[i] = i;
		for(int i = 1;i <= m;i++){
			int u,v;scanf("%d%d",&u,&v);
			int r1 = find(u),r2 = find(v);
			if(r1 != r2)fa[r1] = r2;	
		}
		for(int i = 1;i <= n;i++)if(fa[i] == i)ans++;
		printf("%d\n",ans - 1);
	}return 0;
}
