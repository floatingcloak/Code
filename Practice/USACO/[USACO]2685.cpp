#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct node {
	int u, t;	
};

queue <node> Q;

const int Maxn = 1010000;

int n, k;
bool vis[Maxn];

int main() {
	scanf("%d%d", &n, &k);
	Q.push((node){n, 0}); vis[n] = 1;
	while(!Q.empty()) {
		node u = Q.front(); Q.pop();
		if(u.u == k) {
			printf("%d\n", u.t);
			return 0;
		}
		int now = u.u;
		if(k > now && !vis[now * 2] && now * 2 <= 1000000) {
			vis[now * 2] = 1;
			Q.push((node){now * 2, u.t + 1});
		}
		if(!vis[now + 1] && now <= 100000) {
			vis[now + 1] = 1;
			Q.push((node){now + 1, u.t + 1});
		}
		if(!vis[now - 1] && now >= 2) {
			vis[now - 1] = 1;
			Q.push((node){now - 1, u.t + 1});
		}
	}
	return 0;
}
