#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 10010;

int a[Maxn],f[Maxn],n,ans;

int Check() {
	for(int i = 2;i <= n;i++) f[i + 1] = a[i] - f[i] - f[i - 1];
	if(f[n + 1] != 0)return 0;
	else return 1;	
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&a[i]);	
	}
	for(int i = 0; i <= a[1]; ++i) {
		memset(f,0,sizeof(f));
		f[1] = i;
		f[2] = a[1] - i;
		if(Check())ans++;
	}
	printf("%d\n",ans);
	return 0;
}
