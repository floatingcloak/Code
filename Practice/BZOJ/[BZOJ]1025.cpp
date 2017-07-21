#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int Maxn = 1010;

ll dp[Maxn][Maxn];
int Judge[Maxn],prime[Maxn],n,tot;

ll Dfs(int x,int w){
	if(dp[x][w] > 0)return dp[x][w];
	if(w <= 0)return 1ll;
	dp[x][w] = Dfs(x,w - 1);
	for(int i = prime[w];i <= x;i *= prime[w]){
		dp[x][w] += Dfs(x - i,w - 1);
	}return dp[x][w];
}

int main(){
	scanf("%d",&n);Judge[1] = 1;
	for(int i = 2;i <= n;i++){
		if(!Judge[i])for(int j = 2;i * j <= n;j++)Judge[i * j] = 1;
	}for(int i = 1;i <= n;i++)if(!Judge[i])prime[++tot] = i;
	printf("%lld\n",Dfs(n,tot));
	return 0;
}
