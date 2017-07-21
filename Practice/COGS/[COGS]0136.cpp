#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

typedef long long ll;

char s1[Maxn], s2[Maxn];
ll ans = 0;

int main() {
	freopen("cowmult.in","r",stdin);
	freopen("cowmult.out","w",stdout);
	scanf("%s%s", (s1 + 1), (s2 + 1));
	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	for(int i = 1; i <= len1; ++i) {
		for(int j = 1; j <= len2; ++j) {
			ans += (ll)(s1[i] - '0') * (ll)(s2[j] - '0');	
		}
	}
	printf("%lld\n", ans);
	return 0;
}
