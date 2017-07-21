#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define p 31011

using namespace std;

const int Maxn = 10001;

struct node {int u,v,c;}e[Maxn];
struct noda {int l,r,v;}g[Maxn];

int n,m,fa[Maxn],cnt,tot,Ans = 1,Sum;

bool comp(node a,node b){return a.c < b.c;}

int find(int x){
    return fa[x] == x ? x : find(fa[x]) ;
}

void Dfs(int w,int Now,int k){
    if(Now == g[w].r + 1){
        if(k == g[w].v)Sum++;
        return;
    }
    int r1 = find(e[Now].u),r2 = find(e[Now].v);
    if(r1 != r2){
        fa[r1] = r2;
        Dfs(w,Now + 1,k + 1);
        fa[r1] = r1;fa[r2] = r2;
    }Dfs(w,Now + 1,k);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i] = i;
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
    sort(e + 1,e + m + 1,comp);
    for(int i=1;i<=m;i++){
        if(e[i].c != e[i-1].c){g[++cnt].l = i;g[cnt-1].r = i - 1;}
        int r1 = find(e[i].u),r2 = find(e[i].v);
        if(r1 != r2){
            g[cnt].v++;tot++;
            fa[r1] = r2;
        }
    }g[cnt].r = m;
    for(int i=1;i<=n;i++)fa[i] = i;
    if(tot != n - 1){printf("0\n");return 0;}
    for(int i=1;i<=cnt;i++){
        Sum = 0; Dfs(i, g[i].l, 0); Ans = (Ans * Sum) % p;
        for(int j=g[i].l;j<=g[i].r;j++){
            int r1 = find(e[j].u),r2 = find(e[j].v);
            if(r1 != r2)fa[r1] = r2;
        }
    }printf("%d\n",Ans % p);
    return 0;
}
