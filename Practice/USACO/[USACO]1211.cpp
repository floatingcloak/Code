#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 110;

int n, ans, a[Maxn], b[Maxn];
bool vis[Maxn];

bool Judge(int x, int p) {
    int w = 0, c[15] = {0};
    while(x) {
        c[++w] = x % 10;
        // printf("%d %d \n", c[w], vis[c[w]]);
        if(!vis[c[w]]) return false;
        x /= 10;
    }
    // printf("@@ %d\n", w);
    if(p == 1) { if(w != 3) return false; }
    else if(w != 4) return false;
    return true;
}

void Dfs1(int x) {
    if(x == 6) {
        // for(int i = 1; i <= 5; ++i) printf("%d ", b[i]);
        
        int s1 = 100, s2 = 0, s3 = 0;
        for(int i = 1; i <= 3; ++i) {
            s2 += s1 * b[i];
            s1 /= 10;
        }
        s1 = 10;
        for(int i = 4; i <= 5; ++i) {
            s3 += s1 * b[i];
            s1 /= 10;
        }
        // printf("!");
        int e = s2 * b[4], f = s2 * b[5], g = s3 * s2;
        // puts("");
        if(Judge(e, 1) && Judge(f, 1) && Judge(g, 0)) ++ans;
        return;
    }
    for(int i = 1; i <= n; ++i) {
        b[x] = a[i];
        Dfs1(x + 1); 
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        vis[a[i]] = 1;
    }
    Dfs1(1);
    // printf("%d\n", Judge(246, 1));
    printf("%d\n", ans);
    // while(1);
    return 0;
}