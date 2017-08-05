#include <cstdio>
#include <cstring>
#include <iostream>

#define mod (1 << 31)

using namespace std;

typedef long long ll;

const int Maxn = 2000011;

int judge[Maxn], prime[300000], b[300000], res, ans[500], tot, n;
ll f[50];

int main() {
	judge[1] = 1;
	for(int i = 2; i <= 2000000; ++i) {
		if(!judge[i]) prime[++tot] = i;
		for(int j = 2; j <= tot && i * prime[j] <= 2000000; ++j) {
			judge[i * prime[j]] = 1;
			// cout << '!';
			if(i % prime[j] == 0) break;
		}
	}
	// cout << tot << endl;
	scanf("%d", &n);
	f[0] = 0; f[1] = 1;
	for(int i = 2; i <= n; ++i) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	ll c = f[n];
	for(int i = 1; i <= tot; ++i) {
		// cout << prime[i] << ' ';
		while(f[n] % prime[i] == 0) {
			b[i]++;
			f[n] /= prime[i];
		}
	}
	for(int i = 1; i <= tot; ++i) {
		for(int j = 1; j <= b[i]; ++j) ans[++res] = prime[i];
	}
	// cout << res << endl;;
	printf("%d=", c);
	for(int i = 1; i <= res; ++i) {
		if(i == res) printf("%d", ans[i]);
		else printf("%d*", ans[i]);
	}
	// for(;;);
	return 0;
}
