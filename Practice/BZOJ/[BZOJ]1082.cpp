#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1010;

int n,m,mid,Sum,Rest,a[Maxn],b[Maxn],Pre[Maxn],t[Maxn];

int Dfs(int k,int x){
    if(k == 0)return 1;
    if(Pre[mid] + Rest > Sum)return 0;
    for(int i=x;i<=m;i++){
        if(t[i] >= b[k]){
                t[i] -= b[k];
                if(t[i] < b[1])Rest += t[i];
                if(b[k] == b[k-1]){if(Dfs(k-1,i))return 1;}
                else if(Dfs(k-1,1))return 1;
                if(t[i] < b[1])Rest -= t[i];
                t[i] += b[k];
        }
    }return 0;
}

int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;i++){scanf("%d",&a[i]);Sum += a[i];}
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    sort(a+1,a+m+1);sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)Pre[i] = Pre[i-1] + b[i];
    while(Pre[n] > Sum)n--; int l = 0,r = n;
    while(l <= r){
        mid = (l + r) / 2;memcpy(t,a,sizeof(a));Rest = 0;
        if(Dfs(mid,1))l = mid + 1;
        else r = mid - 1;
    }printf("%d\n",r);
    // while(1);
    return 0;
}
<div class="meta"><span>February 14, 2017</span></div>























