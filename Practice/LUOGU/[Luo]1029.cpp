#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a, b;

int Gcd(int a, int b) {return b == 0 ? a : Gcd(b, a % b);}

int main() {
	scanf("%d%d", &a, &b);
	int m = a * b, ans = 0;
	for(int i = a; i <= b; ++i) {
		if(m % i == 0) {
			int j = m / i;
			int k = Gcd(i, j);
			int l = i * j / k;
			if(k == a && l == b) ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
