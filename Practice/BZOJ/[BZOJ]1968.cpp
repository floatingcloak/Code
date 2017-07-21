#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
long long ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)ans += (long long)(n / i);
    printf("%lld\n",ans);
    // while(1);
    return 0;
}