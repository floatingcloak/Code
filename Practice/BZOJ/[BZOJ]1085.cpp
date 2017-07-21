#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10;

int T,sx,sy,Judge,Limit;
int dx[9] = {0,1,-1,1,-1,2,-2,2,-2};
int dy[9] = {0,2,2,-2,-2,1,1,-1,-1};
char Goal[6][6] = {
    '0','0','0','0','0','0',
    '0','1','1','1','1','1',
    '0','0','1','1','1','1',
    '0','0','0','*','1','1',
    '0','0','0','0','0','1',
    '0','0','0','0','0','0'
};
char map[Maxn][Maxn];

void Print(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++)printf("%c",map[i][j]);
        printf("\n");
    }printf("\n");
}

int Get(){int res = 0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++)if(map[i][j] != Goal[i][j])res++;
    }return res - 1;
}

void Dfs(int x,int y,int g){int h = Get();
    // Print();
    if(h == -1){Judge = 1;return;}
    if(h + g > Limit)return;
    for(int i=1;i<=8;i++){
        int xx = x + dx[i],yy = y + dy[i];
        if(xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5){
            swap(map[x][y],map[xx][yy]);
            Dfs(xx,yy,g+1);
            swap(map[x][y],map[xx][yy]);
            if(Judge)return;
        }
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                cin>>map[i][j];
                if(map[i][j] == '*'){sx = i;sy = j;}
            }
        }
        for(Limit = 1,Judge = 0;Limit <= 15;Limit++){Dfs(sx,sy,0);if(Judge)break;}
        if(Limit == 16)printf("-1\n");
        else printf("%d\n",Limit);
    }
    return 0;
}