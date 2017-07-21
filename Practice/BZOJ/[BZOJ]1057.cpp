#include <cstdio>
#include <cstring>
#include <iostream>
//悬线法。。统计上面左边右边的最大值直接出答案
//By sssSSSay 
using namespace std;

const int Maxn = 2100;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,m,a[Maxn][Maxn],r[Maxn][Maxn],l[Maxn][Maxn],h[Maxn][Maxn],ans1,ans2;

int main() {
	n = read();m = read();
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			a[i][j] = read();
			if(i == 1)h[i][j] = 1;
			else if(a[i][j] == a[i - 1][j])h[i][j] = 1;
			else h[i][j] = h[i - 1][j] + 1;
		}
	}
//	for(int i = 1; i <= n; ++i) {
//		for(int j = 1; j <= m; ++j)printf("%d ",h[i][j]);
//		printf("\n");	
//	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			l[i][j] = j;
			while(l[i][j] > 1 && h[i][l[i][j] - 1] >= h[i][j] && a[i][l[i][j] - 1] != a[i][l[i][j]]) {
				l[i][j] = l[i][l[i][j] - 1];	
			}
		}
		for(int j = m; j >= 1; --j) {
			r[i][j] = j;
			while(r[i][j] < m && h[i][r[i][j] + 1] >= h[i][j] && a[i][r[i][j]] != a[i][r[i][j] + 1]) {
				r[i][j] = r[i][r[i][j] + 1];
			}
		}
		for(int j = 1; j <= m; ++j) {
			int t = r[i][j] - l[i][j] + 1;
//			cout<<t<<endl;
			ans1 = max(ans1,h[i][j] * t);
			t = min(h[i][j],t);
			ans2 = max(ans2,t * t);	
		}
	}
	printf("%d\n%d\n",ans2,ans1);
}
