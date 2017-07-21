#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1000;

struct node {
    int a, b;
} ans[Maxn * 2];

int n, m, tot, a[30];
int c[126000];
bool vis[126000];

void Dfs(int x, int last, int d) {
    // for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    // puts("");
    if(a[1] == 0 && d == 0 && x != 1) return;
    if(x == n + 1) {
        // vis[a[1]][d] = 1;
        ans[++tot].a = a[1]; ans[tot].b = d;
        return;
    }
    
    for(int i = tot; i >= 1; --i) {
        int k = c[i];
        if(x == 1) {
            a[x] = k;
            Dfs(x + 1, k, 0);
            a[x] = 0;
            // if(w) return false;
        }
        else if(x == 2) {
            if(k > last) {
                a[x] = k;
                Dfs(x + 1, k, k - last);
                a[x] = 0;
                // if(w) return false;
            }
        }
        else if(k - last == d) {
            a[x] = k;
            Dfs(x + 1, k, d);
            a[x] = 0;
            // if(w) return false;
        }
    }
    // return false;
}

bool comp(node a, node b) {
    if(a.b == b.b) return a.a < b.a;
    else return a.b < b.b;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j <= m; ++j) {
            int k = i * i + j * j;
            if(!vis[k]) {
                vis[k] = 1;
                c[++tot] = k;
            }
        }
    }
    // printf("%d\n", tot);
    Dfs(1, 0, 0);
    sort(ans + 1, ans + 1 + tot, comp);
    for(int i = 1; i <= tot; ++i) if(ans[i].a != 0 || ans[i].b != 0)printf("%d %d\n", ans[i].a, ans[i].b);
    // system("pause");
    return 0;
}