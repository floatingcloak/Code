#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll r,ans;

ll Gcd(ll a,ll b){return b == 0 ? a : Gcd(b,a % b);}

void Cal(ll d) {
	ll lim = (ll)sqrt(2 * r / d);
	for(ll a = 1; a <= lim; ++a) {
		ll b = (ll)sqrt(2 * r / d - a * a);
		if(Gcd(a,b) == 1 && a <= b && d * (a * a + b * b) == 2 * r) ++ans;
	}
}

int main() {
	scanf("%lld",&r);
	ll lim = (ll)sqrt(2.0 * r);
	for(ll d = 1; d <= lim; ++d) {
		if(2 * r % d == 0) {
			Cal(d);
			if(d * d != 2 * r) Cal(2 * r / d);
		}
	}
	printf("%lld",ans * 4);
	return 0;
}
