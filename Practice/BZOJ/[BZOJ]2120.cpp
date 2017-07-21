#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;



int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){int x,y;
        char ch;scanf("\n%c",&ch);
        if(ch == R){
            scanf("%d%d",&x,&y);
            w[++tot].x = x;w[tot].c = y;
        }
        else {cnt++;
            scanf("%d%d",&q[cnt].l,&q[cnt].r);
            q[cnt].e = tot;q[cnt].num = cnt;
        }
    }
    sort(q + 1,q + cnt + 1,comp1);
    Solve();
    sort(q + 1,q + cnt + 1,comp2);
    for(int i=1;i<=cnt;i++)printf("%d\n",q[i].ans);
    return 0;
}