#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
 
#define base 233
#define val (o -> v)
#define siz (o -> s)
#define pre (o -> p)
#define cha (o -> c)
#define Lc (o -> ch[0])
#define Rc (o -> ch[1])
 
using namespace std;
 
const int Maxn = 100010;
 
struct Treap {
    unsigned int v;
    int p,s;char c;
    Treap* ch[2];
}*Root;
 
int n,len,m;
char s[Maxn];
unsigned int hs[Maxn];
 
typedef pair<Treap*,Treap*> Troot;
 
int Size(Treap* o){return o?siz:0;}
 
inline void G(int & x) {
	x = 0; int y = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') y = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	x *= y;
}
 
inline Treap* NewNode(char k,int w){
    Treap* o = new Treap();
    val = (unsigned int)(k - 96);pre = w;siz = 1;cha = k;
    return o;
}
 
inline void Update(Treap* o){
    siz = 1 + Size(Lc) + Size(Rc);
    val = (unsigned int)(cha - 96);
    if(!Lc && Rc)val = val + Rc -> v * hs[1];
    if(Lc && !Rc)val = Lc -> v + val * hs[Size(Lc)];
    if(Lc && Rc)val = Lc -> v + val * hs[Size(Lc)] + Rc -> v * hs[Size(Lc) + 1];
}
 
inline Treap* Merge(Treap* A,Treap* B){
    if(A == NULL)return B;
    if(B == NULL)return A;
    if(A -> p < B -> p){A -> ch[1] = Merge(A -> ch[1],B);Update(A);return A;}
    else {B -> ch[0] = Merge(A,B -> ch[0]);Update(B);return B;}
}
 
inline Troot Split(Treap* o,int k){
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
 
inline unsigned int Get(int a,int b){
    Troot t1,t2;t1 = Split(Root,a-1);t2 = Split(t1.second,b);
    Update(t2.first);unsigned Res = t2.first -> v;
    t1.second = Merge(t2.first,t2.second);
    Root = Merge(t1.first,t1.second);return Res;
}
 
inline int Query(int x,int y){
    int l = 1,r = min(len - x + 1,len - y + 1),Ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        unsigned int t1 = Get(x,mid),t2 = Get(y,mid);
        if(t1 == t2)l = mid + 1,Ans = mid;
        else r = mid - 1;
    }return Ans;
}
 
inline void Delete(int k){
    Troot x,y;
    x = Split(Root,k - 1);
    y = Split(x.second,1);
    Root = Merge(x.first,y.second);
}
 
inline void Insert(int w,char k){
    Troot x;Treap* Temp;
    x = Split(Root,w);
    Temp = NewNode(k,rand());
    x.first = Merge(x.first,Temp);
    Root = Merge(x.first,x.second);
}
 
int main(){
	freopen("bzoj_1014.in","r",stdin);
	freopen("bzoj_1014.out","w",stdout);
    scanf("%s",(s + 1));len = strlen(s + 1);hs[0] = 1;
    for(int i=1;i< Maxn;i++)hs[i] = hs[i-1] * base;
    for(int i=1;i<=len;i++){
        Treap *Now = NewNode(s[i],rand());
        Root = Merge(Root,Now);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){char c;int x,y;
        scanf("\n");scanf("%c",&c); 
        if(c == 'Q'){
            G(x);G(y);
            printf("%d\n",Query(x,y));
        }
        else if(c == 'R'){
            G(x);scanf("\n");scanf("%c",&c);
            Delete(x);Insert(x - 1,c);
        }   
        else {
            G(x);scanf("\n");scanf("%c",&c);
            Insert(x,c);len++;
        }
    }
    // while(1);
    return 0;
}
