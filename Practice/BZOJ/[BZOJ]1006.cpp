#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10010;

struct node {int to,next;}E[2000010];

int n,m,q[Maxn],col[Maxn],hash[Maxn],tot,H[Maxn],Ans,best,lian[1355000],tou[1355000],lin[1355000];
int belong[1355000],cnt,val[1355000];
bool vis[Maxn];

inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

void Insert(int u,int v){E[++tot].to = v;E[tot].next = H[u];H[u] = tot;}

int main(){
    n = read();m = read();
    for(int i=1;i<=m;++i){
        int x,y;x = read();y = read();
        Insert(x,y);Insert(y,x);
    }
	tou[0] = ++cnt;val[cnt] = 1;
    for(int i = 2;i <= n;++i){++cnt;
    	lin[cnt - 1] = cnt;
		val[cnt] = i;
	}
	lin[cnt] = -1;
    for(int i = n;i >= 1;--i){
    	int j,k = 0,l = -1;
    	for(j = tou[best];;){
    		if(!vis[val[j]]){k = val[j];break;}
    		if(l == -1)tou[best] = lin[j];
    		else lin[l] = lin[j];
			l = j;j = lin[j];
    		if(j == 0){--best;j = tou[best];l = -1;}
    	}
    	vis[k] = 1;q[i] = k;
    	for(int z = H[k];z;z = E[z].next){
    		int v = E[z].to;++cnt;
			lin[cnt] = tou[++belong[v]];val[cnt] = v;
			tou[belong[v]] = cnt;
			best = max(best,belong[v]);
    	}
    }
    for(int i=n;i>=1;--i){
        int u = q[i],j;
        for(int k=H[u];k;k=E[k].next)hash[col[E[k].to]] = i;
        for(j=1;;++j)if(hash[j] != i)break;
        col[u] = j;if(j > Ans)Ans = j;
    }
    printf("%d\n",Ans);
    return 0;
}
