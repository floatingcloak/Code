
#include <cstdio>
#include <cstring>
#include <iostream>

#define p 100003LL

typedef long long LL;

using namespace std;

LL m,n;

LL Pow(LL a,LL n){
    LL c = 1;
    while(n){
        if(n & 1)c = (c * a) % p;
        a = (a * a) % p;
        n = n / 2;
    }return c % p;
}

int main(){
    scanf("%lld%lld",&m,&n);
    // printf("%d\n",Pow(m,n));
    LL Temp = Pow(m,n) - (Pow(m - 1,n - 1) * m),j = 1;
    // printf("%lld\n",Temp);
    while(Temp < 0)Temp += Pow(2,j++) * p;
    printf("%lld\n",Temp % p);
    return 0;
}
