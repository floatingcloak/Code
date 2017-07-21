/**************************************************************
    Problem: 1001
    User: sssSSSay
    Language: C++
    Result: Accepted
    Time:1660 ms
    Memory:83324 kb
****************************************************************/
 
#include <cstdio>
#include <cstring>
#include <iostream>
 
#define INF 100000007
 
using namespace std;
 
struct node {int next,val,to;}E[6000010];
 
int n,m,tot,Ans,dis[1000010],H[1000010],q[1000010];
 
void Add(int u,int v,int c){E[++tot].next = H[u];E[tot].to = v;E[tot].val = c;H[u] = tot;}
 
void Link(int u,int v,int c){Add(u,v,c);Add(v,u,c);}

int Num(int x,int y){return (x - 1) * m + y;}//Get A Num For x , y
 
int Bfs(){
    memset(dis,-1,sizeof(dis));
    int h = 1,t = 1;dis[1] = 0;q[h] = 1;
    while(h <= t){
        int u = q[h];
        for(int i=H[u];i;i=E[i].next){
            int v = E[i].to;
            if(dis[v] == -1 && E[i].val){
                dis[v] = dis[u] + 1;
                q[++t] = v;
            }
        }h++;
    }if(dis[n * m] == -1)return 0;
    return 1;
}
 
int Max_Flow(int x,int Min){
    if(x == n * m)return Min;
    int w,used = 0;
    for(int i=H[x];i;i=E[i].next){
        int v = E[i].to;
        if(E[i].val && dis[v] == dis[x] + 1){
            w = Min - used;
            w = Max_Flow(v,min(w,E[i].val));
            used += w;
            E[i].val -= w;
            E[i+1].val += w;
            if(used == Min)return Min;
        }
    }if(!used)dis[x] = -1;
    return used;
}
 
int main(){
    freopen("bjrabbit.in","r",stdin);
    freopen("bjrabbit.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            scanf("%d",&x);
            Link(Num(i,j),Num(i,j+1),x);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&x);
            Link(Num(i,j),Num(i+1,j),x);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            scanf("%d",&x);
            Link(Num(i,j),Num(i+1,j+1),x);
        }
    }
    while(Bfs())Ans += Max_Flow(1,INF);
    printf("%d\n",Ans);
    // while(1);
    return 0;
}
