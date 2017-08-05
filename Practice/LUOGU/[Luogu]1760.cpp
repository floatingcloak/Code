#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10101;

int ans[Maxn], base[Maxn], temp[Maxn];
int l1, l2, n;

void MulAns() {
	memset(temp, 0, sizeof temp); int t;
	for(int i = 1; i <= l1; ++i) {
		t = i + l2 - 1; int x = 0;
		for(int j = 1; j <= l2; ++j) {
			temp[i + j - 1] += ans[i] * base[j] + x;
			x = temp[i + j - 1] / 10;
			temp[i + j - 1] %= 10;
		}
		while(x) {temp[++t] += x % 10; x /= 10;}
	}
	memcpy(ans, temp, sizeof temp);
	l1 = t;
}

void MulBase() {
	memset(temp, 0, sizeof temp); int t;
	for(int i = 1; i <= l2; ++i) {
		t = i + l2 - 1; int x = 0;
		for(int j = 1; j <= l2; ++j) {
			temp[i + j - 1] += base[i] * base[j] + x;
			x = temp[i + j - 1] / 10;
			temp[i + j - 1] %= 10;
		}
		while(x) {temp[++t] += x % 10; x /= 10;}
	}
	memcpy(base, temp, sizeof temp);
	l2 = t;
}

int main() {
	scanf("%d", &n);
	ans[1] = 1; l1 = 1;
	base[1] = 2; l2 = 1;
	while(n) {
		if(n & 1) MulAns();
		MulBase();
		n >>= 1;
	}	
	int now = 1; ans[now]--;
	while(ans[now] < 0) {
		ans[now] += 10;
		ans[++now]--;
	}
	// cout << l1 << endl;
	for(int i = l1; i >= 1; --i) printf("%d", ans[i]);
	puts("");
	// for(;;);
	return 0;
}