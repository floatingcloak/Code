#include <cstdio>
#include <cstring>
#include <iostream>
//约数个数定理：约数的个数为所有质因子指数 + 1的乘积
//然后爆搜。。
//By sssSSSay 
using namespace std;

typedef long long ll;

int n,tot;
ll ans;
ll p[14] = {0,2,3,5,7,11,13,17,19,23,29,31,37};

void Dfs(int s,ll now,int sum,int cur) {
	if(s == 12) {
		if(now > ans && sum > tot) {
			ans = now;
			tot = sum;	
		}
		if(now <= ans && sum >= tot) {
			ans = now;
			tot = sum;	
		}
		return;
	}
	ll temp = 1;
	for(int i = 0; i <= cur; ++i) {
		Dfs(s + 1,now * temp,sum * (i + 1),i);
		temp *= p[s];
		if(now * temp > n)return;
	}
}

int main() {
	scanf("%d",&n);
	Dfs(1,1,1,30);
	printf("%lld\n",ans);
	return 0;
}
