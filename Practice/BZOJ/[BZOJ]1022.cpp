#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 52;

short read(){
	short x=0; char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x;
}

short T,n,a[Maxn];

int main(){
	freopen("bzoj_1022.in","r",stdin);
	freopen("bzoj_1022.out","w",stdout); 
	T = read();
	while(T--){
		n = read();
		for(register int i = 1;i <= n;++i)a[i] = read();
		short SG = 0,pd = 0;
		for(register int i = 1;i <= n;++i){
			if(a[i] != 1)pd = 1;
			SG ^= a[i];
		}puts(((pd == 0 && SG == 0) || (pd == 1 && SG != 0)) ? "John" : "Brother");
	}return 0;
}
