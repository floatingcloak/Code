#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 100100;

int a[Maxn],b[Maxn],n,sum1,sum2;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline int Solve(int a[],int b[]){
	int l1 = 1,r1 = n,l2 = 1,r2 = n,ans = 0;
	while(l1 <= r1 && l2 <= r2){
		if(a[l1] > b[l2]){ans += 2;++l1;++l2;}
		else if(a[r1] > b[r2]){ans += 2;--r1;--r2;}
		else {ans += (a[l1] == b[r2]);++l1;--r2;}
	}return ans;
}

int main(){
//	freopen("bnb.in","r",stdin);
//	freopen("bnb.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;++i)a[i] = read();
	for(int i = 1;i <= n;++i)b[i] = read();
	sort(a + 1,a + n + 1);sort(b + 1,b + n + 1);
	printf("%d %d\n",Solve(a,b),2 * n - Solve(b,a));
	return 0;
}
