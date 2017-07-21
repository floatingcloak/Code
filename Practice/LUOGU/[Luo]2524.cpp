#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 11;

int n, a[Maxn], b[Maxn], sum;
bool vis[Maxn];

void Dfs(int x) {
	if(x == n + 1) {
		sum++;
		int pd = 0;
		for(int i = 1; i <= n; ++i) {
			if(a[i] != b[i]) {pd = 1; break;}
		}
		if(pd == 0) {
			printf("%d\n", sum);
			exit(0);
		}
		return;
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			b[x] = i;
			vis[i] = 1;
			Dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		char ch; cin >> ch;
		a[i] = ch - '0';
	}
	Dfs(1);
	return 0;
}
