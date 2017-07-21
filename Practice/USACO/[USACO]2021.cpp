#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1000010;

int n, ans[Maxn];
int next1[Maxn], pre1[Maxn];

int main() {
//	freopen("test.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) next1[i] = i + 1, pre1[i] = i - 1;
	next1[n] = 1; pre1[1] = n;
	int pd = 0, tot = 1;
	for(int i = 2; tot <= n; i = next1[next1[i]]) {
		ans[i] = tot; ++tot;
		next1[pre1[i]] = next1[i];
		pre1[next1[i]] = pre1[i];
	}
//	cout << tot << endl;
//	cout << '!';
//	cout << n << endl;
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}
