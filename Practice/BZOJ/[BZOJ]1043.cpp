#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define pi acos(-1)

using namespace std;

const int Maxn = 1100;

struct node {
	double l,r;	
}q[Maxn];

int n,tot;
double x[Maxn],y[Maxn],r[Maxn],ans;

bool Comp(node a,node b) {return a.l < b.l;}

double Dis(int a,int b) {
	double x1 = x[a],x2 = x[b],y1 = y[a],y2 = y[b];
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));	
}

void Insert(int a,int b) {
	double d = Dis(a,b);
	double t = (r[a] * r[a] - r[b] * r[b] + d * d) / (2 * d);
	double st = atan2((x[a] - x[b]),(y[a] - y[b]));
	double de = acos(t / r[a]);
	q[++tot].l = st - de;
	q[tot].r = st + de;
}

bool In(int a,int b) {
	if(r[b] - r[a] >= Dis(a,b)) return 1;
	else return 0;
}

double Cal(int x) {
	for(int i = x + 1; i <= n; ++i) if(In(x,i)) return 0;
	tot = 0;
	for(int i = x + 1; i <= n; ++i) {
		if(!In(i,x) && r[x] + r[i] >= Dis(x,i)) Insert(x,i);
	}
	double temp = 0,now = 0;
	for(int i = 1; i <= tot; ++i) {
		if(q[i].l < 0)q[i].l += 2 * pi;
		if(q[i].r < 0)q[i].r += 2 * pi;
		if(q[i].l > q[i].r) {
			q[++tot].l = 0;
			q[tot].r = q[i].r;
			q[i].r = 2 * pi;	
		}
	}
	sort(q + 1,q + tot + 1,Comp);
	for(int i = 1; i <= tot; ++i) {
		if(q[i].l > now) {
			temp += q[i].l - now;
			now = q[i].r;
		}
		else now = max(now,q[i].r);
	}
	temp += 2 * pi - now;
//	cout<<temp<<endl;
	return temp * r[x];
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lf%lf%lf",&r[i],&x[i],&y[i]);
	}
	for(int i = 1; i <= n; ++i) {
		ans += Cal(i);
	}
	printf("%.3lf\n",ans);
	return 0;
}
