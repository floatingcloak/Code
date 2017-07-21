
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define eps 1e-8

using namespace std;

const int Maxn = 500010;

struct node {double a,b;int p;}l[Maxn];

double p[Maxn];
int n,top,s[Maxn],Ans[Maxn];

bool comp(node x,node y){
    if(fabs(x.a - y.a) < eps)return x.b < y.b;
    return x.a > y.a;
}

double Solve(int x,int y){return (l[y].b - l[x].b) / (l[x].a - l[y].a);}

int main(){
    // freopen("bzoj_1007.in","r",stdin);
    // freopen("bzoj_1007.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%lf%lf",&l[i].a,&l[i].b);l[i].p = i;}
    sort(l + 1,l + n + 1,comp);
    for(int i=1;i<=n;i++){
        while(top){
            if(fabs(l[s[top]].a - l[i].a) < eps)top--;
            else if(top > 1 && Solve(i,s[top]) >= Solve(s[top],s[top - 1]))top--;
            else break;
        }s[++top] = i;
    }
    for(int i=1;i<=top;i++)Ans[l[s[i]].p] = 1;
    for(int i=1;i<=n;i++)if(Ans[i])printf("%d ",i);
    // while(1);
    return 0;
}
