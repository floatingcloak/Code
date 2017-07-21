#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 600010;

struct node {int to,next;}E[Maxn*2];

int n,m,tot,H[Maxn],cnt,sum,f[Maxn][33],k,w,fa[Maxn],deep[Maxn];

void Insert(int u,int v){E[++tot].to = v;E[tot].next = H[u];H[u] = tot;}

void Dfs(int x){
    for(int i=1;i<=30;i++){
        if(deep[x] < (1 << i))break;
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for(int i=H[x];i;i=E[i].next){
        int v = E[i].to;
        if(deep[v] == -1){
            f[v][0] = x;
            deep[v] = deep[x] + 1;
            Dfs(v);
        }
    }
}

void adjust(int &x,int h) {
	for(int i=30;i>=0;i--) {
		if(deep[f[x][i]]>=h) {
			x=f[x][i];
        }
    }
}

int query(int x,int y) {
	if(deep[y]>deep[x]) adjust(y,deep[x]);
	if(deep[y]<deep[x]) adjust(x,deep[y]);
	if(x==y) return x;
	for(int i=30;i>=0;i--) 
		if(f[x][i]!=f[y][i]){
            x=f[x][i],y=f[y][i];
        }
	if(x==y) return x;
	return f[x][0]
}

int main(){
    memset(deep,-1,sizeof(deep));
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Insert(x,y);
        Insert(y,x);
    }
    deep[w] = 0;Dfs(w);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        printf("%d\n",query(x,y));
    }   
    // while(1);
    return 0;
}
