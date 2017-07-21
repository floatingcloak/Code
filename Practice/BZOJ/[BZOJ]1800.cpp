#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 31;

bool b[Maxn*Maxn];
int n,Ans,a[Maxn],sum[Maxn];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
        b[sum[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int r = sum[j] - sum[i];
            int c = (sum[n] - 2 * r) / 2;
            if(sum[j] + c + r <= sum[n] && b[sum[j] + c + r] && b[sum[j] + c])Ans++;
        }
    }
    printf("%d\n",Ans);
    // while(1);
    return 0;
}