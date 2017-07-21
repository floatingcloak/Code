#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 301000, M = 501;

map <string, int> vis;

string str[Maxn];
int n, m, p, q;
char ss[Maxn * M];

inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
	freopen("answer.in", "r", stdin);
	freopen("answer.out", "w", stdout);
	n = read(); m = read(); p = read(); q = read();
	fread(ss, m + 1, n, stdin);
	int now = 0, s = 0;
	for(int i = 1; i <= n; ++i) {
		string temp = "";
		for(int j = 0; j < m; ++j) temp += ss[now++];
		str[i] = temp; ++now;
	}
	if(p == 0 && q == 0) {
		for(int i = 1; i <= n; ++i) vis[str[i]] = 1;
		string now = "", unow = "";
		for(int i = 1; i <= m; ++i) now += 'N', unow += 'Y';
		while(true) {
			if(!vis[now] && !vis[unow]) {
				cout << now << endl;
				return 0;
			}
			else {
				int pos = m - 1;
				while(now[pos] == 'Y') {
					now[pos] = 'N';
					unow[pos--] = 'Y';
				}
				now[pos] = 'Y';
				unow[pos] = 'N';
			}
		}
		return 0;	
	}
	if(p == 0) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(str[i][j - 1] == 'Y') str[i][j - 1] = 'N';
				else str[i][j - 1] = 'Y';
			}
			++vis[str[i]];
		}
		sort(str + 1, str + n + 1);
		for(int i = 1; i <= n; ++i) {
			if(vis[str[i]] == q) {
				cout << str[i] << endl;
				return 0;
			}
		}
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i) ++vis[str[i]];
	
	sort(str + 1, str + n + 1);
	
	for(int i = 1; i <= n; ++i) {
		if(vis[str[i]] == p) {
			string temp = "";
			for(int j = 1; j <= m; ++j) {
				temp += (str[i][j - 1] == 'Y') ? 'N' : 'Y';
			}
			if(vis[temp] == q) {
				for(int j = 1; j <= m; ++j) putchar(str[i][j - 1]);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
