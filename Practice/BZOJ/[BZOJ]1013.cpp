#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 11;

int n;
double a[Maxn][Maxn],d[Maxn][Maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n;j++)scanf("%lf",&a[i][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j] = 2 * (a[i+1][j] - a[i][j]);
            d[i][n+1] += (a[i+1][j] * a[i+1][j] - a[i][j] * a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            if(i != j){
                double x = d[j][i] / d[i][i];
                for(int k=1;k<=n+1;k++)d[j][k] -= x * d[i][k];
            }
         }
    }
    for(int i=1;i< n;i++)printf("%.3lf ",d[i][n + 1] / d[i][i]);
    printf("%.3lf",d[n][n+1] / d[n][n]);//坑点,一定要单独输出
    // while(1);
    return 0;
}
