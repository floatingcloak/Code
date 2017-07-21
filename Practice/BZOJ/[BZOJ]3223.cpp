
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define val (o -> v)
#define siz (o -> s)
#define pre (o -> p)
#define tag (o -> t)
#define Lc (o -> ch[0])
#define Rc (o -> ch[1])

using namespace std;

const int Maxn = 101000;

struct Treap {
    int v,p,s,t;
    Treap* ch[2];
};

Treap* Root;
int n,m;

typedef pair<Treap*,Treap*> Troot;

int S(Treap* o){if(o == NULL){return 0;}return siz;}

Treap* NewNode(int k,int w){Treap* o = new Treap();val = k;pre = w;siz = 1;tag = 0;return o;}

void PushDown(Treap* o){
    if(o == NULL)return;
    if(!tag)return;
    if(Lc)Lc -> t ^= 1;
    if(Rc)Rc -> t ^= 1;
    tag = 0;swap(Lc,Rc);
}

void Update(Treap* o){siz = 1 + S(Lc) + S(Rc);}

Treap* Merge(Treap* A,Treap* B){
    if(A == NULL)return B;
    if(B == NULL)return A;
    PushDown(A);PushDown(B);
    if(A -> p < B -> p){A -> ch[1] = Merge(A -> ch[1],B);Update(A);return A;}
    else {B -> ch[0] = Merge(A,B -> ch[0]);Update(B);return B;}
}

Troot Split(Treap* o,int k){
    Troot Temp(NULL,NULL);
    if(o == NULL)return Temp;
    PushDown(o);int LcSize = S(Lc),RcSize = S(Rc);
    if(k <= LcSize){
        Temp = Split(Lc,k);Lc = Temp.second;
        Update(o);Temp.second = o;
    }
    else {
        Temp = Split(Rc,k - LcSize - 1);
        Rc = Temp.first;Update(o);Temp.first = o;
    }return Temp;
}

void Insert(Treap* &o,int k){
    Treap* Now = NewNode(k,rand());
    PushDown(o);o = Merge(o,Now);
}

void Turn(int L,int R){
    Troot Temp1 = Split(Root,R);
    Troot Temp2 = Split(Temp1.first,L-1);
    if(Temp2.second != NULL)Temp2.second -> t ^= 1;
    Root = NULL;
    Root = Merge(Temp2.first,Temp2.second);
    Root = Merge(Root,Temp1.second);
}

void Ans(Treap* o){
    if(tag != 0)PushDown(o);
    if(Lc != NULL)Ans(Lc);
    printf("%d ",val);
    if(Rc != NULL)Ans(Rc);
}

int main(){
    freopen("phs.in","r",stdin);
    freopen("phs.out","w",stdout);
    srand(time(NULL));
    scanf("%d%d",&n,&m);Root = NULL;
    for(int i=1;i<=n;i++)Insert(Root,i);
    for(int i=1;i<=m;i++){
        int L,R;scanf("%d%d",&L,&R);
        Turn(L,R);
    }
    Ans(Root);
    return 0;
}