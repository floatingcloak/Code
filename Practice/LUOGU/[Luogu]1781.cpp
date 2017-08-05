#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string s[50];
int n, res;

int main() {
	scanf("%d", &n); string ans = ""; int l = 0;
	for(int i = 1; i <= n; ++i) cin >> s[i];
	for(int i = 1; i <= n; ++i) {
		int ll = s[i].length();
		if(ll > l || (ll == l && s[i] > ans)) {
			ans = s[i]; l = ll; res = i;
		}
	}
	printf("%d\n", res);
	cout << ans << endl;
	for(;;);
	return 0;
}