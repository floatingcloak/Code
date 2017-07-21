#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

map <string, int> hs;

struct node {
	string str, b[15];
	int val, sur, x, chu;
} a[15];

int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].str;
		hs[a[i].str] = i;
	}
	for(int q = 1; q <= n; ++q) {
		int x; string ss; cin >> ss;
		int i = hs[ss];
		scanf("%d%d", &a[i].val, &a[i].x);
		if(a[i].x != 0) a[i].chu = (a[i].val / a[i].x) * a[i].x;
		for(int j = 1; j <= a[i].x; ++j) {
			cin >> a[i].b[j];
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= a[i].x; ++j) {
			int w = hs[a[i].b[j]];
			a[w].sur += a[i].val / a[i].x;
		}
	}
	for(int i = 1; i <= n; ++i) {
		cout << a[i].str << ' ' << a[i].sur - a[i].chu << endl;
	}
	return 0;
}
