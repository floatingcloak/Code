#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 2000000001

using namespace std;

const int Maxn = 1000010;

int n, m, a[Maxn], ans = INF, vis[2500], ans1, ans2;

int main() {
	scanf("%d%d", &n, &m); int tot = 0;
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int l = 1, r = 0;
	while(l <= n && r <= n) {
		if(tot < m) {
			if(r == n) break;
			int v = a[++r];
			if(vis[v] == 0) ++tot;
			++vis[v];
		}
		else if(tot == m) {
			if((r - l + 1) < ans) {
				ans1 = l, ans2 = r;
				ans = r - l + 1;	
			}
			int v = a[l++];
			if(vis[v] == 1) --tot;
			--vis[v];
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
