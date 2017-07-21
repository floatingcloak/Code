#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
//map一下然后Treap，相同分数用时间来进行第二关键字排序，保证节点各不相同。
//By sssSSSay 
#define val (o -> v)
#define siz (o -> s)
#define pre (o -> p)
#define tim (o -> t)
#define lc (o -> ch[0])
#define rc (o -> ch[1])

using namespace std;

const int Maxn = 251000;

map <string,int> has;

struct Treap {
	int v,s,p,t;
	string name;
	Treap* ch[2];
};

Treap* root = NULL;
char str[110];
char nam[Maxn][110];
int n,x,s[Maxn],na[Maxn];

Treap* NewNode(int k,int pr,int t) {
	Treap *o = new Treap();
	val = k;pre = pr;siz = 1;tim = t;
	return o;
}

int Size(Treap* o) {return o ? siz : 0;}

void Update(Treap* &o) {
	siz = 1 + Size(lc) + Size(rc);
}

void rotate(Treap* &o,int d) {
	Treap* x = o -> ch[d ^ 1];
	o -> ch[d ^ 1] = x -> ch[d];
	x -> ch[d] = o;
	Update(o);Update(x);
	o = x;
}

void Insert(Treap* &o,int k,int t) {
	if(o == NULL) {
		o = NewNode(k,rand(),t);
		return;
	}
	int d = k <= val;
	Insert(o -> ch[d],x,t);
	if(pre > o -> ch[d] -> p) rotate(o,d ^ 1);
	Update(o);
}

void Delete(Treap* &o,int k,int t) {
	if(o == NULL) return;
	if(val == k && tim == t) {
		if(!lc) o = rc;
		else if(!rc) o = lc;
		else {
			int d = (lc -> p) < (rc -> p);
			rotate(o,d);Delete(o -> ch[d],k,t);	
		}
	}
	else if(k < val || (val == k && tim < t))Delete(o -> ch[1],k,t);
	else Delete(o -> ch[0],k,t);
	if(o)Update(o);
}

int Rank(Treap* o,int t) {
	if(!o)return 0;
	if(val == na[t] && t == tim) return Size(lc) + 1;
	else if(val > na[t] || (val == na[t] && t > tim))return Rank(rc,t) + Size(lc) + 1;
	else return Rank(lc,t);
}

int Kth(Treap* o,int k) {
	if(!o)return 0;
	if(k == Size(lc) + 1) return tim;
	else if(k <= Size(lc)) return Kth(lc,k);
	else return Kth(rc,k - Size(lc) - 1);
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s",str);
		int len = strlen(str);
		if(str[0] == '+') {
			string temp = "";
			for(int j = 1; j < len; ++j) {
				temp += str[j];
				nam[i][j - 1] = str[j];
			}
			int w = has[temp];
			if(w) Delete(root,na[w],w);
			scanf("%d",&x);
			Insert(root,x,i);
			has[temp] = i;
			na[i] = x;
		}
		else if(str[0] == '?') {
			string cc = "";
			for(int j = 1; j < len; ++j)cc += str[j];
			if(cc[0] >= '0' && cc[0] <= '9') {
				int x = 0;
				for(int j = 0; j < len - 1; ++j) {
					x = x * 10 + (cc[j] - '0');
				}
				int mx = min(x + 9,root -> s);
				
				for(int i = x; i < mx; ++i) {
					cout<<nam[Kth(root,i)]<<' ';	
				}
				printf("%s\n",nam[Kth(root,mx)]);
			}
			else {
				printf("%d\n",Rank(root,has[cc]));
			}
		}
	}
	
	return 0;
}
