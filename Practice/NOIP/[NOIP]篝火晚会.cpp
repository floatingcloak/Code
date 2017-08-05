#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101010;

int n, x[Maxn], y[Maxn], b[Maxn], c[Maxn];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	int now = 1;
	for(int s = 1; s <= n; now = y[now], ++s) b[s] = now;
	for(int i = 1; i <= n; ++i) cout << b[i] << ' ';
	cout << endl;
	if((y[b[n]] != b[1]) || (x[b[1]] != b[n])) {
		puts("-1");
		for(;;);
		return 0;
	}
	// for(int i = 1; i <= n; ++i) c[i] = b[n - i + 1];
	for(int i = 1; i <= n; ++i) {
		cin >> str;
	}
	cout << str + 1 << endl;
	
	return 0;
}
/*
5
1 2
3 4
1 6
*/