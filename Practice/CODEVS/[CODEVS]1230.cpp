#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101000;

map <int, int> hs;

int n, m, a[Maxn];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);	
		hs[a[i]] = 1;
	}
	while(m--) {
		int x; scanf("%d", &x);
		if(hs[x]) printf("YES\n");
		else printf("NO\n");	
	}
	return 0;
}
