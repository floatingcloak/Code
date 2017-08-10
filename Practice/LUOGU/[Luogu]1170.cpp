#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 21;

int n;
string s[Maxn];

bool comp(string a, string b) {return (a + b) > (b + a);}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; ++i) cin >> s[i];
		sort(s + 1, s + n + 1, comp);
		for(int i = 1; i <= n; ++i) cout << s[i];
		cout << endl;
	}
	return 0;
}