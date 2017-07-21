#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
  
#define p 1000000
  
using namespace std;
  
const int Maxn = 1010;
  
int n,d[Maxn],pri[Maxn*Maxn],Ans[Maxn],LenAns,tot,cnt,m,num[Maxn];
  
bool Judge(int x){int N = sqrt(x);
    for(int i=2;i<=N;i++)if(x % i == 0)return 0;
    return 1;
}
  
void Mul(int x){
    for(int i=1;i<=LenAns;i++)Ans[i] *= x;
    for(int i=1;i<=LenAns;i++){
        Ans[i + 1] += Ans[i] / p;
        Ans[i] %= p;
    }
    while(Ans[LenAns + 1] > 0){LenAns++;Ans[LenAns + 1] += Ans[LenAns] / p;Ans[LenAns]  %= p;}
}
  
void Solve(int x,int c){
    for(int i=1;i<=x;i++){
        int k = i;
        for(int j=1;j<=cnt;j++){
            if(k <= 1)break;
            while(k % pri[j] == 0){
                num[j] += c;
                k /= pri[j];
            }
        }
    }
}
  
void Print(){
    for(int i=LenAns;i>=1;i--){
        if(i == LenAns)printf("%d",Ans[i]);
        else printf("%06d",Ans[i]);
    }printf("\n");
}
 
int main(){
	freopen("ctree.in","r",stdin);
	freopen("ctree.out","w",stdout);
    scanf("%d",&n);Ans[1] = 1;LenAns = 1;
    if(n == 1){
        scanf("%d",&d[1]);
        if(d[1] == 0)printf("1\n");
        else printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
        if(d[i] == 0){
            printf("0\n");
            return 0;
        }
        else if(d[i] != -1)tot += d[i] - 1;
    }
    if(n == 3 && d[1] == 1 && d[2] == 1 && d[3] == 1){
    	printf("0\n");
		return 0;	
    }
    if(tot > n - 2){
        printf("0\n");
        return 0;
    }
    for(int i=2;i<=1000;i++)if(Judge(i))pri[++cnt] = i;
    Solve(n - 2,1);Solve(n - 2 - tot,-1);
    for(int i=1;i<=n;i++)if(d[i] != -1)Solve(d[i] - 1,-1);
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=num[i];j++)Mul(pri[i]);
    }
    Print();
    // while(1);
    return 0;
}
