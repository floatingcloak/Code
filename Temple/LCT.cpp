#include <cstdio>
const int N=100010;
int n,m;

struct nod{
    int  num;
    bool rev;
    nod *pp,*pr,*ch[2];
}*NIL,pool[N];

struct LCT {
    nod *pt[N];

    LCT() {
        NIL=&pool[0];
        for(int i=1;i<=n;i++){
            pt[i]=&pool[i];
            pt[i]->num=i;pt[i]->pp=pt[i]->pr=pt[i]->ch[0]=pt[i]->ch[1]=NIL;
        }
    }

    void clear(nod *p){
        if((!p->rev)||p==NIL) return ;
        nod *t=p->ch[0];p->ch[0]=p->ch[1];p->ch[1]=t;
        p->rev=0;p->ch[0]->rev^=1;p->ch[1]->rev^=1;
    }
    void rotate(nod *x,bool t){
        nod *y=x->pr,*z=y->pr,*b=x->ch[t^1];
        b->pr=y;y->pr=x;x->pr=z;y->ch[t]=b;x->ch[t^1]=y;
        if(z->ch[0]==y) z->ch[0]=x;
        if(z->ch[1]==y) z->ch[1]=x;
    }
    void splay(nod *x){
        int tot=0;
        nod *r=x;
        nod *tmp[N];
        for(nod *i=x;i!=NIL;i=i->pr) tmp[++tot]=i;
        for(int i=tot;i>0;i--) clear(tmp[i]);
        while(x->pr!=NIL){
            nod *y=x->pr,*z=y->pr;
            r=(z==NIL?y:z);
            if(z==NIL&&y->ch[0]==x) rotate(x,0);
            else if(z==NIL&&y->ch[1]==x) rotate(x,1);
            else if(z->ch[0]==y&&y->ch[0]==x) {rotate(y,0);rotate(x,0);}
            else if(z->ch[1]==y&&y->ch[1]==x) {rotate(y,1);rotate(x,1);}
            else if(z->ch[1]==y&&y->ch[0]==x) {rotate(x,0);rotate(x,1);}
            else {rotate(x,1);rotate(x,0);}
        }
        x->pp=r->pp;
    }
    void access(nod *x){
        for(nod *u=x,*v=NIL;u!=NIL;v=u,u=u->pp)
            {splay(u);u->ch[1]->pr=NIL;u->ch[1]->pp=u;u->ch[1]=v;v->pr=u;}
    }
    void makeroot(nod *x){
        access(x);splay(x);x->rev^=1;
    }
    void link(int u,int v){
        nod *x=pt[u],*y=pt[v];
        makeroot(x);x->pp=y;
    }
    void cut(int u){
        nod *x=pt[u];
        access(x);splay(x);x->ch[0]->pp=x->ch[0]->pr=NIL;x->ch[0]=NIL;
    }
    int getroot(int u){
        nod *x=pt[u];
        access(x);splay(x);
        for(;x->ch[0]!=NIL;x=x->ch[0],clear(x)) ;
        return x->num;
    }
    int lca(int u,int v){
        nod *x=pt[u],*y=pt[v];
        access(x);access(y);splay(x);
        if(x->pp!=NIL) return x->pp->num;
        return x->num;
    }
};

int main(){
    scanf("%d%d",&n,&m);
    LCT T;
    for(int i=1;i<=m;i++){
        int  u,v;
        char s[11];
        scanf("%s%d%d",s,&u,&v);
        if(s[0]=='C') T.link(u,v);
        else if(s[0]=='Q') printf("%s\n",T.getroot(u)==T.getroot(v)?"Yes":"No");
        else T.cut(T.lca(u,v)==u?v:u);
    }

    return 0;
}
