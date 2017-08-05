#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	string s;
	int d;
} a[110];

int n;

bool comp(node a, node b) {return a.d < b.d;}

int main() {
	// freopen("nba.in", "r", stdin);
	// freopen("nba.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) cin >> a[i].s >> a[i].d;
	sort(a + 1, a + n + 1, comp);
	for(int i = 1; i <= n; ++i) cout << a[i].d << ' ' << a[i].s << endl;
	for(;;);
	return 0;
}