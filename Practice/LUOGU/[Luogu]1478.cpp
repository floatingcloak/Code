#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 101010;

int n, s, x, y, z, ans[Maxn], tot, c[Maxn], res;

int main() {
	scanf("%d%d", &n, &s);
	scanf("%d%d", &x, &y); z = x + y;
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &x, &c[i]);
		if(x <= z) ans[++tot] = c[i];
	} 
	sort(ans + 1, ans + 1 +tot);
	for(int i = 1; i <= tot; ++i) {
		if(s - ans[i] >= 0) {
			++res;
			s -= ans[i];
		}
	}
	printf("%d\n", res);
	// for(;;);
	return 0;
}