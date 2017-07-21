#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Maxn = 21;

int n, b[Maxn], tot;
bool c[Maxn], v[Maxn], r[Maxn];

void Dfs(int x) {
    if(x == n + 1) {
        ++tot;
        if(tot <= 3) {
            for(int i = 1; i <= n; ++i) printf("%d ", b[i]);
            puts("");
        }
        
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(!c[i] && !v[x + i] && !r[x - i + n]) {
            c[i] = v[x + i] = r[x - i + n] = 1;
            b[x] = i;
            Dfs(x + 1);
            c[i] = v[x + i] = r[x - i + n] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    Dfs(1);
    printf("%d\n", tot);
    system("pause");
    return 0;
}