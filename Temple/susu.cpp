#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int Maxn = 1010;

int n,m,c;
ll map[Maxn][Maxn],sum[Maxn][Maxn];
ll aa[Maxn];

bool comp(ll a,ll b) {return a < b;}

ll Sum(int x1,int y1,int x2,int y2) {
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int main() {
	freopen("susu.in","r",stdin);
	freopen("susu.out","w",stdout);
	scanf("%d%d%d", &n, &m, &c);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%lld",&map[i][j]);	
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + map[i][j] - sum[i - 1][j - 1];
		}
	}
	for(int i = 1; i <= c; ++i) {
		int x1, y1, x2, y2;
		ll h;
		scanf("%d%d%d%d%lld", &x1, &y1, &x2, &y2, &h);
		ll cnt = Sum(x1,y1,x2,y2);
		if(cnt < h) {
			printf("Poor QLW\n");	
		}
		else {
			int cc = 0;
			for(int j = x1; j <= x2; ++j) {
				for(int l = y1; l <= y2; ++l) aa[++cc] = map[j][l];
			}
			sort(aa + 1, aa + cc + 1);
			ll temp = 0;
			int ans = 0;
			for(int j = cc; j >= 1; --j) {
				temp += aa[j];
				if(temp >= h) {
					ans = cc - j + 1;
					break;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
