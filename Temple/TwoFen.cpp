#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 220000
#define inf 1000000000

using namespace std;
struct query
{
    int x,y,k,s,tp,cur;
}q[maxn],q1[maxn],q2[maxn];
int a[maxn],ans[maxn],tmp[maxn],t[maxn];
int n,m,num,cnt;

void add(int x,int y)
{
    for (int i=x;i<=n;i+=(i&-i)) t[i]+=y;
}

int ask(int x)
{
    int tmp=0;
    for (int i=x;i>0;i-=(i&-i)) tmp+=t[i];
    return tmp;
}

void divide(int head,int tail,int l,int r) {//head到tail询问的答案区间在l到r之间 
//即要处理 l 到 r 之间的数 对 head 到 tail 之间的询问的影响 
    if (head>tail) return ;
    
    if (l==r) {//当前答案为 l 
        for(int i=head;i<=tail;i++) if(q[i].tp==3) ans[q[i].s]=l;//询问 
        return;
    }
    
    int mid=(l+r)>>1;
    
    for (int i=head;i<=tail;i++) {
        if (q[i].tp==1&&q[i].y<=mid) add(q[i].x,1);
        if (q[i].tp==2&&q[i].y<=mid) add(q[i].x,-1);
        if (q[i].tp==3) tmp[i]=ask(q[i].y)-ask(q[i].x-1);//计算当前层的修改对当前层询问的贡献 
    }
    
    for (int i=head;i<=tail;i++) {
        if (q[i].tp==1&&q[i].y<=mid) add(q[i].x,-1);//消除这层的影响 
        if (q[i].tp==2&&q[i].y<=mid) add(q[i].x,1);
    }
    
    int l1=0,l2=0;
    
    for (int i = head; i <= tail; i++) {//类似l = mid + 1 r = mid - 1?
        if (q[i].tp==3) {
            if (q[i].cur+tmp[i]>q[i].k-1) q1[++l1]=q[i];//q[i].cur+tmp[i]表示累积了多少个数 大了要往小的一方递归 
            else {
                q[i].cur+=tmp[i];//如果小的话向大的一方递归并统计当前层答案 
                q2[++l2]=q[i];
            }
        }
        else {
            if (q[i].y<=mid) q1[++l1]=q[i];
            else q2[++l2]=q[i];
        }
    }
    for (int i=1;i<=l1;i++) q[head+i-1]=q1[i];
    for (int i=1;i<=l2;i++) q[head+l1+i-1]=q2[i];
    
    divide(head,head+l1-1,l,mid);
    divide(head+l1,tail,mid+1,r);
}    

int main()
{
    //freopen("ranking.in","r",stdin);
    //freopen("ranking.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        q[++num].x=i; q[num].y=a[i];
        q[num].tp=1; q[num].s=0;
    }
    char sign;
    int x,y,z;
    for (int i=1;i<=m;i++)
    {
        scanf("\n%c",&sign);
        if (sign=='Q')
        {
            scanf("%d%d%d",&x,&y,&z);
            q[++num].x=x,q[num].y=y,q[num].k=z;
            q[num].tp=3; q[num].s=++cnt;//是询问。。 
        }
        else
        {
            scanf("%d%d",&x,&y);
            q[++num].x=x; q[num].y=a[x];//原来的 (即要删除的2代表删除)
            q[num].tp=2; q[num].s=0;
            q[++num].x=x; q[num].y=y;//改后的 
            q[num].tp=1; q[num].s=0;
            a[x]=y;
        }
    }
    divide(1,num,0,inf);
    for (int i=1;i<=cnt;i++)
        printf("%d\n",ans[i]);
    return 0;
}
