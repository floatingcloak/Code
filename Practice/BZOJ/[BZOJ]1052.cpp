#include <cstdio>
#include <cstring>
#include <iostream>
//好像与枚举的顺序有关？不满足会WA？
//By sssSSSay 
#define INF 2e9 + 10

using namespace std;

const int Maxn = 21000;

int n,ans,x[Maxn],y[Maxn];
int vis[Maxn],cnt;

bool Dfs(int s,int l) {
	bool pd = 0;int sq[4];
	sq[0] = INF;
	sq[2] = INF;
	sq[1] = -INF;
	sq[3] = -INF;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {pd = 1;break;}
	}
	if(s <= 3 && pd == 0) return 1;
	if(s >= 3 && pd == 1) return 0;
	for(int i = 1; i <= n; ++i) {
		if(vis[i])continue;
		sq[0] = min(sq[0] , x[i]);
		sq[1] = max(sq[1] , x[i]);
		sq[2] = min(sq[2] , y[i]);
		sq[3] = max(sq[3] , y[i]);	
	}
	for(int j = 1; j <= n; ++j) {
		if(vis[j])continue;
		if(x[j] >= sq[0] && x[j] <= sq[0] + l && y[j] <= sq[3] && y[j] >= sq[3] - l)vis[j] = 1;	
	}cnt++;
	if(Dfs(s + 1,l)) return 1;
	else {
		for(int j = 1; j <= n; ++j) {
			if(x[j] >= sq[0] && x[j] <= sq[0] + l && y[j] <= sq[3] && y[j] >= sq[3] - l)vis[j] = 0;	
		}cnt--;
	}
	
	for(int j = 1; j <= n; ++j) {
		if(vis[j])continue;
		if(x[j] >= sq[0] && x[j] <= sq[0] + l && y[j] >= sq[2] && y[j] <= sq[2] + l)vis[j] = 1;	
	}
	if(Dfs(s + 1,l)) return 1;
	for(int j = 1; j <= n; ++j) {
		if(x[j] >= sq[0] && x[j] <= sq[0] + l && y[j] >= sq[2] && y[j] <= sq[2] + l)vis[j] = 0;	
	}
	
	for(int j = 1; j <= n; ++j) {
		if(vis[j])continue;
		if(x[j] >= sq[1] - l && x[j] <= sq[1] && y[j] <= sq[3] && y[j] >= sq[3] - l)vis[j] = 1;	
	}
	if(Dfs(s + 1,l)) return 1;
	for(int j = 1; j <= n; ++j) {
		if(x[j] >= sq[1] - l && x[j] <= sq[1] && y[j] <= sq[3] && y[j] >= sq[3] - l)vis[j] = 0;	
	}
	
	for(int j = 1; j <= n; ++j) {
		if(vis[j])continue;
		if(x[j] >= sq[1] - l && x[j] <= sq[1] && y[j] >= sq[2] && y[j] <= sq[2] + l)vis[j] = 1;	
	}
	if(Dfs(s + 1,l)) return 1;
	for(int j = 1; j <= n; ++j) {
		if(x[j] >= sq[1] - l && x[j] <= sq[1] && y[j] >= sq[2] && y[j] <= sq[2] + l)vis[j] = 0;	
	}
	return 0;
}

int main() {
//	freopen("cover.in","r",stdin);
//	freopen("cover.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d",&x[i],&y[i]);
	}
	int l = 1,r = 2100000000,ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		memset(vis,0,sizeof(vis));
		if(Dfs(0,mid))r = mid - 1,ans = mid;
		else l = mid + 1;
	}
	printf("%d\n",ans);
	return 0;
}
