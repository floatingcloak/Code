#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <iostream>
 
#define val (o -> v)
#define siz (o -> s)
#define pre (o -> p)
#define lc (o -> ch[0])
#define rc (o -> ch[1])
 
#define INF 1000000007
 
using namespace std;
 
const int Maxn = 600001;
 
priority_queue < int,vector<int>,greater<int> > Q;
multiset <int> w;
map <int,int> hs;
 
struct Treap {
    int v,p,s;
    Treap* ch[2];
}*root = NULL;

inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
} 

int n,m,x,y,a[Maxn],b[Maxn],ans2 = INF,judge,ans = INF;
char s[20];
 
inline int Size(Treap *o) {return o ? siz : 0;}
 
inline void Update(Treap* &o) {
    siz = 1 + Size(lc) + Size(rc);
}
 
inline void Rotate(Treap* &o,int d) {
    Treap* x = o -> ch[d ^ 1];
    o -> ch[d ^ 1] = x -> ch[d];
    x -> ch[d] = o;
    Update(o);Update(x);
    o = x;
}
 
inline void Insert(Treap* &o,int k) {
    if(!o) {
        o = new Treap();
        val = k; pre = rand(); siz = 1;
        return;
    }
    if(val == k) judge = 1;
    int d = val < k;
    Insert(o -> ch[d],k);
    if(pre > o -> ch[d] -> p)Rotate(o,d ^ 1);
    if(o)Update(o);
}
 
inline int Pre(int k) {
    Treap* o = root;
    int temp = -INF;
    while(o) {
        if(val > k) o = lc;
        else {
            temp = max(temp , val);
            o = rc; 
        }
    }
    return temp;
}
 
inline int Next(int k) {
    Treap* o = root;
    int temp = INF;
    while(o) {
        if(val < k) o = rc;
        else {
            temp = min(temp , val);
            o = lc; 
        }
    }
    return temp;
}

inline void insert(int x) {
    hs[x]++;
    if(hs[x] == 1) {
        w.insert(x);
    }
}

inline void Delete(int x) {
	hs[x]--;
	if(hs[x] == 0) {
		w.erase(x);
	}	
}

int main() {
//	freopen("form.in","r",stdin);
//	freopen("form.out","w",stdout);
    n = read();m = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        b[i] = a[i];
        Insert(root,a[i]);
		if(!judge) {
		    int k1 = Pre(a[i] - 1);
		    int k2 = Next(a[i] + 1);
		    if(k1 != -INF) ans = min(ans , abs(k1 - a[i]));
		    if(k2 != INF) ans = min(ans , abs(k2 - a[i]));
		}
    }
    for(int i = 2; i <= n; ++i) insert(abs(a[i] - a[i - 1]));
    int may = INF;
    for(int i = 1; i <= m; ++i) {
        scanf("%s",s);
        if(s[0] == 'M' && s[4] == 'S') {
            if(judge) printf("0\n");
            else {
				printf("%d\n",ans);
			}
        }
        else if(s[0] == 'M' && s[4] == 'G') {printf("%d\n",min(may,*w.begin()));}
        else {
            x = read();
            y = read();
			Insert(root,y);
			if(!judge) {
            	int k1 = Pre(y - 1);
            	int k2 = Next(y + 1);
            	if(k1 != -INF) ans = min(ans , abs(k1 - y));
            	if(k2 != INF) ans = min(ans , abs(k2 - y));
            }
            if(abs(b[x] - y) < may)may = abs(b[x] - y);
            if(x != n) {
				if(abs(a[x + 1] - y) < may)insert(abs(a[x + 1] - y));
                if(abs(a[x + 1] - b[x]) < may)Delete(abs(a[x + 1] - b[x]));
            }
            b[x] = y;
        }
    }
    return 0;
}
