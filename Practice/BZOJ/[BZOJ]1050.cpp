#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//同舒适的路线，枚举一头枚举另一头直接并查集判断。 
//By sssSSSay 
#define INF 1e9

using namespace std;

const int Maxn = 640;

struct Node {
	int u,v,c;	
} e[5100];

double ans = INF;
int n,m,x,y,c,s,t,son,mot,h[Maxn],fa[Maxn];

bool Comp(Node a,Node b) {return a.c < b.c;}

int Gcd(int a,int b) {return b == 0 ? a : Gcd(b,a % b);}

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

int main() {
//	freopen("comf.in","r",stdin);
//	freopen("comf.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d",&x,&y,&c);
		e[i].u = x;
		e[i].v = y;
		e[i].c = c;
	}
	scanf("%d%d",&s,&t);
	sort(e + 1,e + m + 1,Comp);
	for(int i = 1; i <= m; ++i) {
		int minc = e[i].c,maxc = e[i].c,j;
		fa[Find(e[i].u)] = Find(e[i].v);
		for(j = i + 1; j <= m; ++j) {
			if(Find(s) == Find(t))break;
			int r1 = Find(e[j].u),r2 = Find(e[j].v);
			if(r1 != r2) {
				fa[r1] = r2;
				maxc = max(maxc , e[j].c);
			}
		}
		int r1 = Find(s),r2 = Find(t);
		if(maxc != -INF && r1 == r2){
			double now = (double)maxc / (double)minc;
			if(now < ans) {
				ans = now;
				son = maxc;
				mot = minc;
			}
		}
		for(int i = 1; i <= n; ++i)fa[i] = i;
	}
	int gcd = Gcd(son,mot);
	if(ans == INF)printf("IMPOSSIBLE\n");
	else if(son % mot == 0)printf("%d\n",son / mot);
	else printf("%d/%d\n",son / gcd,mot / gcd);
}
