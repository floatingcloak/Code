#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int Maxn = 1000001;

int n,a[Maxn],c[Maxn];
LL sum,ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int x = sum / n;
    for(int i=1;i<=n;i++)c[i] = c[i-1] + a[i] - x;
    sort(c + 1,c + n + 1);
    int y = c[(n >> 1) + 1];
    for(int i=1;i<=n;i++){
        if(y > c[i])ans += y - c[i];
        else ans += c[i] - y;
    }
    printf("%lld\n",ans);
    // while(1);
    return 0;
}