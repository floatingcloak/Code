#include <cstdio>
#include <cstring>
#include <iostream>

#define S 0
#define T n + m + 1

using namespace std;

const int Maxn = 1010;

struct node {int to,next,val;}e[Maxn];

int n,m,tot = 1,h[Maxn];

void Add(int u,int v,int c){e[++tot].to = v;e[tot].next = h[u];e[tot].val = c;h[u] = tot;}

void Link(int u,int v,int c){Add(u,v,c);Add(v,u,c);}

int Bfs(){
    queue <int> Q;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i <  n; i++)Link(i + m + 1,T,1);
    for(int i = 1; i <= m; i++){
        int x,y;scanf("%d%d",&x,&y);
        Link(S,i,1);Link(i,x + m + 1,1);Link(i,y + m + 1,1);
    }
    while(Bfs() != -1)Ans += Dfs(0,INF);
    printf("%d\n",Ans);
    while(1);
    return 0;
}