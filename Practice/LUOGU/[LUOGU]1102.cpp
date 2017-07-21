#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 10000000000007LL

typedef long long LL;

using namespace std;

const int Maxn = 200010;

int n,cnt[Maxn];
LL C,a[Maxn],Ans,c[Maxn],b[Maxn],tot;

bool comp(LL a,LL b){return a < b;}

int main(){// a - c = b
    scanf("%d%lld",&n,&C);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1,comp);
    for(int i=1;i<=n;i++){
        if(a[i] != a[i-1]) b[i] = ++tot;
        else b[i] = tot;
        c[tot] = a[i];
        cnt[tot]++;
    }
    // for(int i=1;i<=n;i++)printf("%d ",b[i]);
    // printf("\n");
    for(int i=n;i>=1;i--){
        LL m = c[b[i]] - C;
        int l = 1,r = i - 1;
        LL res = INF;
        while(l <= r){
            int mid = (l + r) / 2;
            if(c[b[mid]] <= m)res = b[mid],l = mid + 1;
            else r = mid - 1;
        }
        // printf("%lld\n",res);
        if(res != INF && c[res] == m)Ans += cnt[res];
    }
    printf("%d\n",Ans);
    // while(1);
    return 0;
}