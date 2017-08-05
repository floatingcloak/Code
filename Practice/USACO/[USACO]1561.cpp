#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 100001 * 2;

int n, tot, a[Maxn];

int main() {
	scanf("%d", &n);
	int l = 100001, r = 100000;
	while(n--) {
		char ch; cin >> ch;
		if(ch == 'A') {
			char c; cin >> c;
			if(c == 'L') {
				++tot; a[--l] = tot;
			}
			else {
				++tot; a[++r] = tot;
			}
		}
		else {
			char c; cin >> c;
			if(c == 'L') {
				int x; scanf("%d", &x);
				for(int i = 1; i <= x; ++i) ++l;
			}
			else {
				int x; scanf("%d", &x);
				// cout << "@@" << x << endl;
				while(x--) --r;
			}
		}
		// cout << l << ' ' << r << endl;
	}
	for(int i = l; i <= r; ++i) if(a[i] != 0) cout << a[i] << endl;
	// cin >> n;
	return 0;
}