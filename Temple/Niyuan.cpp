#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1000000007
#define LL unsigned long long

using namespace std;

LL ans,SUM;
LL n,m;

LL f_pow(LL a,LL n)
{
	LL sum = 1;
	
	while(n > 0){
		if(n % 2 == 1)sum = (a * sum) % INF;
		a = (a * a) % INF;
		n /= 2;
	}
	
	return sum % INF;
}

LL work(LL x){return x == 1 ? 1 : (INF - INF/x) * work(INF % x) % INF;}//INF为质数 

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	
//	printf("%lld\n",f_pow(2,10));
	
	for(int i=1;i<=n;i++){
		if(i == 1){
			ans += m;
			continue;
		}
		
		SUM = ((f_pow(i,m) - 1) * i ) % INF;
//		求(i - 1)逆元 求 （SUM * 逆元）% INF 
		LL p = work(i-1) % INF; 
		
		SUM = (SUM * p) % INF;
		ans = (ans + SUM) % INF;
	}
	
	printf("%lld",ans % INF);
	
	return 0;
}
