#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 101010;

int n, a[Maxn], opt, ans = 1;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if(a[1] <= a[2]) opt = 1;
	for(int i = 1; i <= n; ++i) {
		if(opt == 0 && i == n) {++ans; break;}
		if(opt == 1 && a[i] > a[i + 1]) {opt = 0; ++ans; continue;}
		if(opt == 0 && a[i] < a[i + 1]) {opt = 1; ++ans; continue;}
	}
	cout << ans << endl;
	// for(;;);
	return 0;
}