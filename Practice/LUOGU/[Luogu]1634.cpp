#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;
ll Pow(ll a, ll n, ll c = 1) {
	while(n) {
		if(n & 1) c = c * a;
		a = a * a;
		n >>= 1;
	}
	return c;
}

int main() {
	scanf("%lld%lld", &n, &k); ++n;
	cout << Pow(n, k) << endl;
	// for(;;);
	return 0;
}