#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int Maxn = 100010;

int n;
double A,Sum[Maxn],c[Maxn],m[Maxn];

int main(){
    // freopen("bzoj_1011_planet.in","r",stdin);
    // freopen("bzoj_1011_planet.out","w",stdout);
    scanf("%d%lf",&n,&A);
    for(int i=1;i<=n;i++){
        scanf("%lf",&m[i]);
        Sum[i] = Sum[i-1] + m[i];
    }int Up = min(5000,n);
    for(int i=1;i<=Up;i++){
        int k = floor(A * (double)i);
        for(int j=1;j<=k;j++)c[i] += m[j] / (double)(i - j);
        c[i] *= m[i];
    }
    for(int i=Up+1;i<=n;i++){
        int k = floor(A * (double)i);
        c[i] = m[i] * Sum[k] / ((double)i - ((double)k / 2.0));
    }
    for(int i=1;i<=n;i++)printf("%.6lf\n",c[i]);
    // while(1);
    return 0;
}
