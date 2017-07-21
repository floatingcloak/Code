#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a;
long long  m,t,u,f,d,i,sum;

int main()
{
    freopen("racing.in","r",stdin);
    freopen("racing.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&m,&t,&u,&f,&d);
	for(i=0;i<=t;i++)
	{
		getchar();
		scanf("%c",&a);
		if(a=='u')sum+=u+d;	
		if(a=='f')sum+=f+f;
		if(a=='d')sum+=u+d;
		if(sum>m)break;
	}
	printf("%lld\n",i);
}