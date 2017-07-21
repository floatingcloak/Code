#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//背板子系列之凸包 + 旋转卡壳 
//By sssSSSay
#define eps 1e-8

using namespace std;

const int Maxn = 5010;

struct node {
	double x, y;	
} p[Maxn], g[Maxn];

int n;
double ans;

node operator - (node a, node b) {return (node){a.x - b.x, a.y - b.y};}

node operator + (node a, node b) {return (node){a.x + b.x, a.y + b.y};}

node operator * (node a, double x) {return (node){a.x * x, a.y * x};}

node operator / (node a, double x) {return (node){a.x / x, a.y / x};}

int dcmp(double x) {return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1);}

double cross(node a,node b) {return a.x * b.y - a.y * b.x;}

bool comp(node a, node b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double Dot(node a,node b) {return a.x * b.x + a.y * b.y;}

double Len(node a) {return sqrt(Dot(a, a));}

double Dis(node x,node a,node b) {node v1 = b - a, v2 = x - a; return fabs(cross(v1, v2) / Len(v1));}

double Area(node a,node b,node c) {return cross(b - a, c - a) / 2;}

double CalArea(node a,node b,int m) {
	double sum1 = 0,sum2 = 0;
	for(int i = 1; i <= m; ++i) {
		sum1 = max(sum1, Area(g[i], a, b));
		sum2 = min(sum2, Area(g[i], a, b));
	}
	return sum1 + (-sum2);
}

int Gra() {
	sort(p + 1, p + n + 1, comp);
	int m = 0;
	for(int i = 1; i <= n; ++i) {
		while(m > 1 && dcmp(cross(g[m - 1] - g[m - 2], p[i] - g[m - 2])) <= 0) --m;
		g[m++] = p[i];
	}
	int k = m;
	for(int i = n - 1; i >= 1; --i) {
		while(m > k && dcmp(cross(g[m - 1] - g[m - 2], p[i] - g[m - 2])) <= 0) --m;
		g[m++] = p[i];	
	}
	if(n > 1) m--;
	return m;
}

double RoCa(int m) {
	if(m == 1 || m == 2) return 0;
	int now = 2; double temp = 0;
	g[m + 1] = g[1];
	
	for(int i = 1; i <= m; ++i) {
		while(dcmp(Dis(g[now], g[i], g[i + 1]) - Dis(g[now + 1], g[i], g[i + 1])) < 0) {
			++now; if(now == m + 1) now = 1;
//			printf("!");
		}
		//这样找到的是g[i]对应的对踵点g[now] 即距离g[i]最远的点 
		temp = max(temp, CalArea(g[i], g[now], m));
	}
	return temp;
}

int main() {
//	freopen("test.in","r",stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	int m = Gra();
	ans = RoCa(m);
	printf("%.3lf\n", ans);
	return 0;
}
