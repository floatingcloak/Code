#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
//数据很小可以记忆化搜索，注意一些小细节要手推
//By sssSSSay 
#define INF 1e9

using namespace std;

const int Maxn = 15;

int n,r,c,a[Maxn][Maxn],sum[Maxn][Maxn];
double ave,ans = INF,dp[Maxn][Maxn][Maxn][Maxn][Maxn];

int Cal(int x1,int y1,int x2,int y2) {
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

double Dfs(int x,int x1,int y1,int x2,int y2) {
	double &res = dp[x][x1][y1][x2][y2];
	if(res != -1)return res;
	if(x == 0) {
		res = Cal(x1,y1,x2,y2);
		res = (res - ave) * (res - ave);
		return res;
	}
	res = 1e9;
	for(int i = x1; i < x2; ++i) {
		for(int j = 0; j < x; ++j) {
			res = min(res,Dfs(j,x1,y1,i,y2) + Dfs(x - j - 1,i + 1,y1,x2,y2));
		}
	}
	for(int i = y1; i < y2; ++i) {
		for(int j = 0; j < x; ++j) {
			res = min(res,Dfs(j,x1,y1,x2,i) + Dfs(x - j - 1,x1,i + 1,x2,y2));
		}
	}
	return res;
}

int main() {
	scanf("%d%d%d",&r,&c,&n);
	for(int i = 0; i <= 13; ++i) {
		for(int j = 0; j <= 13; ++j) {
			for(int k = 0; k <= 13; ++k) {
				for(int l = 0; l <= 13; ++l) {
					for(int o = 0; o <= 13; ++o)dp[i][j][k][l][o] = -1;
				}
			}
		}
	}
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			scanf("%d",&a[i][j]);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];	
		}
	}
	ave = (double)sum[r][c] / (double)n;
	Dfs(n - 1,1,1,r,c);
	printf("%.2lf\n",sqrt(dp[n - 1][1][1][r][c] / n));
	return 0;
}
