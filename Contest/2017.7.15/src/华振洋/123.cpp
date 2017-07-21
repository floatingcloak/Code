#include<iostream>
#include<cstdio>
using namespace std;
int a[1100];
long long f[1100][1055],g[1100][1055],G[1100][1055];
long long ans;
int main()
{
	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) {
		f[i][a[i]]++;
		for(int j=0;j<1024;j++) {
			f[i][j]+=f[i-1][j];
			f[i][a[i]^j]+=f[i-1][j];
		}
	}
	for(int i=n;i>=1;i--) {
		g[i][a[i]]++;
		G[i][a[i]]++;
		for(int j=0;j<1024;j++) {
			g[i][j]+=g[i+1][j];
			g[i][a[i]&j]+=g[i+1][j];
			G[i][a[i]&j]+=g[i+1][j];
		}
	}
	for(int i=1;i<=n;i++)
        for(int j=0;j<1024;j++)
            ans+=f[i][j]*G[i+1][j];
    cout<<ans<<endl;
} 
