#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 100000007
#define eps 1e-6

using namespace std;

const int Maxn = 510;

int n,m,dis[Maxn][Maxn];
double sx[Maxn],sy[Maxn],tx[Maxn],ty[Maxn];

bool Judge(int u,int v){int pd = 1;
	if(sx[u] == sx[v]){
		if(sy[v] > sy[u]){for(int i = 1;i <= n;i++)if(tx[i] > sx[u] + eps){pd = 0;break;}	}
		else {for(int i = 1;i <= n;i++)if(tx[i] + eps < sx[u]){pd = 0;break;}}
	}
	else {
		double k1 = (sy[v] - sy[u]) / (sx[v] - sx[u]);
		double b1 = sy[u] - k1 * sx[u];
		if(k1 == 0){
			if(sx[v] > sx[u]){for(int i = 1;i <= n;i++)if(ty[i] + eps < sy[u]){pd = 0;break;}}
			else {for(int i = 1;i <= n;i++)if(ty[i] > sy[u] + eps){pd = 0;break;}}
		}
		else if(sy[v] > sy[u]){
			if(k1 > 0){for(int i = 1;i <= n;i++)if(ty[i] + eps < k1 * tx[i] + b1){pd = 0;break;}}
			else {for(int i = 1;i <= n;i++){
//					if(u == 7 && v == 4)printf(">>>%d\n",i);
					if(ty[i] > k1 * tx[i] + b1 + eps){pd = 0;break;}
				
				}
			}
		}
		else {
			if(k1 > 0){for(int i = 1;i <= n;i++)if(ty[i] > k1 * tx[i] + b1 + eps){pd = 0;break;}}
			else {for(int i = 1;i <= n;i++)if(ty[i] + eps < k1 * tx[i] + b1){pd = 0;break;}}	
		}
	}return pd;
}

bool Judge2(int u,int v){
	int pd = 1;
	if(sx[u] == sx[v]){for(int i = 1;i <= n;i++){if(ty[i] > max(sy[u],sy[v]) || ty[i] < min(sy[u],sy[v])){pd = 0;break;}	}}
	else {
		double k1 = (sy[v] - sy[u]) / (sx[v] - sx[u]);
		double b1 = sy[u] - k1 * sx[u];
		for(int i = 1;i <= n;i++){if(ty[i] != tx[i] * k1 + b1){pd = 0;break;}}
	}return pd;
}

bool Judge3(int u,int v){int pd = 1;
//	
	if(fabs(sx[u] - sx[v]) < eps){
		for(int i = 1;i <= n;i++)if(ty[i] > max(sy[u],sy[v]) || ty[i] < min(sy[u],sy[v])){pd = 0;break;}
		return pd;
	}
	else {
		double k1 = (sy[v] - sy[u]) / (sx[v] - sx[u]);
		double b1 = sy[v] - k1 * sx[v];	
		double mxx = max(sx[u],sx[v]),mix = min(sx[u],sx[v]),mxy = max(sy[u],sy[v]),miy = min(sy[u],sy[v]);
		if(k1 != 0){
			for(int i = 1;i <= n;i++){
//				if(u == 1 && v == 3)printf("%d\n",(fabs(ty[i] - tx[i] * k1 - b1) > eps));
				if((fabs(ty[i] - tx[i] * k1 - b1) >eps) || (tx[i] > mxx) || (ty[i] > mxy) || (tx[i] < mix) || (ty[i] < miy)){pd = 0;break;}
//				if(u == 1 && v == 3)printf("%d\n",pd);
			}
//			if(u == 1 && v == 3)printf("%d\n",pd);
		}
		else {
			for(int i = 1;i <= n;i++)if(ty[i] != sy[u] || (tx[i] < mix) || (tx[i] > mxx)){pd = 0;break;}
		}
	}return pd;
}

int main(){
	scanf("%d%d",&m,&n);int pd = 1;double x1,y1,z1;
	for(int i = 1;i <= m;i++){
		double x,y,z;scanf("%lf%lf%lf",&x,&y,&z);
		if(i == 1){x1 = x;y1 = y;z1 = z;}
		else if(x != x1 || y != y1 || z != z1)pd = 0;
		sx[i] = x;sy[i] = y;
	}
	for(int i = 1;i <= n;i++){
		double x,y,z;scanf("%lf%lf%lf",&x,&y,&z);
		if(x != x1 || y != y1 || z != z1)pd = 0;
		tx[i] = x;ty[i] = y;
	}
	if(pd == 1){printf("1\n");return 0;}pd = 1;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			if(Judge3(i,j)){pd = 0;break;}
		}
	}if(pd == 0){printf("2\n");return 0;}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++)dis[i][j] = INF;	
	}
	for(int i = 1;i <= m;i++){
		for(int j = i + 1;j <= m;j++){
			if(Judge(i,j))dis[i][j] = 1;
			else if(Judge(j,i))dis[j][i] = 1;
			else if(Judge2(i,j))dis[i][j] = dis[j][i] = 1;
			
		}
	}
	
	for(int k = 1;k <= m;k++){
		for(int i = 1;i <= m;i++){
			if(dis[i][k] == INF)continue;
			for(int j = 1;j <= m;j++)dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
		}
	}int Ans = INF;
	for(int i = 1;i <= m;i++)Ans = min(Ans,dis[i][i]);
	if(Ans == INF){printf("-1\n");return 0;}
	printf("%d\n",Ans);
	return 0;
}
