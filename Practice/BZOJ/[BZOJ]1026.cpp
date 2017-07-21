#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 13;

int A,B,a[Maxn],f[Maxn][10][2][2];

int Abs(int w){return w >= 0 ? w : -w;}

int Solve(int XD){int m = 0;
	while(XD){
		a[m++] = XD % 10;
		XD /= 10;
	}
	reverse(a, a + m);//123 = 1 2 3
	memset(f,0,sizeof(f));
	f[0][0][1][1] = 1; // 目前已经填完了i位 其最后一位是j 前面是否贴上界k 前面是否全空l 
	for(int i = 0; i < m; i++){ // 填数 
		for(int j = 0; j <= 9; j++){ // 枚举上一位 
			for(int k = 0; k <= 1; k++){ // 前面是否贴上界
				for(int l = 0; l <= 1; l++){ // 前面是否全空 
					int lim = k ? a[i] : 9; // 枚举的上界 
					if(l == 1){ // 全空直接填 
						for(int d = 0; d <= lim; d++)f[i + 1][d][k && d == lim][l && d == 0] += f[i][j][k][l];
					}
					else { // 不是全空的话需要判断一下 
						for(int d = 0; d <= lim; d++)if(Abs(d - j) >= 2)f[i + 1][d][k && d == lim][0] += f[i][j][k][l];
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 1; j++){
			for(int k = 0; k <= 1; k++)ans += f[m][i][j][k]; // 把填了m个数的所有方案相加	
		}
	}return ans;
}

int main(){
	scanf("%d%d",&A,&B);
	printf("%d\n",Solve(B) - Solve(A - 1));
	return 0;
}
