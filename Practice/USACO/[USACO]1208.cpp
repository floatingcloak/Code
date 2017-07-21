#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 5100;

typedef long long ll;

struct node {
	ll w, v;
} a[Maxn];

ll m, n, ans;

bool comp(node a,node b) {return a.v < b.v;}

int main() {
	scanf("%lld%lld", &m, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &a[i].v, &a[i].w);
	}
	sort(a + 1, a + n + 1, comp);
	for(int i = 1; i <= n; ++i) {
		if(!m) break;
		ans += min(m, a[i].w) * a[i].v;
		m -= min(m, a[i].w);
	}
	printf("%lld\n", ans);
	return 0;
}
