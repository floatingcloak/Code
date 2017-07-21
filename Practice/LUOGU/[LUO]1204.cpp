#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1000001;

int n, a[Maxn], b[Maxn], ans1, ans2, temp, sum1, sum2;

int main() {
	int minx = 1000001, maxx = 0;
	scanf("%d", &n);
	for(int i = 1, x, y; i <= n; ++i) {
		scanf("%d%d", &x, &y);
		minx = min(minx, x);
		maxx = max(maxx, y);
		a[x]++; b[y]++;
	}
	temp = 0;
	for(int i = minx; i <= maxx; ++i) {
		temp += a[i] - b[i];
		ans1 = max(ans1, sum1);
		ans2 = max(ans2, sum2);
		if(temp == 0) {
			sum1++; sum2 = 0;
		}
		else {
			sum2++; sum1 = 0;
		}
	}
	cout << ans2 << ' ' << ans1 << endl;
	return 0;
}
