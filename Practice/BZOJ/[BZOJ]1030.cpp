#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

#define mod 10007

using namespace std;

const int Maxn = 710000;

queue <int> Q;

int n,m,tot,f[Maxn],dp[50][Maxn],ch[Maxn][28],vis[Maxn];
char s[50];

int Pow(int a,int n){int c = 1;
	while(n){if(n & 1){c = (c * a) % mod;}a = (a * a) % mod;n >>= 1;}
	return c % mod;
}

void Insert() {
	int len = strlen(s), u = 0;
	for(int i = 0; i < len; i++) {
		int v = s[i] - 64;
		if(ch[u][v] == 0) ch[u][v] = ++tot;
		u = ch[u][v];
	}
	vis[u] = 1;
}

void Build(){
	for(int i = 1;i <= 26;i++)if(ch[0][i] > 0)Q.push(ch[0][i]);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		vis[u] |= vis[f[u]];
		for(int i = 1;i <= 26;i++){
			int v = ch[u][i];
			if(v > 0){
				f[v] = ch[f[u]][i];
				Q.push(v);
			}
			else ch[u][i] = ch[f[u]][i];
		}
	}
}

int main(){
	freopen("textgen.in","r",stdin);
	freopen("textgen.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){scanf("%s",s);Insert();}
	Build();dp[0][0] = 1;
	for(int i = 1;i <= m;i++){
		for(int j = 0;j <= tot;j++){
			if(vis[j] == 0 && dp[i - 1][j] > 0){
				for(int k = 1;k <= 26;k++){
					dp[i][ch[j][k]] = (dp[i][ch[j][k]] + dp[i - 1][j]) % mod;
				}
			}
		}
	}
	int Ans1 = 0,Ans2 = Pow(26,m);
	for(int i = 0;i <= tot;i++)if(vis[i] == 0)Ans1 += dp[m][i];
	printf("%d\n",((Ans2 - Ans1) % mod + mod) % mod);
	return 0;
}
