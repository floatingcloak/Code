#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//倒着做lis然后贪心的取答案 
//By sssSSSay 
using namespace std;

const int Maxn = 10100;

int n,x,q,ans,last,a[Maxn],g[Maxn],f[Maxn];

bool comp(int a,int b) {return a > b;}

void Solve(int k) {
	last = 0;
	for(int i = 1; i <= n; ++i) {
		if(f[i] >= k && a[i] > last) {
			printf("%d",a[i]);
			if(k != 1)printf(" ");
			last = a[i];
			--k;
			if(!k)break;
		}
	}
	printf("\n");
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	for(int i = n; i >= 1; --i) {
		int k = lower_bound(g + 1,g + n + 1,a[i],comp) - g;
		f[i] = k;
		ans = max(ans,f[i]);
		g[k] = a[i];
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&x);	
		if(x > ans)printf("Impossible\n");
		else Solve(x);
	}
	return 0;
}
