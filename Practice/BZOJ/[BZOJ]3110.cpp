#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
#define INF 1e9 + 7
 
using namespace std;
 
const int Maxn = 510000;
 
struct node {
	int p,a,b,c,w,ans;	
} q[Maxn], q1[Maxn], q2[Maxn];
 
int n,m,t1[Maxn],t2[Maxn],temp[Maxn],w[Maxn];
bool vis[Maxn];
 
bool comp(node a,node b) {return a.w < b.w;}
 
void Add(int x,int c) {
	for(int i = x; i <= n; i += i & (-i)) {
		t1[i] += c;
		t2[i] += c * x;	
	}
}

int Query(int x,int temp = 0) {
	for(int i = x; i; i -= i & (-i))temp += (x + 1) * t1[i] - t2[i];
	return temp;	
}

void Solve(int l,int r,int a,int b) {
	if(a > b) return;
	if(l == r) {
		for(int i = a; i <= b; ++i) {
			if(q[i].p == 2) q[i].ans = l;
		}
		return;
	}
	int mid = (l + r) / 2;
	for(int i = a; i <= b; ++i) {
		if(q[i].p == 1 && q[i].c > mid) {
			Add(q[i].a, 1);
			Add(q[i].b + 1, -1);
		}
		else if(q[i].p == 2){
			temp[i] = Query(q[i].b) - Query(q[i].a - 1);
		}
	}
	for(int i = a; i <= b; ++i) {
		if(q[i].p == 1 && q[i].c > mid) {
			Add(q[i].a, -1);
			Add(q[i].b + 1, 1);
		}
	}
	int l1 = 0,l2 = 0;
	for(int i = a; i <= b; ++i) {
		if(q[i].p == 2) {
			if(temp[i] < q[i].c) {
				q[i].c -= temp[i];
				q1[++l1] = q[i];
			}
			else q2[++l2] = q[i];
		}
		else {
			if(q[i].c <= mid) q1[++l1] = q[i];
			else q2[++l2] = q[i];
		}
	}
	for(int i = a, j = 1; i <= b; ++i, ++j) {
		if(j <= l1) q[i] = q1[j];
		else q[i] = q2[j - l1];
	}
	Solve(l,mid,a,a + l1 - 1);
	Solve(mid + 1,r,a + l1,b);
}
 
int main() {
	freopen("zjoi13_sequence.in","r",stdin);
	freopen("zjoi13_sequence.out","w",stdout);
	n = read(); m = read();
	for(int i = 1, p, a, b, c; i <= m; ++i) {
		p = read(); a = read(); b = read(); c = read();
		q[i].p = p; q[i].c = c;
		q[i].a = a; q[i].b = b;
		q[i].w = i;
	}
	Solve(1,n,1,m);
	sort(q + 1,q + 1 + m,comp);
	for(int j = 1; j <= m; ++j) {
		int i = q[j].w;
		if(q[i].p == 2) printf("%d\n",q[i].ans);
	}
	return 0;
}
