#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 3200;

int n,m,a[Maxn],c[Maxn],cnt[Maxn],d[Maxn],tot,Ans[Maxn];

bool Judge(int x){cnt[x]++;
	for(int i = 1;i <= n;i++){
		if(cnt[i] >= 2){memcpy(c,cnt,sizeof(cnt));
			cnt[i] -= 2;
			for(int j = 1;j <= n;j++){
				if(cnt[j] >= 3){cnt[j] %= 3;}
				if(cnt[j] >= 1 && cnt[j + 1] >= 1 && cnt[j + 2] >= 1 && j + 2 <= n){
					int k = min(min(cnt[j],cnt[j + 2]),cnt[j + 1]);cnt[j] -= k;cnt[j + 1] -= k;cnt[j + 2] -= k;	
				}
			}
			int pd = 1;
			for(int l = 1;l <= n;l++)if(cnt[l] != 0){pd = 0;break;}
			if(pd == 1)return 1;
			memcpy(cnt,c,sizeof(c));
		}
	}return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= 3 * m + 1;i++){
		scanf("%d",&a[i]);cnt[a[i]]++;
	}
	for(int i = 1;i <= n;i++){
		memcpy(d,cnt,sizeof(cnt));
		if(Judge(i))Ans[++tot] = i;
		memcpy(cnt,d,sizeof(d));
	}
	for(int i = 1;i < tot;i++)printf("%d ",Ans[i]);
	if(tot >= 1)printf("%d",Ans[tot]);
	else printf("NO");
	return 0;
}
