#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 401000;

int n, a[Maxn], tot, s[Maxn], b[Maxn];
int ch[Maxn * 40][2], lmax[Maxn], rmax[Maxn];

void Insert(int x) {
	int b[34] = {0}, d = 0;
	while(x) {
		b[++d] = x & 1;
		x >>= 1;
	}
	int now = 0;
	for(int i = 31; i >= 1; --i) {
		int p = b[i];
		if(!ch[now][p]) ch[now][p] = ++tot;
		now = ch[now][p];
	}
}

int Search(int x) {
	int b[34] = {0}, ans = 0, d = 0;
	while(x) {
		b[++d] = x & 1;
		x >>= 1;
	}
	int now = 0;
	for(int i = 31; i >= 1; --i) b[i] = !b[i];
	for(int i = 31; i >= 1; --i) {
		int p = b[i];
		if(ch[now][p]) {
			ans += (1 << (i - 1));
			now = ch[now][p];
		}
		else if(ch[now][p ^ 1]) now = ch[now][p ^ 1];
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &s[i]);
		a[i] = a[i - 1] ^ s[i];
	}
	for(int i = n; i >= 1; --i) b[i] = b[i + 1] ^ s[i];
	Insert(0);
	for(int i = 1; i <= n; ++i) {
		Insert(a[i]);
		lmax[i] = max(lmax[i - 1], Search(a[i]));
	}
	memset(ch, 0, sizeof(ch));
	Insert(0);
	for(int i = n; i >= 1; --i) {
		Insert(b[i]);
		rmax[i] = max(rmax[i + 1], Search(b[i]));
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = max(ans, lmax[i] + rmax[i + 1]);
	}
	printf("%d\n", ans);
	return 0;
}
