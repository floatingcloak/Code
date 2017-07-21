#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 33686018

using namespace std;

const int Maxn = 1010;

int val[7] = {0,100,50,20,10,5,1},cnt[Maxn][Maxn],d[Maxn],e[Maxn],sum,a,b,c,dp[3][Maxn][Maxn];

int main(){
	scanf("%d%d%d",&a,&b,&c);
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <= 6;j++){
			scanf("%d",&cnt[i][j]);
			sum += cnt[i][j] * val[j];//统计总钱数 
			d[i] += cnt[i][j] * val[j];//统计第i个人的初始总钱数 
			e[j] += cnt[i][j];//统计第j种钱币的总钱数 
		}
	}
	int Ta = d[1] - a + c,Tb = d[2] - b + a;
	if(Ta < 0 || Tb < 0 || sum - Ta - Tb < 0){printf("impossible\n");return 0;}
	memset(dp[0],2,sizeof(dp[0]));int pre = 0,now = 0;dp[0][d[1]][d[2]] = 0;
	for(int i = 1;i <= 6;i++){
		pre = now;now ^= 1;memset(dp[now],2,sizeof(dp[now]));
		for(int j = 0;j <= sum;j++){
			for(int k = 0;j + k <= sum;k++){
				if(dp[pre][j][k] == INF)continue;
				dp[now][j][k] = min(dp[now][j][k],dp[pre][j][k]);//相当于初值 
				for(int l = 0;l <= e[i];l++){
					for(int o = 0;o + l <= e[i];o++){
						int DeltaA = l - cnt[1][i],DeltaB = o - cnt[2][i];
						int TCost1 = j + DeltaA * val[i],TCost2 = k + DeltaB * val[i];
						if(TCost1 < 0 || TCost2 < 0 || sum - TCost1 - TCost2 < 0)continue;
						dp[now][TCost1][TCost2] = min(dp[now][TCost1][TCost2],dp[pre][j][k] + (abs(DeltaA) + abs(DeltaB) + abs(DeltaA + DeltaB)) / 2);
						
					}
				}
				
			}
		}
	}
	if(dp[now][Ta][Tb] == INF){printf("impossible\n");return 0;}
	else printf("%d\n",dp[now][Ta][Tb]);
	return 0;
}
