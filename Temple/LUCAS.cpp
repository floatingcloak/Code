#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int Maxn = 100010;

LL m,n,p,Fac[Maxn],T;

LL Pow(LL a,LL n){LL c = 1;
    while(n > 0){if(n & 1)c = (c * a) % p;a = (a * a) % p;n = n / 2;}
	return c % p;
}

LL Lucas(LL n,LL m,LL p){
    LL Res = 1;
    while(n && m){
        LL A = n % p,B = m % p;
        if(A < B)return 0;
        Res = (Res * Fac[A] * Pow(Fac[B] * Fac[A - B] % p,p - 2)) % p;
        n /= p;m /= p;
    }return Res;
}

int main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&p);Fac[0] = 1;
        for(LL i=1;i<=p;i++)Fac[i] = (Fac[i-1] * i) % p;
        printf("%lld\n",Lucas(n+m,m,p) % p);
    }
    // while(1);
    return 0;
}
