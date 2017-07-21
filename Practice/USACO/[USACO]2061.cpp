#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10100;

struct node {
	int l, r, c;	
} a[Maxn];

int n;

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1, x, y, z; i <= n; ++i) {
		scanf("%d%d%d", &x, &y, &z);	
		a[i].l = x; a[i].r = y; a[i].c = z;
	}
	
	return 0;
}
