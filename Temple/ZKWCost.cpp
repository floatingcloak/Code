#include <iostream>
#include <cstring>
#define MAXNODE 500
#define MAXEDGE MAXNODE*MAXNODE
#define MIN(a,b) ((a)<(b)?(a):(b))
#define OPPOSITE(x) (((x)&1)?((x)+1):((x)-1))
#define INFINIT ~0U>>1

using namespace std;

int n,m;
int N,S,T;
int begin[MAXNODE+1],end[MAXEDGE+1],next[MAXEDGE+1],c[MAXEDGE+1],cost[MAXEDGE+1],d[MAXNODE+1],cur[MAXNODE+1];
bool hash[MAXNODE+1];
int Count = 0;
int aug(int u,int f){
    if (u == T) return f;
    hash[u] = true;
    for (int now = cur[u]; now; now = next[now])
        if (c[now]&&!hash[end[now]]&&d[u] == d[end[now]]+cost[now])
            if (int tmp = aug(end[now],MIN(f,c[now])))
                return c[now] -= tmp,c[OPPOSITE(now)] += tmp,cur[u] = now,tmp;
    return 0;
}
bool modlabel(){
    int tmp = INFINIT;
    for (int i = 1; i<=N; i++)
        if (hash[i])
            for (int now = begin[i]; now; now = next[now])
                if (c[now]&&!hash[end[now]])
                    tmp = MIN(tmp,d[end[now]]+cost[now]-d[i]);
    if (tmp == INFINIT)return true;
    for (int i = 1; i<=N; i++)if (hash[i])hash[i] = false,d[i] += tmp;
    return false;
}
int CostFlow(){
    int costflow = 0,tmp;
    while (true){
        for (int i = 1; i<=N; i++)
            cur[i] = begin[i];
        while (tmp = aug(S,~0U>>1)){
            costflow += tmp*d[T];
            cout<<d[T];
            memset(hash,0,sizeof(hash));
        }
        if (modlabel())
            break;
    }
    return costflow;
}
void AddEdge(int a,int b,int flow, int v){
    Count++; next[Count] = begin[a]; begin[a] = Count; end[Count] = b; c[Count] = flow; cost[Count] = v;
    Count++; next[Count] = begin[b]; begin[b] = Count; end[Count] = a; c[Count] = 0; cost[Count] = -v;
}
int main(){
//    freopen("costflow.in","r",stdin);
//    freopen("costflow.out","w",stdout);
    scanf("%d%d",&n,&m);
    while (m--){
        int t1,t2,t3,t4;
        scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
        AddEdge(t1,t2,t3,t4);
    }
    S = 1,T = N = n;
    printf("%d\n",CostFlow());
    return 0;
}
