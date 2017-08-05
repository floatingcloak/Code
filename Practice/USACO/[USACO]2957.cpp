#include <cstdio>
#include <cstring>
#include <iostream>

#define p 233

using namespace std;

const int Maxn = 10101;

char s1[Maxn], s2[Maxn], t[Maxn];
unsigned int pow[Maxn], hs1[Maxn], hs2[Maxn];

unsigned int Get1(int l, int r) {
	return hs1[r] - hs1[l - 1] * pow[r - l + 1];
}

unsigned int Get2(int l, int r) {
	return hs2[r] - hs2[l - 1] * pow[r - l + 1];
}

int main() {
	cin >> (s1 + 1) >> (s2 + 1);
	int l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
	if(l1 > l2) {
		for(int i = 1; i <= l2; ++i) t[i] = s2[i];
		for(int i = 1; i <= l1; ++i) s2[i] = s1[i];
		memset(s1, 0, sizeof s1);
		for(int i = 1; i <= l2; ++i) s1[i] = t[i];
		swap(l1, l2);
	}
	pow[0] = 1; hs1[0] = hs2[0] = 1;
	for(int i = 1; i <= max(l1, l2); ++i) pow[i] = pow[i - 1] * p;
	for(int i = 1; i <= l1; ++i) hs1[i] = hs1[i - 1] * p + s1[i] - 'a';
	for(int i = 1; i <= l2; ++i) hs2[i] = hs2[i - 1] * p + s2[i] - 'a';
	for(int l = l1; l >= 1; --l) {
		for(int i = 1; i <= l1 - l + 1; ++i) {
			int j = i + l - 1;
			unsigned int temp = Get1(i, j);
			for(int k = 1; k <= l2 - l + 1; ++k) {
				if(Get2(k, k + l - 1) == temp) {
					printf("%d\n", l);
					// for(;;);
					return 0;
				}
			}
		}
	}
	puts("0");
	// for(;;);
	return 0;
}