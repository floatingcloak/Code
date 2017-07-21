#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101;

int s[4], res, k, ans[Maxn];

void Dfs(int x, int sum) {
	if(x == 4) {
		++ans[sum];
		return;	
	}
	for(int i = 1; i <= s[x]; ++i) {
		Dfs(x + 1, sum + i);
	}
}

int main() {
	scanf("%d%d%d", &s[1], &s[2], &s[3]);
	Dfs(1, 0);
	int lim = s[1] + s[2] + s[3];
	for(int i = 3; i <= lim; ++i) {
		if(ans[i] > res) {
			res = ans[i];
			k = i;	
		}
	}
	printf("%d\n", k);
	return 0;	
}
