#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100000007
#define val (o -> v)
#define siz (o -> s)
#define pre (o -> p)
#define Lc (o -> ch[0])
#define Rc (o -> ch[1])

const int Maxn = 100010;

struct Treap {
    int v,s,p;
    Treap* ch[2];
}*Root = NULL;

int n,q,x,top,a[Maxn];

typedef pair<Treap*,Treap*> Troot;

int Size(Treap* o){return (o)?(siz):0;}

void Update(Treap* o){siz = 1 + Size(Lc) + Size(Rc);}

Treap* NewNode(int k,int w){
    Treap* o = new Treap();
    val = k;pre = w;siz = 1;
    return o;
}

Treap* Merge(Treap* A,Treap* B){
    if(A == NULL)return B;
    if(B == NULL)return A;
    if(A -> p < B -> p){A -> ch[1] = Merge(A -> ch[1],B);Update(A);return A;}
    else {B -> ch[0] = Merge(A,B -> ch[0]);Update(B);return B;}
}

Troot Split(Treap* o,int k){
    Troot Temp(NULL,NULL);
    if(o == NULL)return Temp;
    int LcSize = Size(Lc),RcSize = Size(Rc);
    if(k <= LcSize){
        Temp = Split(Lc,k);Lc = Temp.second;
        Update(o);Temp.second = o;
    }
    else {
        Temp = Split(Rc,k - LcSize - 1);
        Rc = Temp.first;Update(o);Temp.first = o;
    }return Temp;
}

int Kth(Treap* o,int k){
    if(k == Size(Lc) + 1)return val;
    return k <= Size(Lc) ? Kth(Lc,k) : Kth(Rc,k - Size(Lc) - 1);
}

int Rank(Treap* o,int k){
    if(o == NULL)return 0;
    else if(k > val)return Rank(Rc,k) + Size(Lc) + 1;
    else return Rank(Lc,k);
}

int Pre(Treap* o,int k){
    int Max = -INF;
    while(o){
        if(val <= k){Max = max(Max,val);o = Rc;}
        else o = Lc;
    }return Max;
}

int Next(Treap* o,int k){
    int Min = INF;
    while(o){
        if(val >= k){Min = min(Min,val);o = Lc;}
        else o = Rc;
    }return Min;
}

void Insert(int k){
    int w = Rank(Root,k) + 1;
    Troot x = Split(Root,w-1);
    Treap* Now = NewNode(k,rand());
    Root = Merge(Merge(x.first,Now),x.second);
}

void Delete(int k){
    int w = Rank(Root,k) + 1;
    Troot x = Split(Root,w-1);
    Troot y = Split(x.second,1);
    Root = Merge(x.first,y.second);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&q,&x);
        if(q == 1)Insert(x);
        else if(q == 2)Delete(x);
        else if(q == 3)printf("%d\n",Rank(Root,x) + 1);
        else if(q == 4)printf("%d\n",Kth(Root,x));
        else if(q == 5)printf("%d\n",Pre(Root,x-1));
        else if(q == 6)printf("%d\n",Next(Root,x+1));
    }
    return 0;
}