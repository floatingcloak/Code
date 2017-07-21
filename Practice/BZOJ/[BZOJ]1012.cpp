#include <cstdio>
#include <cstring>
#include <iostream>
//比较简单的线段树 O(∩_∩)O
//好像有更优的单调栈做法
typedef long long LL;

#define lc  (o * 2)
#define rc  (o * 2 + 1)
#define mid ((l + r) / 2)
#define INF 1000000007

using namespace std;

const int Maxn = 200010;

int m,n;
LL Max[Maxn * 4],t,d,x;

LL M(LL a,LL b){return a > b ? a : b ;}

void Add(int l,int r,int o){
    if(l == r && l == n){Max[o] = x;return;}
    if(n <= mid)Add(l,mid,lc);
    if(n  > mid)Add(mid+1,r,rc);
    Max[o] = M(Max[lc],Max[rc]);
}

LL Query(int l,int r,int o,int a,int b){
    if(l == r)return Max[o];
    if(l == a && r == b)return Max[o];
    else if(b <= mid)return Query(l,mid,lc,a,b);
    else if(a >  mid)return Query(mid+1,r,rc,a,b);
    else return M(Query(l,mid,lc,a,mid),Query(mid+1,r,rc,mid+1,b));
}

int main(){
    // freopen("bzoj_1012.in","r",stdin);
    // freopen("bzoj_1012.out","w",stdout);
    scanf("%d%lld",&m,&d);
    for(int i=1;i<=m;i++){scanf("\n");
        // printf("%d\n",Max[1]);
        // printf("%d\n",n);
        char c;scanf("%c%lld",&c,&x);
        if(c == 'A'){x = (x + t) % d;n++;Add(1,Maxn,1);}
        else {
            LL w = Query(1,Maxn,1,n-x+1,n);t = w;
            printf("%lld\n",w);
        }
    }
    return 0;
}
