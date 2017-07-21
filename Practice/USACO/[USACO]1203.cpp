#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 510;

int n, res, vis[Maxn];
char s[Maxn];

int main() {
	scanf("%d", &n); int tot = 1;
	scanf("%s", (s + 1));
	for(int i = 1; i <= n; ++i) {
		int ans = 0; ++tot;
		int l = i, r = i + 1; if(r == n + 1) r = 1;
		char lc = s[l], rc = s[r];
		if(lc == 'w') lc = s[(l == 1) ? n : (l - 1)];
		if(rc == 'w') rc = s[(r == n) ? 1 : (r + 1)];
		while(vis[l] != tot && (s[l] == lc || s[l] == 'w')) {
			vis[l] = tot; ++ans; --l; if(l == 0) l = n;
		}
		while(vis[r] != tot && (s[r] == rc || s[r] == 'w')) {
			vis[r] = tot; ++ans; ++r; if(r == n + 1) r = 1;
		}
		res = max(res, ans);
	}
	printf("%d\n", res);
	return 0;
}
