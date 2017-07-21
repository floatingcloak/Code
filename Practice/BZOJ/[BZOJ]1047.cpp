#include <cmath>
#include <deque>
#include <cstdio>
#include <cstring>
#include <iostream>
//二维滑动窗口，单调队列实现(似乎二维St表也可以？)
//By sssSSSay  
#define INF 10000000007

using namespace std;

const int Maxn = 1010;

typedef long long ll;

int a,b,m;
ll c[Maxn][Maxn],d[Maxn][Maxn],e[Maxn][Maxn];
ll f[Maxn][Maxn],g[Maxn][Maxn],ans = INF;

ll Abs(ll x) {return x < 0 ? (-x) : x;}

int main() {
//	freopen("square.in","r",stdin);
//	freopen("square.out","w",stdout);
	scanf("%d%d%d",&a,&b,&m);
	for(int i = 1; i <= a; ++i) {
		for(int j = 1; j <= b; ++j) scanf("%lld",&c[i][j]);
	}
	for(int i = 1; i <= a; ++i) {
		deque <int> Q;
		for(int j = 1; j <= m; ++j) {
			if(Q.empty()) Q.push_front(c[i][j]);
			else {
				while(!Q.empty() && Q.front() < c[i][j]) Q.pop_front();
				Q.push_front(c[i][j]);
			}
			d[i][j] = Q.back();
		}
		for(int j = m + 1; j <= b; ++j) {
			if(!Q.empty() && Q.back() == c[i][j - m]) Q.pop_back();
			while(!Q.empty() && Q.front() < c[i][j]) Q.pop_front();
			Q.push_front(c[i][j]);
			d[i][j] = Q.back();
		}
	}
	for(int j = 1; j <= b; ++j) {
		deque <int> Q;
		for(int i = 1; i <= m; ++i) {
			if(Q.empty()) Q.push_front(d[i][j]);
			else {
				while(!Q.empty() && Q.front() < d[i][j]) Q.pop_front();
				Q.push_front(d[i][j]);
			}
			e[i][j] = Q.back();
		}
		for(int i = m + 1; i <= a; ++i) {
			if(!Q.empty() && Q.back() == d[i - m][j]) Q.pop_back();
			while(!Q.empty() && Q.front() < d[i][j]) Q.pop_front();
			Q.push_front(d[i][j]);
			e[i][j] = Q.back();
		}
	}
	for(int i = 1; i <= a; ++i) {
		deque <int> Q;
		for(int j = 1; j <= m; ++j) {
			if(Q.empty()) Q.push_back(c[i][j]);
			else {
				while(!Q.empty() && Q.back() > c[i][j]) Q.pop_back();
				Q.push_back(c[i][j]);
			}
			f[i][j] = Q.front();
		}
		for(int j = m + 1; j <= b; ++j) {
			if(!Q.empty() && Q.front() == c[i][j - m]) Q.pop_front();
			while(!Q.empty() && Q.back() > c[i][j]) Q.pop_back();
			Q.push_back(c[i][j]);
			f[i][j] = Q.front();
		}
	}
	for(int j = 1; j <= b; ++j) {
		deque <int> Q;
		for(int i = 1; i <= m; ++i) {
			if(Q.empty()) Q.push_back(f[i][j]);
			else {
				while(!Q.empty() && Q.back() > f[i][j]) Q.pop_back();
				Q.push_back(f[i][j]);
			}
			g[i][j] = Q.front();
		}
		for(int i = m + 1; i <= a; ++i) {
			if(!Q.empty() && Q.front() == f[i - m][j]) Q.pop_front();
			while(!Q.empty() && Q.back() > f[i][j]) Q.pop_back();
			Q.push_back(f[i][j]);
			g[i][j] = Q.front();
		}
	}
	for(int i = m; i <= a; ++i) {
		for(int j = m; j <= b; ++j) ans = min(ans , Abs(e[i][j] - g[i][j]));
	}
	printf("%lld\n",ans);
	return 0;
}
