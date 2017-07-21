#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int mx,ans;
int ind,cnt,scc,top;
int n,m,X;
int last[100005],last2[100005];
int dfn[100005],low[100005],hav[100005],belong[100005],q[100005];
int r[100005],f[100005],g[100005],vis[100005];
bool inq[100005];
struct edge{int to,next;}e[2000005],ed[2000005];
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}
void ins(int u,int v)
{
    ed[++cnt].to=v;ed[cnt].next=last2[u];last2[u]=cnt;
    r[v]++;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++ind;
    q[++top]=x;inq[x]=1;
    for(int i=last[x];i;i=e[i].next)
        if(!dfn[e[i].to])
            tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
        else if(inq[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
    int now=0;
    if(low[x]==dfn[x])
    {
        scc++;
        while(now!=x)
        {
            now=q[top];top--;
            inq[now]=0;
            hav[scc]++;
            belong[now]=scc;
        }
    }
}
void rebuild()
{
    cnt=0;
    for(int x=1;x<=n;x++)
    {
        for(int i=last[x];i;i=e[i].next)
            if(belong[x]!=belong[e[i].to])
                ins(belong[x],belong[e[i].to]);
    }
}
void dp()
{
    int head=0,tail=0;
    for(int i=1;i<=scc;i++)
	{
		if(!r[i])q[tail++]=i;
		f[i]=hav[i];g[i]=1;
	}
    while(head!=tail)
    {
        int now=q[head];head++;
        for(int i=last2[now];i;i=ed[i].next)
		{
			r[ed[i].to]--;
			if(!r[ed[i].to])q[tail++]=ed[i].to;
			if(vis[ed[i].to]==now)continue;
			if(f[now]+hav[ed[i].to]>f[ed[i].to])
			{
				f[ed[i].to]=f[now]+hav[ed[i].to];
				g[ed[i].to]=g[now];
			}
			else if(f[now]+hav[ed[i].to]==f[ed[i].to])
				g[ed[i].to]=(g[ed[i].to]+g[now])%X;
			vis[ed[i].to]=now;
		}
    }
}
int main()
{
    n=read();m=read();X=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        insert(u,v);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	printf("%d\n", scc);
    rebuild();
    dp();
	for(int i=1;i<=scc;i++)
	{
		if(f[i]>mx)mx=f[i],ans=g[i];
		else if(f[i]==mx)ans=(ans+g[i])%X;
	}
	for(int i = 1; i <= scc; ++i) printf("%d ", f[i]);
	puts("");
	for(int i = 1; i <= scc; ++i) printf("%d ", g[i]);
	puts("");
    printf("%d\n%d\n",mx,ans);
	while(1);
    return 0;
}