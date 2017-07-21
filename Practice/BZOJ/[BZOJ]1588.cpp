#include <time.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

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

int root = 0,n,x,k,q,a[Maxn];

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

int Kth(Treap* o,int k){//The Same As Above
    if(o == NULL || k <= 0 || k > siz)return 0;
    int S = (Rc == NULL) ? 0 : (Rc -> S);
    if(k >= S + 1 && k <= S + cnt)return val;
    else if(k <= S)return Kth(Rc,k);
    else return Kth(Lc,k - S - cnt);
}

int Rank(Treap* o,int k){
    if(o == NULL)return 0;
    if(val == k)return Size(Rc) + 1;
    else if(k > val)return Rank(Lc,k) + Size(Rc) + cnt;
    else return Rank(Rc,k);
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
    srand(time(NULL));
    scanf("%d",&n);
    Treap* Root = NULL;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        int 
        Insert(Root,x);
    }
    return 0;
}