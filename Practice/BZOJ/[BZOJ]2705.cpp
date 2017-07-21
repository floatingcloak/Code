#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
//据神犇Faller说这题就是个phi%%%
//By sssSSSay
using namespace std;

const int Maxn = 1010;

typedef long long ll;

ll n, ans;
int m;

ll phi(ll x) {
	ll t = x;
	for(ll i = 2; i <= m; ++i) {
		if(x % i == 0) {
			t = t / i * (i - 1);
			while(x % i == 0) x/= i;
		}
	}
	if(x > 1) t = t / x * (x - 1);
	return t;
}

int main() {
	scanf("%lld", &n);
	m = sqrt(n);
	for(ll d = 1; d <= m; ++d) {
		if(n % d == 0) {
			ans += phi(n / d) * d;
			if(d * d < n) ans += (n / d) * phi(d);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
