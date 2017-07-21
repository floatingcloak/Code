#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

int a[Maxn], b[Maxn], c[Maxn], n, m, tot;
char str[Maxn];

void Reserve() {
	for(int i = 1; i <= tot; ++i) b[tot - i + 1] = a[i];
}

void Judge(int s) {
	for(int i = 1; i <= tot / 2; ++i) if(a[i] != a[tot - i + 1]) return;
	printf("STEP=%d\n", s);
	exit(0);
}

void Add() {
	memset(c, 0, sizeof(c)); int len = tot;
	for(int i = 1; i <= tot; ++i) {
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / n;
		c[i] %= n;
	}
	if(c[tot + 1] != 0) ++tot;
	memcpy(a, c, sizeof(c));
}

int main() {
	scanf("%d", &n); scanf("%s", (str + 1));
	tot = strlen(str + 1);
	for(int i = 1; i <= tot; ++i) {
		if(str[i] > '9') {
			a[i] = str[i] - 55;
		}
		else a[i] = str[i] - '0';
//		cout << a[i];
	}
	Reserve();
	for(int s = 0; s <= 30; ++s) {
		Judge(s);
		Add(); Reserve();
	}
	printf("Impossible!\n");
	return 0;
}
