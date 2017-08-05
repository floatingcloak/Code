#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

char b[21] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
int n, k, ans[Maxn];

int main() {
	int  t = 0;
	scanf("%d%d", &n, &k); int c = n;
	while(n) {
		ans[++t] = n % k;
		if(ans[t] < 0) {
			ans[t] -= k;
			n += k;
		}
		n /= k;
	}
	cout << c << "=";
	for(int i = t; i >= 1; --i) printf("%c", b[ans[i]]);
	printf("(base%d)\n", k);
	// for(;;);
	return 0;
}