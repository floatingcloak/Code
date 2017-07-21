#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 5100;

int tot, n, m, ch[Maxn][Maxn], f[Maxn], end[Maxn];
char s[Maxn];

void Insert(int len) {
	int now = 0;
	for(int i = 1; i <= len; ++i) {
		int p = s[i] - 'a';
//		cout << now << endl;
		if(ch[now][p] == -1) ch[now][p] = ++tot;
		now = ch[now][p];
	}
//	cout << now << endl;
	end[now] = 1;
}

bool Search(int l, int r) {
	int now = 0;
	for(int i = l; i <= r; ++i) {
		int p = s[i] - 'a';
//		cout << now << endl;
		if(ch[now][p] == -1) return 0;
		else now = ch[now][p];
	}
//	cout <<now << endl;
	if(end[now]) return 1;
}

int main() {
	memset(ch, -1, sizeof(ch));
//	scanf("%d%d", &n, &m);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
//		memset(s, 0, sizeof(s));
		scanf("%s", (s + 1)); int len = strlen(s + 1);
		Insert(len);
	}
	int s1 = 0;
	while(1) {
//			scanf("\n");
		cin >> (s + 1);
		int len = strlen(s + 1);
		cout << Search(1, len) << ' ' << s << endl;
	}
//	for(int i = 1; i <= m; ++i) {
//		memset(f, 0, sizeof(f));
//		cin >> (s + 1); int len = strlen(s + 1);
//		f[0] = 1;
//		for(int j = 0; j <= len; ++j) {
//			if(f[j] == 1) {
//				for(int k = 1; j + k <= len; ++k) {
//					int l = j + 1, r = j + k;
//					if(Search(l, r)) f[r] = 1;
//				}
//			}
//		}
//		int ans = 0;
//		for(int j = 0; j <= len; ++j) if(f[j] == 1) ans = j;
//		printf("%d\n", ans);
//	}
	return 0;
}
