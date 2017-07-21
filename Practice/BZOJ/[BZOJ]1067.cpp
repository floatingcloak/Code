#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define lc (o << 1)
#define rc ((o << 1) + 1)
#define mid ((l + r) >> 1)

using namespace std;

const int Maxn = 50100;
const int N = 210100;

map <int, int> hs;

struct node {
	int y, w;
} a[Maxn], b[Maxn];

int n,m,maxn[N];

void Build(int l,int r,int o) {
	if(l == r) {
		maxn[o] = b[l].w;
		return;
	}
	Build(l, mid, lc);
	Build(mid + 1, r, rc);
	maxn[o] = max(maxn[lc], maxn[rc]);
}

int Query(int l,int r,int o,int a,int b) {
	if(l >= a && r <= b) return maxn[o];
	if(b <= mid) return Query(l, mid, lc, a, b);
	else if(a > mid) return Query(mid + 1, r, rc, a, b);
	else return max(Query(l, mid, lc, a, b), Query(mid + 1, r, rc, a, b));
}

int Find2(int x,int l = 1, int r = n, int ans = 0) {
	while(l <= r) {
		int mid1 = (l + r) >> 1;
		if(a[mid1].y <= x) l = mid1 + 1, ans = mid1;
		else r = mid1 - 1;
	}
	return hs[a[ans].y];
}

int Find1(int x,int l = 1, int r = n, int ans = 0) {
	while(l <= r) {
		int mid1 = (l + r) >> 1;
		if(a[mid1].y >= x) r = mid1 - 1, ans = mid1;
		else l = mid1 + 1;
	}
	return hs[a[ans].y];
}

int main() {
//	freopen("test.in","r",stdin);
//	freopen("my.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) scanf("%d%d",&a[i].y,&a[i].w);
	for(int i = 1; i <= n; ++i) {
		b[i].y = b[i - 1].y + 1;
		b[i].w = a[i].w;
		hs[a[i].y] = i;
	}
	Build(0, n, 1);
	scanf("%d",&m);
	for(int i = 1, a, c, xx, yy; i <= m; ++i) {
		scanf("%d%d",&a,&c);
		xx = hs[a]; yy = hs[c];
		if(a > c) puts("false");
		else {
			int delta = (c - a) - (yy - xx) ,vx = b[xx].w, vy = b[yy].w, maxx = 0;
			int ll = Find1(a), rr = Find2(c);
			if(xx && yy && xx + 1 <= yy - 1) maxx = Query(0, n, 1, xx + 1,yy - 1);	
			else if(!xx && yy && ll <= yy - 1) maxx = Query(0, n, 1, ll, yy - 1);
			else if(xx && !yy && xx + 1 <= rr) maxx = Query(0, n, 1, xx + 1, rr);
			else if(!xx && !yy && ll <= rr)maxx = Query(0, n, 1, ll, rr);
			
			if(xx && yy && vy <= vx && delta == 0 && maxx < vy) puts("true");
			else {
				if(xx && yy && yy == xx + 1 && vy <= vx) puts("maybe");
				else if(!xx && !yy) puts("maybe");
				else if(xx == n && c > a) puts("maybe");
				else if(yy == 1 && a < c) puts("maybe");
				else if(xx && yy && vx >= vy && delta != 0 && maxx < vy) puts("maybe");
				else if(!xx && yy && (maxx < vy || yy == xx + 1)) puts("maybe");
				else if(xx && !yy && (maxx < vx || yy == xx + 1)) {
					puts("maybe");
				}
				else puts("false");
			}
		}
	}
	return 0;
}
