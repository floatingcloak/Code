#include<bits/stdc++.h>

#define N 100005
#define M (l+r>>1)
#define P (k<<1)
#define S (k<<1|1)
#define K l,r,k
#define L l,M,P
#define R M+1,r,S
#define Z int l=1,int r=n,int k=1

using namespace std;

int n,m;
struct node{bool u[2],v[2],a[2];}a[1<<18];
bool t[2][N];
// 结构体里的u是横着是否连通 v是竖着是否连通(1 是 右边 0 是 左边) a记的是对角线(1 是 副对角线 0 是 主对角线)
node merge(node u,node v,Z){//将 u 和 v 合并成 a 返回 a 
	node s[]={u,v},a;
	for(int i=0;i<=1;++i){//只要维护当前块的信息
		a.u[i] = ( s[0].u[i] && t[i][M] && s[1].u[i] )// M 是中点 
		|| ( s[0].a[i] && t[i^1][M] && s[1].a[i^1] );// M 是中点 

		a.v[i] = s[i].v[i]// 直接连接
		|| t[0][M] && s[i].u[0] && s[i].u[1] && t[1][M] && s[i^1].v[i];// 先横着走到另一个联通块里在走回来 

		a.a[i] = ( s[0].u[i] && t[i][M] && s[1].a[i] )//先斜着在横着或者反之 
		|| ( s[0].a[i] && t[i^1][M] && s[1].u[i^1] );
	}return a;
}

node Q(int s,int t,Z){
	if(s == l && t == r)return a[k];
	if(t <= M)return Q(s,t,L);
	if(s >  M)return Q(s,t,R);
	return merge(Q(s,M,L),Q(M+1,t,R),K);
}
//提取s到t的节点 
bool solve(int s,int t,int i,int j){
	node b = Q(s,t);node a = Q(1,s),c = Q(t,n);//提取这一段的节点 
    // u 是前 v 是后 a 是中间 
    // 结构体里的u是横着是否连通 v是竖着是否连通(1 是 右边 0 是 左边) a记的是对角线(1 是 副对角线 0 是 主对角线)
	return i == j ? ( b.u[i] || a.v[1] && b.u[i ^ 1] && c.v[0]) :
	((b.u[i] && c.v[0]) || (a.v[1] && b.u[j]) || (b.a[i])
	|| a.v[1] && b.a[j] && c.v[0]);//四种情况 
}

void build(Z){//建树...
	if(l == r)memset(a[k].u,1,2);
	else {build(L);build(R);}
}

void update(Z){a[k]=merge(a[P],a[S],K);}//把儿子们合并起来获取当前节点的信息 

void F(int t,Z){return l == r ? void() : ( t <= M ? F(t,L) : F(t,R) , update(K) );}//线段树的单点修改 (到底上一路Update上来)

void ChangeDif(int u,Z){
//	printf("%d %d %d %d %d\n",l,r,u,M,k);
	if(l == r)return;
	if(u <= M)ChangeDif(u,L);
	if(u >  M)ChangeDif(u,R);
	update(K);
}

void G(int s,int t,Z){
	if(l == r){//对于在同一列的情况进行直接操作 
		memset(a[k].v,s,2);
		memset(a[k].a,s,2);
	}else{
		if(t <= M)G(s,t,L);
		else G(s,t,R);
		update(K);//将递归操作后的子树合并 
	}
}

int main(){
	scanf("%d",&n);build();char s[8];
	while(scanf("%s",s) != EOF && s[0] != 'E'){
		int u,v,i,j;
		scanf("%d%d%d%d",&i,&u,&j,&v);--i,--j;
		if(u>v){swap(u,v);swap(i,j);}
		if(s[0] == 'A')puts(solve(u,v,i,j)?"Y":"N");
		else{
			bool z = s[0] == 'O';
			if(i != j)G(z , u);
			else {t[i][u] = z;ChangeDif(u);}//t[i][u]记录i行u列其右边是否连通 
		}
	}
}
