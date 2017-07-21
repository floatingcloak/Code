#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 51;

typedef long long ll;

ll n, f[Maxn];

int main() {
	scanf("%lld", &n);
	f[1] = 1;
	for(int i = 2; i <= n; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	printf("%lld", f[n]);
	puts(".00");
	return 0;
}
