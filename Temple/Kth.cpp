#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 1000000

using namespace std;

const int Maxn = 101000;

struct node {
	int w,p,num;	
} a[Maxn];

int sum[Maxn * 30],rs[Maxn * 30],ls[Maxn * 30],rt[Maxn * 30];
int cnt,n,x,m;

int Query(int o,int l,int r,int a,int b) {
	if(l >= a && r <= b) return sum[o];
	int mid = (l + r) >> 1;
	if(b <= mid) return Query(ls[o],l,mid,a,b);
	else if(a > mid) return Query(rs[o],mid + 1,r,a,b);
	else return Query(ls[o],l,mid,a,b) + Query(rs[o],mid + 1,r,a,b);
}

void Add(int l,int r,int c,int x,int &y) {
	y = ++cnt;sum[y] = sum[x] + 1;
	ls[y] = ls[x];rs[y] = rs[x];
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(c <= mid) Add(l,mid,c,ls[x],ls[y]);
	else Add(mid + 1,r,c,rs[x],rs[y]);
}

int Solve(int x,int y,int z) {
	x = rt[x - 1]; y = rt[y];
	int l = 1,r = N,ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		int temp = Query(y,1,N,mid,N) - Query(x,1,N,mid,N);
		if(temp >= z) l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	return ans;
}

bool comp1(node a,node b) {return a.w < b.w;}

bool comp2(node a,node b) {return a.p < b.p;}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		cnt = 0;map <int,int> hs;
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; ++i) {
			scanf("%d",&a[i].w);
			a[i].p = i;
		}
		sort(a + 1,a + n + 1,comp1);
		for(int i = 1; i <= n; ++i) {
			a[i].num = i;
			hs[i] = a[i].w;
		}
		sort(a + 1,a + n + 1,comp2);
		for(int i = 1; i <= n; ++i) Add(1,N,a[i].num,rt[i - 1],rt[i]);
		while(m--) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			c = (b - a + 1) - c + 1;
			printf("%d\n",hs[Solve(a,b,c)]);
		}
	}
	return 0;
}
