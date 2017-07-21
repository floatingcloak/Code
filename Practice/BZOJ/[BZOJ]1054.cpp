#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
//呃随便宽搜随便hash一下就过掉了。。数据很小
//By sssSSSay 
using namespace std;

queue <int> X,Y;

const int Maxn = 101000;

int dis[1 << 17];
int a[Maxn][5][5],temp[5][5];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,1,-1};
char str[5];

void Copy(int h) {
	for(int i = 1; i <= 4; ++i) {
		for(int j = 1; j <= 4; ++j) temp[i][j] = a[h][i][j];
	}
}

void Push(int t) {
	if(t == 100001)t = 1;
	for(int i = 1; i <= 4; ++i) {
		for(int j = 1; j <= 4; ++j) a[t][i][j] = temp[i][j];
	}
}

void Print(int h) {
	for(int i = 1; i <= 4; ++i) {
		for(int j = 1; j <= 4; ++j)printf("%d",a[h][i][j]);
		printf("\n");
	}
	printf("sssssssssssssssssssssssssssssssss\n");
}

int main() {
	int st = 0,g = 0;
	for(int i = 1; i <= 4; ++i) {
		scanf("%s",str);
		for(int j = 0; j <= 3; ++j) {
			a[1][i][j + 1] = str[j] - '0';
			st = (st << 1) | a[1][i][j + 1];
		}
	}
	for(int i = 1; i <= 4; ++i) {
		scanf("%s",str);
		for(int j = 0; j <= 3; ++j) {
			g = (g << 1) | (str[j] - '0');
		}
	}
	dis[st] = 1;
	int h = 1,t = 1;
	while(h <= t) {
		int now = 0;
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) now = (now << 1) | a[h][i][j];
		}
//		Print(h);
		if(now == g) {
//			printf("!");
			printf("%d\n",dis[now] - 1);
			return 0;
		}
		for(int i = 1;i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				if(a[h][i][j]) {
//					cout<<'!';
					for(int k = 1; k <= 4; ++k) {
						int xx = i + dx[k],yy = j + dy[k];
//						cout<<xx<<' '<<yy<<endl;
						if(xx >= 1 && xx <= 4 && yy >= 1 && yy <= 4 && !a[h][xx][yy]) {
							int ss = 0;
							Copy(h);
							temp[i][j] = 0;
							temp[xx][yy] = 1;
							for(int l = 1; l <= 4; ++l) {
								for(int p = 1; p <= 4; ++p)ss = (ss << 1) | temp[l][p];	
							}
							if(!dis[ss]) {
								dis[ss] = dis[now] + 1;
								t++;
								Push(t);
							}
						}
					}
				}
			}
		}
		h++;
		if(h == 100001)h = 1;
	}
//	printf("%d\n",dis[g]);
	return 0;
}
