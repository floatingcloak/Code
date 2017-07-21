#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

// const int Maxn = 101000000;

int res[84] = {0,2,3,5,7,23,29,31,37,53,59,71,73,79,233,239,293,311,313,317,373,379,593,599,719,733,739,797,2333,2339,2393,2399,2939,3119,3137,3733,3739,3793,3797,5939,7193,7331,7333,7393,23333,23339,23399,23993,29399,31193,31379,37337,37339,37397,59393,59399,71933,73331,73939,233993,239933,293999,373379,373393,593933,593993,719333,739391,739393,739397,739399,2339933,2399333,2939999,3733799,5939333,7393913,7393931,7393933,23399339,29399999,37337999,59393339,73939133};
int l[9] = {0,1,5,14,28,44,59,71,79};
int r[9] = {0,4,13,27,43,58,70,78,83};
int n;
// int judge[Maxn], prime[Maxn], tot, tot1, tot2, tot3, tot4;
// int tot5, tot6, tot7, tot8, l[10], r[10];
// int ans[20100 * 9];

// int Judge(int x) {
//     while(x) {
//         if(judge[x]) return false;
//         x /= 10;
//     }
//     return true;
// }

int main() {
    // freopen("[USACO]1218.txt", "w", stdout);
    // judge[1] = 1; judge[0] = 1;
    // for(int i = 2; i <= 100000000; ++i) {
    //     if(!judge[i]) prime[++tot] = i;
    //     for(int j = 1; j <= tot && prime[j] * i <= 100000000; ++j) {
    //         judge[i * prime[j]] = 1;
    //         if(i % prime[j] == 0) break;
    //     }
    // }
    // int tot = 0;
    // l[1] = 1;
    // for(int i = 1; i <= 9; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[1] = tot;
    // l[2] = tot + 1;
    // for(int i = 10; i <= 99; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[2] = tot;
    // l[3] = tot + 1;
    // for(int i = 100; i <= 999; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[3] = tot;
    // l[4] = tot + 1;
    // for(int i = 1000; i <= 9999; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[4] = tot;
    // l[5] = tot + 1;
    // for(int i = 10000; i <= 99999; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[5] = tot;
    // l[6] = tot + 1;
    // for(int i = 100000; i <= 999999; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[6] = tot;
    // l[7] = tot + 1;
    // for(int i = 1000000; i <= 9999999; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[7] = tot;
    // l[8] = tot + 1;
    // for(int i = 10000000; i <= 99999999; ++i) {
    //     if(!judge[i] && Judge(i)) ans[++tot] = i;
    // }
    // r[8] = tot;
    // printf("%d\n", tot);
    // for(int i = 1; i <= tot; ++i) printf("%d,", ans[i]);
    // puts("");
    // for(int i = 1; i <= 8; ++i) printf("%d,", l[i]);
    // puts("");
    // for(int i = 1; i <= 8; ++i) printf("%d,", r[i]);
    // puts("");
    scanf("%d", &n);
    for(int i = l[n]; i <= r[n]; ++i) printf("%d\n", res[i]);
    system("pause");
    return 0;
}