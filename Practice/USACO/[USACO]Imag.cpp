#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 15;

int n;
char map[Maxn][Maxn], tar[Maxn][Maxn], temp[Maxn][Maxn], nn[Maxn][Maxn];

bool judge1(char map[Maxn][Maxn]) {
	for(int k = 1; k <= n; ++k) {
		for(int l = 1; l <= n; ++l) {
			int kk = l, ll = n - k + 1;
			if(map[k][l] != tar[kk][ll]) return 0;
		}
	}
	return 1;
}

bool judge2(char map[Maxn][Maxn]) {
	for(int k = 1; k <= n; ++k) {
		for(int l = 1; l <= n; ++l) {
			int kk = n - k + 1, ll = n - l + 1;
			if(map[k][l] != tar[kk][ll]) return 0;
		}
	}
	return 1;
}

bool judge3(char map[Maxn][Maxn]) {
	for(int k = 1; k <= n; ++k) {
		for(int l = 1; l <= n; ++l) {
			int kk = n - l + 1, ll = k;
			if(map[k][l] != tar[kk][ll]) return 0;
		}
	}
	return 1;
}

bool judge4(char map[Maxn][Maxn]) {
	for(int k = 1; k <= n; ++k) {
		for(int l = 1; l <= n; ++l) {
			int kk = k, ll = n - l + 1;
			if(map[k][l] != tar[kk][ll]) return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) cin >> map[i][j];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) cin >> tar[i][j];
	}
	for(int i = 1; i <= 7; ++i) {
		if(i == 1) {
			int pd = judge1(map);
			if(pd == 1) {
				puts("1");
				return 0;
			}
		}
		if(i == 2) {
			int pd = judge2(map);
			if(pd == 1) {
				puts("2");
				return 0;
			}
		}
		if(i == 3) {
			int pd = judge3(map);
			if(pd == 1) {
				puts("3");
				return 0;
			}
		}
		if(i == 4) {
			int pd = judge4(map);
			if(pd == 1) {
				puts("4");
				return 0;
			}
		}
		if(i == 5) {
			for(int k = 1; k <= n; ++k) {
				for(int l = 1; l <= n; ++l) {
					int kk = k, ll = n - l + 1;
					nn[kk][ll] = map[k][l];
				}
			}
			if(judge3(nn) || judge2(nn) || judge1(nn)) {
				puts("5");
				return 0;
			}
		}
		if(i == 6) {
			int pd = 0;
			for(int k = 1; k <= n; ++k) {
				for(int l = 1; l <= n; ++l) {
					if(map[k][l] != tar[k][l]) {
						pd = 1;
						break;
					}
				}
				if(pd == 1) break;
			}
			if(pd == 0) {
				puts("6");
				return 0;
			}
		}
		if(i == 7) {
			puts("7");
			return 0;
		}
	}
}
