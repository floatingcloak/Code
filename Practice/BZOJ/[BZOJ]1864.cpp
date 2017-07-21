#include <cstdio>
#include <cstring>
#include <iostream>
 
using namespace std;
 
const int Maxn = 400010;
 
struct node {int to,next;}E[Maxn];
 
int qu[Maxn],l[Maxn],r[Maxn],res,tot,num,len,t = 1,f[Maxn][3];
char s[Maxn];
 
void Dfs(int x){
    char ch = getchar();
    if(ch == '0')return;
    l[x] = ++t;Dfs(t);
    if(ch == '2'){r[x] = ++t;Dfs(t);}
}
 
void Dp1(int x){
    if(x == 0)return;
    Dp1(l[x]);Dp1(r[x]);
    f[x][1] = f[l[x]][0] + f[r[x]][0] + 1;
    f[x][0] = max(f[l[x]][1] + f[r[x]][0],f[r[x]][1] + f[l[x]][0]);
}
 
void Dp2(int x){
    if(x == 0)return;
    Dp2(l[x]);Dp2(r[x]);
    f[x][1] = f[l[x]][0] + f[r[x]][0] + 1;
    f[x][0] = min(f[l[x]][1] + f[r[x]][0],f[r[x]][1] + f[l[x]][0]);
}
 
int main(){
    freopen("trot.in","r",stdin);
    freopen("trot.out","w",stdout);
    Dfs(1);Dp1(1);
    printf("%d ",max(f[1][1],f[1][0]));
    for(int i=1;i<=t;i++){f[i][0] = 0;f[i][1] = 0;}
    Dp2(1);
    printf("%d\n",min(f[1][1],f[1][0]));
    return 0;
}