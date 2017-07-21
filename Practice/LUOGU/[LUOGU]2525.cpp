#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Maxn = 20;

int n, b[Maxn], a[Maxn], tot, ans[Maxn];
int vis[Maxn];

void Dfs(int x) {
	if(x == n + 1) {
		int pd = 1;
		for(int i = 1; i <= n; ++i) {
			if(b[i] != a[i]) {pd = 0; break;}
		}
		if(pd == 1) {
			for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
			puts("");
			exit(0);
		}
		for(int i = 1; i <= n; ++i) ans[i] = b[i];
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			b[x] = i;
			vis[i] = 1;
			Dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n); int pd = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] != i) pd = 1;
	}
	if(!pd) {
		puts("ERROR");
		return 0;
	}
	Dfs(1);
	while(1);
	return 0;
}