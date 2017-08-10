#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 101010;

struct node {
	int v, t;
} a[Maxn];

int n, sum;

bool comp(node a, node b) {return a.v > b.v;}

int main() {
	scanf("%d", &sum);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i].t);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i].v), sum -= a[i].v;
	sort(a + 1, a + n + 1, comp);
	int now = 0;
	for(int i = 1; i <= n; ++i) {
		if(now + 1 <= a[i].t) {
			sum += a[i].v;
			++now;
		}
	}
	printf("%d\n", sum);
	for(;;);
	return 0;
}