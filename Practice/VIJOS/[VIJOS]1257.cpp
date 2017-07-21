#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 20100;

typedef long long ll;

struct node {
	int u, v;
	ll c;
} e[Maxn];

int n, AddLine, num, vis[Maxn], cnt[Maxn];

bool comp(node a, node b) {return a.c < b.c;}

int main() {
	scanf("%d", &n); ll sum = 0;
	for(int i = 1; i < n; ++i) {
		int x, y; ll z; scanf("%d%d%lld", &x, &y, &z);
		e[i].u = x; e[i].v = y; e[i].c = z;
		sum += z;
	}
	sort(e + 1, e + n, comp);
	int MaxNum = 0;
	for(int i = n - 1; i >= 1; --i) {
		if(e[n - 1].c == e[i].c) {++MaxNum;}
		else {AddLine = i; break;}
	}
	for(int i = 1; i <= AddLine; ++i) {
		int u = e[i].u, v = e[i].v;
		if(!vis[u] && !vis[v]) {
			vis[u] = vis[v] = ++num;
			cnt[num] = 2;
		}
		else {
			if(!vis[v] && vis[u] != 0) {
				vis[v] = vis[u];
				++cnt[vis[u]];
			}
			else if(vis[v] != 0 && !vis[u]) {
				vis[u] = vis[v];
				++cnt[vis[v]];
			}
		}
	}	
	ll Single = 0;
	for(int i = 1; i <= num; ++i) Single += (ll)((cnt[i] * (cnt[i] - 1)) / 2);
	ll Max = e[n - 1].c;
	ll N = (n * (n - 1)) / 2, M = Single;
	ll ans = (N - M - MaxNum) * (Max + 1);
	// printf(">>%d", (N - M - MaxNum));
	// printf("%lld\n", ans + sum);
	ll ans1 = 0;
	for(int i = 1; i <= num; ++i) {
		// printf("@%d\n", cnt[i]);
		ans1 += ((cnt[i] * (cnt[i] - 1)) / 2) - (cnt[i] - 1);
	}
	ans1 *= Max;
	// printf("%lld %lld\n", ans1, ans);
	ans1 += ans + sum;
	printf("%lld\n", ans1);
	// while(1);
	return 0;
}