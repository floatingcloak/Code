#include <cstdio>
#include <cstring>
#include <iostream>

#define mod 10007

using namespace std;

const int Maxn = 60100;

int n,m,a[Maxn],sum[Maxn],dp[Maxn][2];

bool Check(int k) {
	int now = 0,cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(now + a[i] > k) {
			now = a[i];
			cnt++;
			if(cnt > m || a[i] > k)return 0;
		}
		else now += a[i];
	}
	return 1;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 0,r = sum[n],ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(Check(mid))r = mid - 1,ans = mid;
		else l = mid + 1;	
	}
	int now = 0,res = 0;
	for(int i = 0; i <= m; ++i) {
		int temp = 0,pre = 0;
		for(int j = 1; j <= n; ++j) {
			if(i == 0 && sum[j] <= ans) dp[j][now] = 1;
			else {
				while(pre < j && sum[j] - sum[pre] > ans) {
					(temp -= dp[pre][now ^ 1]) %= mod;
					(temp += mod) %= mod;
					pre++;
				}
				(dp[j][now] = temp) %= mod;
			}
			(temp += dp[j][now ^ 1]) %= mod;
		}
		(res += dp[n][now]) %= mod;
		now ^= 1;
	}
	printf("%d %d\n",ans,res);
	return 0;
}
