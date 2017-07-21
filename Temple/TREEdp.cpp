#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define inf 1000000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt,tot,ans;
int P[55],L[55],M[55];
int f[55][105][2005];
int g[55][2005],h[55][2005];
char ch[5];
int last[55],deg[55];
struct data{int to,next,v;}e[20005];
void insert(int u,int v,int w){
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
    deg[v]++;
}
void dp(int x){
    if(!last[x]){
        L[x]=min(L[x],m/M[x]);//叶节点
        for(int i=0;i<=L[x];i++)
            for(int j=i;j<=L[x];j++)
                f[x][i][j*M[x]]=(j-i)*P[x];
        return;
    }
    L[x]=inf;
    for(int i=last[x];i;i=e[i].next){//先处理儿子
        dp(e[i].to);
        L[x]=min(L[x],L[e[i].to]/e[i].v);
        M[x] += e[i].v*M[e[i].to];
    }
    L[x]=min(L[x],m/M[x]);
    memset(g,-0x3f3f3f3f,sizeof(g));
    g[0][0]=0;
    for(int l=L[x];l>=0;l--){
        int tot=0;
        for(int i=last[x];i;i=e[i].next){
            tot++;
            for(int j=0;j<=m;j++)
                for(int k=0;k<=j;k++)
                    g[tot][j]=max(g[tot][j],g[tot-1][j-k]+f[e[i].to][l*e[i].v][k]);
        }
        for(int j=0;j<=l;j++)
            for(int k=0;k<=m;k++)
                f[x][j][k]=max(f[x][j][k],g[tot][k]+P[x]*(l-j));
    }
}
int main(){
    memset(f,-0x3f3f3f3f,sizeof(f));
    n=read();m=read();
    for(int i=1;i<=n;i++){
        P[i]=read();
        scanf("%s",ch);
        if(ch[0]=='A'){
            int x=read();
            while(x--){
                int v=read(),num=read();
                insert(i,v,num);//Read
            }
        }
        else M[i]=read(),L[i]=read();
    }    
    for(int x=1;x<=n;x++)
		if(!deg[x]){
			dp(x);
			tot++;
			for(int i=0;i<=m;i++)
				for(int j=0;j<=i;j++)
					for(int k=0;k<=L[x];k++)
						h[tot][i]=max(h[tot][i],h[tot-1][j]+f[x][k][i-j]);
		}
	for(int i=0;i<=m;i++)ans=max(ans,h[tot][i]);
    printf("%d\n",ans);
    return 0;
}