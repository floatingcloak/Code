#include <time.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#define mod 1000000
#define INF 1000000007
#define Lc (o -> Ch[0])
#define Rc (o -> Ch[1])
#define val (o -> v)
#define pre (o -> p)
#define siz (o -> S)
#define cnt (o -> c)

using namespace std;

const int Maxn = 100010;

struct Treap{
    Treap* Ch[2];
    int p,v,S,c;
};

int n,q,x,Ans,a;bool pet;

int Size(Treap* o){return o?siz:0;}

void Update(Treap* &o){
    siz = cnt;
    if(Lc != NULL)siz += Lc -> S;
    if(Rc != NULL)siz += Rc -> S;
}

void Rotate(Treap* &o,int d){
    Treap* P = o -> Ch[d^1];//P Is A Point That Willing To Be A Root
    o -> Ch[d^1] = P -> Ch[d];//Eh......Rotate Should Give P's Child To O
    P -> Ch[d] = o;//O Is Going Down So It Is P's Child
    Update(o);Update(P);//Points' Size Has Been Changed
    o = P;//Use P To Replace O
}

void Insert(Treap* &o,int x){
    if(o == NULL){//Insert It To Leaves
        o = new Treap();
        Lc = Rc = NULL;
        pre = rand();val = x;cnt = 1;
    }
    else if(val == x)cnt++;
    else {//Rotate And Let x Going Up
         int d = x < val;
         Insert(o -> Ch[d],x);
         if( ( pre ) > o -> Ch[d] -> p)Rotate(o,d^1);
    }
    Update(o);//Mountain O's Size
}

void Delete(Treap* &o,int x){
    if(val == x && cnt >= 2)cnt--;
    else if(val == x){//If Find Out X 
        if(Lc == NULL)o = Rc;
        else if(Rc == NULL)o = Lc;//Link Child To Father Straight
        else {
            int d = (Lc -> p) < (Rc -> p);//Search A Child Tree That Has A Less Pre
            Rotate(o,d);Delete(o -> Ch[d],x);//Rotate It And Delete It In Child Tree
        }
    }
    else Delete(o -> Ch[x < val],x);
    if(o != NULL)Update(o);
}

int Pre(Treap* o,int k){
    int Max = -INF;
    while(o){
        if(val <= k){Max = max(Max,val);o = Lc;}
        else o = Rc;
    }return Max;
}

int Next(Treap* o,int k){
    int Min = INF;
    while(o){
        if(val >= k){Min = min(Min,val);o = Rc;}
        else o = Lc;
    }return Min;
}

int main(){
    // freopen("pet.in","r",stdin);
    // freopen("pet.out","w",stdout);
    // srand(time(NULL));
    scanf("%d",&n);
    Treap* Root = NULL;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&q,&x);
        if(Root == NULL)pet = (q == 0);
        if(!(pet ^ (q == 0)))Insert(Root,x);
        else {
            int r1 = Pre(Root,x),r2 = Next(Root,x);
            // printf(">>>%d %d\n",r1,r2);
            if((r2 == INF) || (r1 != -INF && x - r1 <= r2 - x)){Delete(Root,r1);(Ans += x - r1) %= mod;}
            else {Delete(Root,r2);(Ans += r2 - x) %= mod;}
        }
        // if(q == 0)Insert(Root,x);
        // else {
        //     int r1 = Pre(Root,x),r2 = Next(Root,x);
        //     if(r1 == -INF){(Ans += r2 - x) %= mod;Delete(Root,r2);}
        //     else if(r2 == INF){(Ans += x - r1) %= mod;Delete(Root,r1);}
        //     else {
        //         int a = x - r1,b = r2 - x;
        //         // printf("%d %d",r1,r2);
        //         if(a <= b){(Ans += x - r1) %= mod;Delete(Root,r1);}
        //         else {(Ans += r2 - x) %= mod;Delete(Root,r2);}
        //     }
        // }
    }printf("%d\n",Ans);
    // while(1);
    return 0;
}