#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

#define MAXN 30333
#define MAXM 555

typedef unsigned long long LL;

int n, m, p, q, ans;
int js[MAXN];
char s[MAXN];
std::map <std::string, int> mp;

struct data {
	std::string s;

	bool operator < (const data &xx) const {
		return s < xx.s;
	}

	bool operator == (const data &xx) const {
		for(int i = 0; i < m; i++) if(s[i] != xx.s[i]) return 0;
		return 1;
	}

}ha[MAXN];



int main() {
     freopen("answer.in", "r", stdin);
     freopen("answer.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for(int i = 1; i <= n; i++) scanf("%s", s), ha[i].s = s;
	std::sort(ha + 1, ha + 1 + n);
	// printf("dsfdsfdsaasddasfasdfas\n");
	// for(int i = 1; i <= n; i++) printf("%s\n", ha[i].s);
	int tmp = n;
	n = 1;
	js[1] = 1;
	for(int i = 2; i <= tmp; i++) {
		if(ha[i] == ha[i - 1]) js[n]++;
		else js[++n] = 1, ha[n] = ha[i];
	}

	for(int i = 1; i <= n; i++) mp[ha[i].s] = i;
	for(int i = 1; i <= n; i++) {
		if(js[i] >= p) {
			std::string tmp;
			for(int j = 0; j < m; j++) if(ha[i].s[j] == 'Y') tmp += 'N'; else tmp += 'Y';
			if(js[mp[tmp]] >= q) {
				std::cout<<ha[i].s<<std::endl;
				return 0;
			}
		}
	}

	// if(!pd1 || !pd2)
	printf("-1\n");
	// else printf("%s\n", ha[ans].s);

//	for(int i = 1; i <= m; i++) {
//		if((Y[i] < p && N[i] < p) || (Y[i] < q && N[i] < q)) {
//			printf("-1\n");
//			return 0;
//		}
//	}
}
/*
2 2 2 0
YY
YY
*/
