#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define siz (o -> s)
#define val (o -> v)
#define pre (o -> p)
#define lc (o -> ch[0])
#define rc (o -> ch[1])

using namespace std;

int n,Min,Add,Ans;

struct Treap {
    int v,s,p;
    Treap* ch[2];
}*Root = NULL;

typedef pair<Treap*,Treap*> Troot;

int Size(Treap* o){return o?siz:0;}

void Update(Treap* o){siz = 1 + Size(lc) + Size(rc);}

Treap* NewNode(int k,int p){
    Treap* o = new Treap();
    siz = 1;pre = p;val = k;
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
    int LcSize = Size(lc),RcSize = Size(rc);
    if(k <= LcSize){
        Temp = Split(lc,k);lc = Temp.second;
        Update(o);Temp.second = o;
    }
    else {
        Temp = Split(rc,k - LcSize - 1);
        rc = Temp.first;Update(o);Temp.first = o;
    }return Temp;
}

int Kth(Treap* o,int k){
    if(o == NULL)return -1;
    if(k == Size(rc) + 1)return val;
    return k <= Size(rc) ? Kth(rc,k) : Kth(lc,k - Size(rc) - 1);
}

int Rank(Treap* o,int k){
    if(o == NULL)return 0;
    else if(k > val)return Rank(rc,k) + Size(lc) + 1;
    else return Rank(lc,k); 
}

void Insert(int k){
    int w = Rank(Root,k) + 1;
    Troot x = Split(Root,w - 1);
    Treap* Now = NewNode(k,rand());
    Root = Merge(Merge(x.first,Now),x.second);
}

void Delete(int k){
    int w = Rank(Root,k) + 1;
    Troot x = Split(Root,w - 1);
    Troot y = Split(x.second,1);
    Root = Merge(x.first,y.second);
}

int Solve(Treap* &o,int k){int t;
    if(o == NULL)return 0;
    if(val < k){
        t = 1 + Size(lc);o = rc;
        return t + Solve(o,k);
    }
    else {
        t = Solve(lc,k);siz -= t;
        return t;
    }
}

int main(){
    freopen("cashier.in","r",stdin);
    freopen("cashier.out","w",stdout);
    scanf("%d%d",&n,&Min);
    for(int i = 1; i <= n; i++){
        char c;scanf("\n%c",&c);
        int x;scanf("%d",&x);
        // if(Root != NULL && Root -> ch[0] != NULL)printf("%d %d\n",Root -> v,Root -> ch[0] -> v);
        if(c == 'I' && x >= Min)Insert(x - Add);
        if(c == 'A')Add += x;
        if(c == 'S'){
            Add -= x;
            Ans += Solve(Root,Min - Add);
        }
        if(c == 'F'){
            if(!Root || x > Root -> s)printf("-1\n");
            else printf("%d\n",Kth(Root,x) + Add);
        }
    }
    printf("%d\n",Ans);
    // while(1);
    return 0;
}