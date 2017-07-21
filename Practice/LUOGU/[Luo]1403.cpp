#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

int n;

int main() {
	scanf("%d", &n);
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += (ll)(n / i);
	}
	cout << ans << endl;
	return 0;
}
