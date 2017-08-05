#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

int n;
char b[Maxn];

void Dfs(int x, int sum, int res, int p) {
	if(x == n) {
		if(b[n - 1] == ' ') res += sum;
		if(b[n - 1] == '+') res += n;
		if(b[n - 1] == '-') res -= n;
		if(res == 0) {
			for(int i = 1; i < n; ++i) printf("%d%c", i, b[i]);
			printf("%d\n", n);
		}
		return;
	}
	// cout << res << endl;
	b[x] = ' ';
	Dfs(x + 1, sum * 10 + p * (x + 1), res, p);
	b[x] = '+';
	Dfs(x + 1, x + 1, res + sum, 1);
	b[x] = '-';
	Dfs(x + 1, -(x + 1), res + sum, -1);
}

int main() {
	scanf("%d", &n);
	Dfs(1, 1, 0, 1);
	// for(;;);
	return 0;
}