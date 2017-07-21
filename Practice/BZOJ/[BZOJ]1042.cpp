#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101000;

typedef long long ll;

ll f[Maxn],res,ans;
int n,c[6],d[6],T;

void Dfs(int x,ll sum,int k) {
	if(sum < 0)return;
	if(x == 5) {
		if(k & 1) ans -= f[sum];
		else ans += f[sum];
		return;
	}
	Dfs(x + 1,sum - (d[x] + 1) * c[x],k + 1);
	Dfs(x + 1,sum,k);
}

int main() {
	scanf("%d%d%d%d%d",&c[1],&c[2],&c[3],&c[4],&T);
	f[0] = 1;
	for(int i = 1; i <= 4; i++) {
		for(int j = c[i]; j <= 100000; j++) {
			f[j] += f[j - c[i]];
		}
	}
	while(T--) {
		scanf("%d%d%d%d%lld",&d[1],&d[2],&d[3],&d[4],&res);
		ans = 0;
		Dfs(1,res,0);
		printf("%lld\n",ans);
	}
	return 0;
}
