#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 35;

char s[Maxn][10];
int n,p[10][Maxn];
long long f[10][Maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= 6;i++)scanf("%s",(s[i] + 1));
	for(int i = 1;i <= 3;i++)f[i][1] = 1LL;
	for(int i = 6;i >= 1;i--)p[s[i][1] - 'A' + 1][1] = s[i][2] - 'A' + 1;
	for(int i = 2;i <= n;i++){
		for(int a = 1;a <= 3;a++){
			int b = p[a][i - 1],c = 6 - b - a;
			if(p[b][i - 1] == c){
				f[a][i] = f[a][i - 1] + 1 + f[b][i - 1];
				p[a][i] = c;
			}
			if(p[b][i - 1] == a){
				f[a][i] = f[a][i - 1] + 1 + f[b][i - 1] + 1 + f[a][i - 1];
				p[a][i] = b;
			}
		}
	}printf("%lld\n",f[1][n]);
	return 0;
}
