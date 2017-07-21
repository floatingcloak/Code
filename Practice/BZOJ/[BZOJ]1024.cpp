#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int n,x,y;

double Dfs(int n,double x,double y){
    double re = 1e6;
    if(n == 1)return exp(fabs(log(x/y)));
    for(int i=1;i<<1<=n;i++)re = min(re,max(Dfs(i,x/n*i,y),Dfs(n-i,x-x/n*i,y)));
    for(int i=1;i<<1<=n;i++)re = min(re,max(Dfs(i,x,y/n*i),Dfs(n-i,x,y-y/n*i)));
    return re;
}

int main(){
    scanf("%d%d%d",&x,&y,&n);
    printf("%.6lf\n",Dfs(n,x,y));return 0;
}
