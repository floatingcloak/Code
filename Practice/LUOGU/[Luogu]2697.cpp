#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1000001

using namespace std;

int f[INF * 2 + 20];
char s[INF];
int a, ans;

int main() {
	memset(f, -1, sizeof f);
	f[0 + INF] = 0;
	cin >> (s + 1);
	int len = strlen(s + 1);
	for(int i = 1; i <= len; ++i) {
		a += (s[i] == 'G') ? 1 : -1;
		// cout << a << ' ' << f[a + INF] << endl;
		if(f[a + INF] != -1) ans = max(ans, i - f[a + INF]);
		if(f[a + INF] == -1) f[a + INF] = i;
	}
	printf("%d\n", ans);
	// for(;;);
	return 0;
}