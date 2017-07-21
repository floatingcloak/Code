#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1010;

struct node {
	int x, y;	
};

int n, m, x, y, ans, tot, res[1010000];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int vis[Maxn][Maxn];
char map[Maxn][Maxn];

int read(){    
    int x=0; char ch=getchar();    
    while (ch<'0' || ch>'9') ch=getchar();    
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }    
    return x;    
}  

void Bfs(int q, int w) {
	queue <node> Q; vis[q][w] = tot;
	Q.push((node){q, w});
	while(!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop(); ++ans;
		for(int i = 1; i <= 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && map[xx][yy] != map[x][y] && !vis[xx][yy]) {
				vis[xx][yy] = tot;
				Q.push((node){xx, yy});
			}
		}
	}
}

int main() {
//	freopen("test.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) cin >> map[i][j];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(vis[i][j] == 0) {
				++tot;
				ans = 0;
				Bfs(i, j);
				res[tot] = ans;	
			}
		}
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		printf("%d\n", res[vis[x][y]]);
	}
	return 0;
}
