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
// �ṹ�����u�Ǻ����Ƿ���ͨ v�������Ƿ���ͨ(1 �� �ұ� 0 �� ���) a�ǵ��ǶԽ���(1 �� ���Խ��� 0 �� ���Խ���)
node merge(node u,node v,Z){//�� u �� v �ϲ��� a ���� a 
	node s[]={u,v},a;
	for(int i=0;i<=1;++i){//ֻҪά����ǰ�����Ϣ
		a.u[i] = ( s[0].u[i] && t[i][M] && s[1].u[i] )// M ���е� 
		|| ( s[0].a[i] && t[i^1][M] && s[1].a[i^1] );// M ���е� 

		a.v[i] = s[i].v[i]// ֱ������
		|| t[0][M] && s[i].u[0] && s[i].u[1] && t[1][M] && s[i^1].v[i];// �Ⱥ����ߵ���һ����ͨ�������߻��� 

		a.a[i] = ( s[0].u[i] && t[i][M] && s[1].a[i] )//��б���ں��Ż��߷�֮ 
		|| ( s[0].a[i] && t[i^1][M] && s[1].u[i^1] );
	}return a;
}

node Q(int s,int t,Z){
	if(s == l && t == r)return a[k];
	if(t <= M)return Q(s,t,L);
	if(s >  M)return Q(s,t,R);
	return merge(Q(s,M,L),Q(M+1,t,R),K);
}
//��ȡs��t�Ľڵ� 
bool solve(int s,int t,int i,int j){
	node b = Q(s,t);node a = Q(1,s),c = Q(t,n);//��ȡ��һ�εĽڵ� 
    // u ��ǰ v �Ǻ� a ���м� 
    // �ṹ�����u�Ǻ����Ƿ���ͨ v�������Ƿ���ͨ(1 �� �ұ� 0 �� ���) a�ǵ��ǶԽ���(1 �� ���Խ��� 0 �� ���Խ���)
	return i == j ? ( b.u[i] || a.v[1] && b.u[i ^ 1] && c.v[0]) :
	((b.u[i] && c.v[0]) || (a.v[1] && b.u[j]) || (b.a[i])
	|| a.v[1] && b.a[j] && c.v[0]);//������� 
}

void build(Z){//����...
	if(l == r)memset(a[k].u,1,2);
	else {build(L);build(R);}
}

void update(Z){a[k]=merge(a[P],a[S],K);}//�Ѷ����Ǻϲ�������ȡ��ǰ�ڵ����Ϣ 

void F(int t,Z){return l == r ? void() : ( t <= M ? F(t,L) : F(t,R) , update(K) );}//�߶����ĵ����޸� (������һ·Update����)

void ChangeDif(int u,Z){
//	printf("%d %d %d %d %d\n",l,r,u,M,k);
	if(l == r)return;
	if(u <= M)ChangeDif(u,L);
	if(u >  M)ChangeDif(u,R);
	update(K);
}

void G(int s,int t,Z){
	if(l == r){//������ͬһ�е��������ֱ�Ӳ��� 
		memset(a[k].v,s,2);
		memset(a[k].a,s,2);
	}else{
		if(t <= M)G(s,t,L);
		else G(s,t,R);
		update(K);//���ݹ������������ϲ� 
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
			else {t[i][u] = z;ChangeDif(u);}//t[i][u]��¼i��u�����ұ��Ƿ���ͨ 
		}
	}
}
