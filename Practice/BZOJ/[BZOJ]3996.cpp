#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define INF 1000000007
#define M 300300
 
using namespace std;
 
struct node {int v,c,next;}E[2002002];
 
int S = 0,T;
int n,x,y,z,m,Ans,sum = 1,cnt,H[M],dis[M];
 
void Link(int x,int y,int z){
    E[++sum].v = y;
    E[sum].c = z;
    E[sum].next = H[x];
    H[x] = sum;
}
 
void Add(int x,int y,int z){Link(x,y,z);Link(y,x,0);}
 
bool Bfs(){
    static int q[M];
    int h = 1,t = 1;
    memset(dis,-1,sizeof(dis));
    q[h] = S;dis[S] = 1;
    while(h <= t){
        int u = q[h];
        for(int i=H[u];i;i=E[i].next){
            int l = E[i].v;
            if(dis[l]==-1 && E[i].c){
                dis[l] = dis[u] + 1;
                q[++t] = l;
//              if(l == T)return 1;
            }
        }h++;
    }if(dis[T] == -1)return 0;
    else return 1;
}
  
int Max_Flow(int x,int Min){
    if(x == T)return Min;
    int val = Min;
    for(int i=H[x];i!=0;i=E[i].next){
        int l = E[i].v;
        if(E[i].c && dis[l] == dis[x] + 1){
            int Temp = Max_Flow(l,min(val,E[i].c));
            val -= Temp;
            E[i].c -= Temp;
            E[i^1].c += Temp;
        }
    }if(val)dis[x] = -1;
    return Min - val;
}
  
int main(){
    scanf("%d%d",&n,&m);T = n + m + 1;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        Add(i + m,T,x);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);Ans += z;
        Add(i,x+m,INF);Add(i,y+m,INF);Add(S,i,z);
    }
    while(Bfs())Ans -= Max_Flow(S,INF);
    printf("%d\n",Ans);
    // while(1);
    return 0;
}