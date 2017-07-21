#include <cstdio>
#include <cstring>
#include <iostream>
//ÍÆÊ½×Ó
//By sssSSSay 
using namespace std;

const int Maxn = 1010;

int n, a[Maxn][Maxn], sumr[Maxn], sumc[Maxn], ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1, x; j <= n; ++j) {
			char ch; cin >> ch; x = ch - '0';
			a[i][j] = x;
			sumr[i] ^= x;
			sumc[j] ^= x;
		}
	}	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) ans += sumr[i] ^ sumc[j] ^ a[i][j];
	}
	printf("%d\n", min(ans, n * n - ans));
	return 0;
}
