#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 110;

int n, a[Maxn];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		int ans = 0;
		for(int j = 1; j < i; ++j) if(a[j] < a[i]) ++ans;
		printf("%d ", ans);
	}
	return 0;
}
