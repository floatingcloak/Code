#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 100000007

using namespace std;

const int Maxn = 510;

int n,m,tot,b[Maxn],cnt[Maxn],dp[Maxn][Maxn];

int main(){
	scanf("%d",&m);int y,temp = 1;
	for(int i = 1;i <= m;i++){
		int x;scanf("%d",&x);
		if(i != 1 && x == y)temp++;
		else if(i != 1){b[++n] = y;cnt[n] = temp;temp = 1;}
		y = x;
	}b[++n] = y;cnt[n] = temp;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)dp[i][j] = INF;
	}
	for(int i = 1;i <= n;i++){
		if(cnt[i] == 1)dp[i][i] = 2;
		else dp[i][i] = 1;
	}
	for(int k = 2;k <= n;k++){
		for(int i = 1;i + k - 1<= n;i++){int j = i + k -1;
			for(int l = i;l < j;l++)dp[i][j] = min(dp[i][j],dp[i][l] + dp[l + 1][j]);
			if(k >= 3 && b[i] == b[j])dp[i][j] = min(dp[i][j],dp[i + 1][j - 1] + (cnt[i] + cnt[j] <= 2));
		}
	}printf("%d\n",dp[1][n]);
	return 0;
}
