#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 51;

map <string, int> hs;
map <string, int> vis;

int n, b[Maxn], c[Maxn];
string a[Maxn];

string In(int x) {
	char s[5]; int tot = 0;
	while(x) {
		s[++tot] = (char)(x % 10) + 48;
		x /= 10;
	}
	string l = ""; 
	for(int i = tot; i >= 1; --i) l += s[i];
	return l;
}

void Dfs(int w, int x, int sum, string s, string v) {
	if(sum > w) return;
	if(x == n + 1) {
		if(sum != w || vis[v]) return;
		++hs[s]; vis[v] = 1;
		if(hs[s] >= 3) {
			printf("%d\n", w);
			exit(0);
		}
		return;
	}
	for(int i = 0; sum + i * b[x] <= w; ++i) {
		string temp = s, temp2 = "";
		string t1 = v, t2 = "";
		for(int j = 1; j <= i; ++j) temp += a[x], t1 += In(x);
		Dfs(w, x + 1, sum + i * b[x], temp, t1);
		for(int j = 1; j <= i; ++j) temp2 += a[x], t2 += In(x);
		temp2 += s; t2 += v;
		Dfs(w, x + 1, sum + i * b[x], temp2, t2);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i].length();
	}
	for(int len = 1; len <= 28; ++len) Dfs(len, 1, 0, "", "");
	puts("-1");
	return 0;
}
