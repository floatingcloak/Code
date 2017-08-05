#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, k, ans;

int main() {
	scanf("%d%d", &n, &k);
	int now = n, w = 0;
	while(now) {
		// cout << now << endl;
		ans += now;
		now += w;
		w = now % k;
		now /= k;
	}
	printf("%d\n", ans);
	// for(;;);
	return 0;
}