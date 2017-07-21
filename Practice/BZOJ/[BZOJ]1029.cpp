#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 151000;

priority_queue <int> Q;

struct node {int l,r;}a[Maxn];

inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

int n,ans,tot;

bool comp(node a,node b){return a.r < b.r;}

int main(){
//	freopen("repair.in","r",stdin);
//	freopen("repair.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){a[i].l = read();a[i].r = read();}
	sort(a + 1,a + n + 1,comp);
	for(int i = 1;i <= n;i++){
		if(tot + a[i].l <= a[i].r){tot += a[i].l;Q.push(a[i].l);}
		else if(a[i].l < Q.top() && tot - Q.top() + a[i].l <= a[i].r){tot -= Q.top();tot += a[i].l;Q.pop();Q.push(a[i].l);}	
	}
	printf("%d\n",Q.size());
	return 0;
}
