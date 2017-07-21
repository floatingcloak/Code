#include <cstdio>
#include <cstring>
#include <iostream>
//方程 : dp[i][j] = Sigma ( dp[i-1][k] * a[k][j] ).0<=k<=m-1
//这个式子其实是dp数组和a数组的矩阵乘 所以可以写成dp = dp * a
//最后快速幂加速 --- sssSSSay
using namespace std;

const int M = 80;

int dp[M][M],a[M][M],next[M],p,n,m;
char s[M];

inline char NC(void)
{
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}

inline int read() {
    static char c; c = NC();  int x;
    static int minus; minus = 1;
    for (x = 0; !(c >= '0' && c <= '9'); c = NC()) if(c == '-') minus = -1;
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = NC()); x *= minus;
    return x;
}

void Mul(int a[M][M],int b[M][M],int c[M][M]){//矩阵乘法
    int d[M][M];
    for(int i=0;i< m;i++){
        for(int j=0;j< m;j++){
            d[i][j] = 0;
            for(int k=0;k< m;k++)d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % p;
        }
    }
    for(int i=0;i< m;i++){
        for(int j=0;j< m;j++)c[i][j] = d[i][j];
    }
}

int main(){
    freopen("bzoj_1009.in","r",stdin);
    freopen("bzoj_1009.out","w",stdout);
    n = read(); m = read(); p = read();
    scanf("%s",(s + 1));int j = 0;
    for(int i=2;i<=m;i++){//处理Next表
        while(j && s[i] != s[j + 1])j = next[j];
        if(s[i] == s[j + 1])j++;next[i] = j;
    }
    for(int i=0;i< m;i++){//枚举在哪一位失配
        for(int j=0;j<=9;j++){//枚举这一位准考证是什么
            int t = i;while(t>0 && s[t + 1] - '0' != j)t = next[t];//找匹配在哪里
            if(s[t + 1] - '0' == j)a[i][t+1]++;//由i转移到t的数+1
            else a[i][0]++;//重新到第一位 即无法匹配
        }
    }
    dp[0][0] = 1;//初始化
    while(n){//快速幂
        if(n & 1)Mul(dp,a,dp);
        Mul(a,a,a);
        n >>= 1;
    }int Sum = 0;
    for(int i=0;i< m;i++)Sum = (Sum + dp[0][i]) % p;//最后一个阶段的所有状态相加即为答案
    printf("%d\n",Sum);
    // while(1);
    return 0;
}
