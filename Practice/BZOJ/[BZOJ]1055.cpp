#include <cstdio>
#include <cstring>
#include <iostream>
//一个我写过的（？）dp，记忆化搜索，考虑两个合成一个，搜索是否能合成WING
//By sssSSSay 
using namespace std;

const int Maxn = 2100;

char ch[5] = {' ','W','I','N','G'},a[5][18][2],str[Maxn];
int hash[5];
int dp[Maxn][Maxn][5];
int cnt[5];

bool Dfs(int l,int r,int k) {
	if(l == r) return str[l] == ch[k];
	int &res = dp[l][r][k];
	if(res != -1)return res;
	for(int i = 1; i <= cnt[k]; ++i) {
		for(int j = l; j < r; ++j) {
				if(Dfs(l,j,hash[a[k][i][0]]) && Dfs(j + 1,r,hash[a[k][i][1]])) return res = 1;
		}
	}
	return res = 0;
}

int main() {
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	
	memset(dp,-1,sizeof(dp));
	hash['W'] = 1;hash['I'] = 2;hash['N'] = 3;hash['G'] = 4;
	
	for(int i = 1; i <= 4; ++i) scanf("%d",&cnt[i]);
	for(int i = 1; i <= 4; ++i) {
		for(int j = 1; j <= cnt[i]; ++j) scanf("%s",a[i][j]);
	}
	scanf("%s",(str + 1));
	int l = 1,r = strlen(str + 1),judge = 0;
	for(int i = 1;i <= 4; ++i) {
		if(Dfs(l,r,i)) {
			printf("%c",ch[i]);
			judge = 1;
		}
	}
	if(!judge) printf("The name is wrong!\n");
	return 0;
}
