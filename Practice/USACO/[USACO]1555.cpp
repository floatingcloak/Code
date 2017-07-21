#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

char s1[Maxn], s2[Maxn];
int a[Maxn], b[Maxn];

int main() {
	scanf("%s", (s1 + 1));
	scanf("%s", (s2 + 1));
	int len1 = strlen(s1 + 1);
	int len2 = strlen(s2 + 1);
	for(int i = 1; i <= len1; ++i) a[i] = s1[i] - '0';
	for(int i = 1; i <= len2; ++i) b[i] = s2[len2 - i + 1] - '0';
	for(int i = 1; i <= len1; ++i) {
		int w = 0; a[i] ^= 1;
		for(int j = 1; j <= len1; ++j) w += a[j] * (1 << (len1 - j));
		int t = 0, c[50] = {0}, x = w;
		while(x) {
			c[++t] = x % 3;
			x /= 3;
		}
		int tot = 0;

		for(int j = len2; j >= 1; --j) if(c[j] != b[j]) ++tot;
		if(tot == 1) {
			printf("%d\n", w);
			// while(1);
			return 0;
		}
		a[i] ^= 1;
	}
	// while(1);
	return 0;
}