#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//乱搞？太特么难了。。。
//By sssSSSay 
using namespace std;

const int Maxn = 10100;

typedef long long ll;

ll n, A, B, C, Min, Max, ans;

struct node {
	ll p, h, s;	
} a[Maxn], b[Maxn];

bool comp1(node a,node b) {return a.p < b.p;}

bool comp2(node a,node b) {return a.h < b.h;}

int Check1(ll x) {return a[x].s >= Min && a[x].s <= Max;}

int Check2(ll x) {return b[x].s >= Min && b[x].s <= Max;}

int main() {
	scanf("%lld%lld%lld%lld", &n, &A, &B, &C);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &a[i].h, &a[i].s);
		a[i].p = A * a[i].h + B * a[i].s;
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1, comp1); 
	sort(b + 1, b + n + 1, comp2);
	for(int i = 1; i <= n; ++i) {
		Min = b[i].s,Max = C / B + Min;
		ll l = 0, r = 0, cnt = 0;
		for(int j = 1; j <= n; ++j)	{
			while(r < n && a[r + 1].p <= A * b[j].h + B * b[i].s + C)	{
				++r, cnt += Check1(r);
			}
			while(l < n && b[l + 1].h < b[j].h) {
				++l, cnt -= Check2(l);
			}
			ans = max(ans, cnt);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
