#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 310;

int q[Maxn*Maxn][Maxn][2],n,m,Q,map[Maxn][Maxn];

void Add(int col,int p,int d,int x){for(int i=p;i<=n;i+=(i&(-i)))q[col][p][d] += x;}

int Query(int col,int p,int d){int Res = 0;for(int i=p;i>0;i-=(i&(-i))){Res += q[col][p][d];}return Res;}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;scanf("%d",&x);
            Add(x,i,0,1);Add(x,j,1,1);
            map[i][j] = x;
        }
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
        int w,x,y,c,x1,x2,y1,y2;scanf("%d",&w);
        if(w == 1){
            scanf("%d%d%d",&x,&y,&c);
            int col = map[x][y];map[x][y] = c;
            Add(col,x,0,-1);Add(col,y,1,-1);
            Add(c,x,0,1);Add(c,y,1,1);
        }
        else {
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
            int Sum1 = query()
        }
    }
}