#include <cstdio>
#include <cstring>
#include <iostream>

#define S 0
#define T n * m + 1
#define INF 1000000007

using namespace std;

const int Maxn = 110;

struct node {
    int to,next,val;
}e[100010];

int n,m,map[Maxn][Maxn],h[Maxn * Maxn + 10],dis[Maxn];

int num(int i,int j){return (i - 1) * m + j;}

void Link(int u,int v,int c){Add(u,v,c);Add(v,u,0);}

void Add(int u,int v,int c){e[++tot].to = v;e[tot].next = h[u];e[tot].val = c;h[u] = tot;}

int Bfs(){
    queue <int> Q;
    memset(dis,-1,sizeof(dis));
    Q.push(S);dis[S] = 0;
    while(!Q.empty()){
        int u = Q.front();Q.pop();
        for(int i=h[u];i;i=e[i].next){
            int v = e[i].to;
            if(dis[v] == -1 && e[i].val){
                dis[v] = dis[u] + 1;
                Q.push(v);
            }
        }
    }return dis[T];
}

int Dfs(int u,int Min){
    if(u == T)return Min;
    int used = 0,w;
    for(int i=cur[u];i;i=e[i].next){
        int v = e[i].to;
        if(dis[v] == dis[u] + 1 && e[i].val){
            w = Min - used;
            w = Dfs(v,min(w,e[i].val));
            used += w;
            e[i].val -= w;
            e[i ^ 1].val += w;
            if(e[i].val)cur[u] = i;
            if(used == Min)return Min;
        }
    }if(!used)dis[u] = -1;
    return used;
}

int main(){
    // freopen("ws.in","r",stdin);
    // freopen("ws.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2)Link(S,num(i,j),INF-1);
            if(map[i][j] == 1)Link(num(i,j),T,INF-1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){int w = num(i,j);
            if(i > 1)Link(w,num(i - 1,j),1);
            if(j > 1)Link(w,num(i,j - 1),1);
            if(i < n)Link(w,num(i + 1,j),1);
            if(j < m)Link(w,num(i,j + 1),1);
        }
    }int Ans = 0;
    while(Bfs() != -1)Ans += Dfs(S,INF);
    printf("%d\n",Ans);
    return 0;
}