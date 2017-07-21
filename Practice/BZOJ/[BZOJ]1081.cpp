#include <cstdio>
#include <cstring>
#include <iostream>
//不太会的找规律
//By sssSSSay 
using namespace std;

const int Maxn = 67000;

int a[Maxn], n, b;

void Dfs(int x, int w) {
	if(x == n + 1) {
		for(int i = n; i >= 1; --i) {
			if(a[i] <= 9) printf("%d", a[i]);
			else printf("%c", (a[i] - 10 + 'A'));
		}
		printf("\n");
		return;
	}
	if(!w) {
		for(int i = 0; i < b; ++i) {
			a[x] = i;
			if(i % 2 == 0) Dfs(x + 1, 0);
			else Dfs(x + 1, 1);
		}
	}
	else {
		for(int i = b - 1; i >= 0; --i) {
			a[x] = i;
			if(i % 2 == 0) Dfs(x + 1, 1);
			else Dfs(x + 1, 0);
		}
	}
}

int main() {
	scanf("%d%d", &n, &b);
	Dfs(1, 0);
	return 0;
}
