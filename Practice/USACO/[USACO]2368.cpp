#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, base = 8;

int main() {
	scanf("%d", &n);
	if(n <= 8) puts("0");
	else {
		if(n == 9) puts("8");
		else if(n == 10) puts("72");
		else {
			putchar('7'); putchar('2');
			for(int i = 1; i <= n - 10; ++i) putchar('0');
			puts("");
		}
	}
	return 0;
}
