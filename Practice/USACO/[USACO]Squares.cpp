#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 123;

int b, a[Maxn], c[Maxn];
char ch[Maxn] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};

int main() {
	scanf("%d", &b);
	for(int i = 1; i <= 300; ++i) {
		int x = i * i, y = i;
		int tot = 0, cnt = 0;
		while(x) {
			a[++tot] = x % b;
			x /= b;
		}
		while(y) {
			c[++cnt] = y % b;
			y /= b;
		}
		int pd = 0;
		for(int j = 1; j <= (tot >> 1); ++j) {
			if(a[j] != a[tot - j + 1]) {
				pd = 1; break;
			}
		}
		if(pd == 0) {
			for(int j = cnt; j >= 1; --j) printf("%c", ch[c[j]]);
			putchar(' ');
			for(int j = tot; j >= 1; --j) printf("%c", ch[a[j]]);
			puts("");
		}
	}
	return 0;
}
