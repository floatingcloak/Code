#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int Maxn = 1000100;
 
int n,m,a[Maxn],xx[Maxn],cc[Maxn],Temp,Now,L,R; 
int pos[Maxn],s[Maxn],cnt,tot,b[Maxn],h[Maxn],next1[Maxn];
 
struct node {int l,r,e,ans,num;}q[Maxn];
 
bool comp1(node a,node b){
    if(pos[a.l] == pos[b.l])return a.r < b.r;
    else return a.l < b.l;
}
 
bool comp2(node a,node b){return a.num < b.num;}
 
void Add(int x,int p){
    s[a[x]] += p;
    if(s[a[x]] == 0)Temp--;
    if(s[a[x]] == 1 && p == 1)Temp++;
}
 
void Change(int f,int p){
    int x = xx[f];int v = cc[f];
    if(x >= L && x <= R){
        Add(x,-1);
        if(p == -1){
            if(next1[f] == 0){
                a[x] = b[x];
            }
            else {
                a[x] = cc[next1[f]];
            }
        }
        else {a[x] = v;}
        Add(x,1);
    }
    else {
        if(p == -1){
            if(next1[f] == 0){
                a[x] = b[x];
            }
            else {
                a[x] = cc[next1[f]];
            }
        }   
        else {a[x] = v;}
    }
}
 
void Solve(){
    L = 1,R = 0;Temp = 0,Now = 0;
    for(int i=1;i<=cnt;i++){
        while(Now < q[i].e)Change(++Now,1);
        while(Now > q[i].e)Change(Now--,-1);
        while(R < q[i].r)Add(++R,1);
        while(L > q[i].l)Add(--L,1);
        while(R > q[i].r)Add(R--,-1);
        while(L < q[i].l)Add(L++,-1);
        q[i].ans = Temp;
    }
}
 
int main(){
    scanf("%d%d",&n,&m);int block = (int)sqrt((double)n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);pos[i] = (i - 1) / block + 1;}
    for(int i=1;i<=n;i++)b[i] = a[i];
    for(int i=1;i<=m;i++){
        int x,y;char ch;cin>>ch;
        if(ch == 'Q'){cnt++;
            scanf("%d%d",&q[cnt].l,&q[cnt].r);
            q[cnt].e = tot;q[cnt].num = i;
        }
        else {
            scanf("%d%d",&x,&y);
            next1[++tot] = h[x];h[x] = tot;
            xx[tot] = x;cc[tot] = y;
        }
    }
    sort(q + 1,q + cnt + 1,comp1);
    Solve();
    sort(q + 1,q + cnt + 1,comp2);
    for(int i=1;i<=cnt;i++)printf("%d\n",q[i].ans);
    return 0;
}