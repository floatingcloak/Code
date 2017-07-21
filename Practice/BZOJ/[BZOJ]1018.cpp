#include <cstdio>
#include <cstring>
#include <iostream>

#define mid (l + r) / 2
#define rc (o * 2 + 1)
#define lc (o * 2)

using namespace std;

const int Maxn = 100100;

int n,m;
char s[8];
struct node {bool u[2],v[2],a[2];}a[1<<18];
bool t[2][Maxn];//维护横向连通性 

inline void G(int & x) {
	x = 0; int y = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') y = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	x *= y;
}

node Merge(node f,node s,int l,int r,int o){
	node x[] = {f,s},A;
	for(int i = 0;i <= 1;i++){
		A.u[i] = (x[0].u[i] && t[i][mid] && x[1].u[i]) ||
		(x[0].a[i] && t[i ^ 1][mid] && x[1].a[i ^ 1]);
		//两种选择
		A.v[i] = (x[i].v[i]) || 
		(x[i].u[0] && x[i].u[1] && t[0][mid] && t[1][mid] && x[i ^ 1].v[i]); 
		//同样两种选择
		A.a[i] = (x[0].u[i] && t[i][mid] && x[1].a[i]) ||
		(x[0].a[i] && t[i ^ 1][mid] && x[1].u[i ^ 1]);//同样 
	}return A; 
}

node Get(int s,int t,int l,int r,int o){
	if(s <= l && t >= r)return a[o];
	if(t <= mid)return Get(s,t,l,mid,lc);
	if(s >  mid)return Get(s,t,mid + 1,r,rc);
	return Merge(Get(s,mid,l,mid,lc),Get(mid + 1,t,mid + 1,r,rc),l,r,o);
}

bool Query(int s,int t,int i,int j){
	node a = Get(1,s,1,n,1),b = Get(s,t,1,n,1),c = Get(t,n,1,n,1);
	return i == j ? ( b.u[i] || a.v[1] && b.u[i ^ 1] && c.v[0]) :
	((b.u[i] && c.v[0]) || (a.v[1] && b.u[j]) || (b.a[i])
	|| a.v[1] && b.a[j] && c.v[0]);
}

void Build(int l,int r,int o){
	if(l == r)memset(a[o].u,1,2);
	else {Build(l,mid,lc);Build(mid + 1,r,rc);}	
}

void Update(int l,int r,int o){a[o] = Merge(a[lc],a[rc],l,r,o);}

void ChangeSame(int l,int r,int o,int b,int p){
	if(l == r){memset(a[o].v,p,2);memset(a[o].a,p,2);}
	else {
		if(b <= mid)ChangeSame(l,mid,lc,b,p);
		if(b >  mid)ChangeSame(mid + 1,r,rc,b,p);
		Update(l,r,o);	
	}
}

void ChangeDif(int l,int r,int o,int u){
	if(l == r)return;
	if(u <= mid)ChangeDif(l,mid,lc,u);
	if(u >  mid)ChangeDif(mid + 1,r,rc,u);
	Update(l,r,o);
}

int main(){
	freopen("bzoj_1018.in","r",stdin);
	freopen("bzoj_1018.out","w",stdout);
	G(n);Build(1,n,1);
	while(scanf("%s",s) != EOF && s[0] != 'E'){
		int x1,y1,x2,y2;G(x1);G(y1);G(x2);G(y2);x1--;x2--;
		if(y1 > y2)swap(y1,y2),swap(x1,x2);
		if(s[0] == 'A'){printf("%c\n",Query(y1,y2,x1,x2) ? 'Y' : 'N');}
		else {
			if(x1 != x2)ChangeSame(1,n,1,y1,s[0] == 'O');
			else {t[x1][y1] = s[0] == 'O';ChangeDif(1,n,1,y1);}	
		}
	}
	return 0;
}
