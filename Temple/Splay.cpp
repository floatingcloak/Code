#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 100010
using namespace std;
struct node { int num,mark,f,size;node *ch[2],*fa;node() { num=f=mark=size=0;fa=ch[0]=ch[1]=NULL; } }s[N];
node *null,*head;int n,m,l,r;
struct memory {
    int tot;memory() { tot=0; }
    node *out(int n,int f,node *fa) { node *p=s+tot++;p->num=n,p->f=f,p->fa=fa;return p; }
}pool;
void mark_down(node *now) {
    if(now==NULL) return;
    if(now->mark) {
      swap(now->ch[0],now->ch[1]); now->mark=0;
      if(now->ch[0]!=NULL) now->ch[0]->mark^=1,now->ch[0]->f^=1;
      if(now->ch[1]!=NULL) now->ch[1]->mark^=1,now->ch[1]->f^=1;
    }
    return;
}
void count(node *now) {
    if(now==NULL) return;
    int t=1;
    if(now->ch[0]!=NULL) t+=now->ch[0]->size;
    if(now->ch[1]!=NULL) t+=now->ch[1]->size;
    now->size=t; return;
}
void check(node *now,node *to) {
    node *tr[N];int tot=0;
    while(now!=to) { tr[++tot]=now;now=now->fa; }
    while(tot>0) { mark_down(tr[tot--]); }
}
void rorate(node *now) { 
    node *fa=now->fa;int d=now->f;
    if(now->ch[d^1]!=NULL) now->ch[d^1]->fa=fa,now->ch[d^1]->f=d;fa->ch[d]=now->ch[d^1];
    now->fa=fa->fa;fa->fa->ch[fa->f]=now;now->f=fa->f;fa->f=d^1;
    now->ch[d^1]=fa;fa->fa=now;
    count(fa);count(now); return;
}
void splay(node *now,node *to) {
    if(now==NULL) return;
    check(now,to); while(now->fa!=to) {
      if(now->fa->fa==to) { rorate(now); break; }
      else if(now->f==now->fa->f) rorate(now->fa),rorate(now);
      else rorate(now),rorate(now);
    }if(to==null) head=now;
}
void build(int sum) {
    null=pool.out(0,0,null),head=pool.out(0,0,null);
    sum+=2;head->size=sum; node *now=head;int t=1;sum--;
    while(sum--) {
      now->ch[1]=pool.out(t++,1,now);now=now->ch[1];now->size=n+1;
      if(rand()%2) splay(now,null);
    } return;
}
node *find(node *now,int t,node *to) {
    while(now!=NULL) {
      mark_down(now);int ti;
      if(now->ch[0]==NULL) ti=1;
      else ti=now->ch[0]->size+1;
      if(ti==t) { splay(now,to);return now; }
      else if(ti>t) now=now->ch[0];
      else t-=ti,now=now->ch[1];
    }
}
void rev(int l,int r) {
    if(l>r) swap(l,r);
    node *left=find(head,l,null),*right=find(head,r,head);
    node *now=head->ch[1]->ch[0];
    if(now==NULL) return;else now->mark=now->mark^1;
}
void print(node *now) {
    if(now==NULL) return;mark_down(now);
    print(now->ch[0]);
    if(now->num!=0&&now->num<=n) printf("%d ",now->num);
    print(now->ch[1]);
}
int main() {
    scanf("%d%d",&n,&m);build(n);
    for(int i=1;i<=m;i++)  scanf("%d%d",&l,&r),rev(l,r+2);
    print(head);return 0;
}