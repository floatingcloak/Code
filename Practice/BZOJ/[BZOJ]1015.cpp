#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 400010;

struct node {int to,next;}E[Maxn];

inline char NC(void)
{
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}

inline int read() {
    static char c; c = NC(); 
    int x;
    static int minus; minus = 1;
    for (x = 0; !(c >= '0' && c <= '9'); c = NC()) if(c == '-') minus = -1;
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = NC()); x *= minus;
    return x;
}

bool vis[Maxn];
int a[Maxn],n,tot,k,m,cnt,res;
int H[Maxn],fa[Maxn],x[Maxn],y[Maxn],Ans[Maxn];

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

void Add(int u,int v){E[++cnt].to = v;E[cnt].next = H[u];H[u] = cnt;}

int main(){
    freopen("bzoj_1015.in","r",stdin);
    freopen("bzoj_1015.out","w",stdout);
    n = read(); m = read(); 
    for(int i=0;i< n;i++)fa[i] = i;
    for(int i=1;i<=m;i++){
    	x[i] = read(); y[i] = read();
        Add(x[i],y[i]);Add(y[i],x[i]);
    }
    k = read();
	for(int i=1;i<=k;i++){
        a[i] = read();
        vis[a[i]] = 1;
    }
    for(int i=0;i< n;i++){
        if(!vis[i]){
            tot++;int u = i;
            for(int j=H[u];j;j=E[j].next){
                int v = E[j].to;
                if(!vis[v]){
                   int r1 = find(u),r2 = find(v);
                    if(r1 != r2){fa[r1] = r2;tot--;}
                }
            }
        }
    }
    Ans[++res] = tot;
    for(int i=k;i>=1;i--){
        int u = a[i];vis[u] = 0;tot++;
        for(int j=H[u];j;j=E[j].next){
            int v = E[j].to;
            if(!vis[v]){
                int r1 = find(u),r2 = find(v);
                if(r1 != r2){fa[r1] = r2;tot--;}
            }
        }Ans[++res] = tot;
    }
    for(int i=res;i>=1;i--)printf("%d\n",Ans[i]);
    return 0;
}
