#include<iostream>
#include<cstdio>
#include<cstring>

#define fo(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a) for(i=first[a];i;i=next[i])

using namespace std;

const int maxn=100007,da=100007;

struct node{int l,r,sum;}t[maxn*100];

int i,j,k,l,n,m,ans,r,mid;
int f[maxn],a[maxn],p[maxn],q[maxn],num,mx[maxn],mi[maxn],root[maxn];
bool bz,az;

int lowbit(int x){return x&(-x);}

int find(int x,int l,int r,int y,int z){
    if(!x)return 0;
    if(l==y&&r==z)return t[x].sum;
    int mid=(l+r)/2;
    if(z<=mid)return find(t[x].l,l,mid,y,z);
    else if(y>mid)return find(t[x].r,mid+1,r,y,z);
    else return max(find(t[x].l,l,mid,y,mid),find(t[x].r,mid+1,r,mid+1,z));
}

void change(int &x,int l,int r,int y,int z){
    if(!x) x = ++num;
    t[x].sum = max(t[x].sum,z);
    if(l == r) return;
    int mid = (l+r)/2;
    if(y <= mid) change(t[x].l,l,mid,y,z);
    else change(t[x].r,mid+1,r,y,z);
}

int main(){
//  freopen("fan.in","r",stdin);
    scanf("%d%d",&n,&m);
    fo(i,1,n)scanf("%d",&a[i]),mx[i]=mi[i]=a[i];
    fo(i,1,m){scanf("%d%d",&k,&l);mx[k]=max(l,mx[k]);mi[k]=min(l,mi[k]);}
    fo(i,1,n){
        int o=0;
        for(j=mi[i];j;j-=lowbit(j))o=max(o,find(root[j],1,da,1,a[i]));
        f[i] = o + 1;
        ans=max(ans,f[i]);
        for(j=a[i];j<=da;j+=lowbit(j))change(root[j],1,da,mx[i],f[i]);
    }
    printf("%d\n",ans);
    while(1);
}