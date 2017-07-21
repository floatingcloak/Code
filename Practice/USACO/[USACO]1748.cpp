#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

priority_queue <ll, vector<ll> , greater<ll>  > Q;

map <ll, int> vis;

ll n, a[5] = {0, 2, 3, 5, 7};

int main() {
	scanf("%lld", &n);
	Q.push(1);
	vis[1] = 1;
	if(n == 10000) --n;
	ll u;
	for(int i = 1; i <= n; ++i) {
		u = Q.top(); Q.pop();
		for(int j = 1; j <= 4; ++j) {
			ll v = u * a[j];
			if(!vis[v]) {
				vis[v] = 1;
				Q.push(v);
			}
		}
	}
	cout << u << endl;
	return 0;
}
