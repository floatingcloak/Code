> # 题意
### Description
### 　　阿申准备报名参加GT考试，准考证号为N位数X1X2....Xn(0<=Xi<=9),他不希望准考证号上出现不吉利的数字。
### 他的不吉利数学A1A2...Am(0<=Ai<=9)有M位，不出现是指X1X2...Xn中没有恰好一段等于A1A2...Am. A1和X1可以为0
### Input
### 　　第一行输入N,M,K.接下来一行输入M位的数。 N<=10^9,M<=20,K<=1000
### Output
### 　　阿申想知道不出现不吉利数字的号码有多少种，输出模K取余的结果.
### Sample Input
### 4 3 100 
### 111
### Sample Output
### 81

> # 题解
## ~~蒟蒻膜拜神题~~
## 奉上大牛博客 [Here](http://blog.csdn.net/cjk_cjk/article/details/43038377)
## 像这种题如果没有见过能做出来是万分厉害的%%%
## ~~反正我不会~~ 用到了Kmp一类的Dp 需要一些经验才能对这种题有感觉
## f[i][j]意为以准考证中的地i位为结尾的后缀已经匹配到了不吉利串以j为结尾的前缀的方案数(这口气好长)
## 答案就是$\sum_{i=0}^{m-1}f[n][i]$显然
## 那么我们考虑如何转移 我们考虑从前面“要”
## $f[i][j] = \sum_{k=0}^{m-1}(f[i-1][k] * a[k][j])$
## 这个乱七八糟的式子是什么东西呢?考虑在已知f[i-1][k]的答案后再i-1的后面加了一个数字
## 加了一个数字后变成了i(加了一个) 那么是不是$f[i][j] = f[i-1][k]$?
## 当然不是 加了这个数字是未知的 但我们知道只有0~9这十个数字 加了不同的数字会让f[i-1][k]中的k变成不同的值(即匹配的位数会有变化)
## 那么a[k][j]这个a数组代表当i-1状态匹配了k位 在i-1后面任意加一个数字x致使可以匹配j位 这个x的个数
## 现在只要我们有了这个a数组就可以很方便的转移 那么a怎么求呢
## 很好求 ~~一眼看上去~~可以知道上述a数组的功能其实就是一个next表(Kmp中的那个)
## ~~我不讲Kmp~~这样就可以通过对不吉利串来处理出一个a数组 然后进行转移
## 似乎问题已经解决 但是数据范围?N <= 10 ^ 9 ...
## ~~好的此题不可做大家散了吧~~
## 恩我们观察这个转移式子 sigma f[i-1][k] * a[k][j] 多么像矩阵乘法的形式！而且每次转移乘的都是同一个a数组！
## 我们把f看成矩阵A a看成矩阵B 那么A * B就是一次转移
## A * B * B * B * B ...如此乘很多次就可以得到最后的答案 而矩阵乘满足结合律 对B矩阵快速幂再与A相乘即可
## 最后答案取$\sum_{k=0}^{m-1}f[0][k]$初值f[0][0] = 1
## 我们总结一些：Kmp预处理 + Dp + 矩阵乘法快速幂
## 再次%蒟蒻
## 下面上代码
```
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
    scanf("%d%d%d",&n,&m,&p);
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
```
# 欢迎指出Bug


