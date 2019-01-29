#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
long long x,y;
long long n,b;
vector < pair < long long, long long > > a;
//vector和数组差不多，只不过他不定长，在不确定数据大小的情况下，vector可能可以节省很多空间
//pair和结构体差不多，只不过他不用写变量名、定义类型名等等，在只有两个量的情况下推荐写pair
long long ans;
#define C getchar()

inline void read(long long &s){
    s=0; int t=1,k=C;
    for (;k<'0'||k>'9';k=C) if (k=='-') t=-1;//判断该数正负 
    for (;k>='0'&&k<='9';k=C) s=(s<<1)+(s<<3)+(k^48);//<<1加上<<3就相当于*10，但是位运算的速度较快，^48也相当于-‘0’，同理，较快。 
    s*=t;
}
#define G(a) putchar(a+48)
inline void write(int s){
    if (s<0) G(-3),s=-s;
    if (s>9) write(s/10);
    G(s%10);
}
int main(){
	read(n);
	read(b);
	for(int i=1;i<=n;i++){
		read(x);
		read(y);
		a.push_back({x, y});
		}
	sort(a.begin(), a.end());
	 //在a数组中插入一个元素在末尾，{x, y}表示一个pair型的量，第一个元素是x，第二个是y
    for(long long i = 0; i < n; i++) {
    //vector数组第一个数下标为0
  if(b / a[i].first < a[i].second) {
        //如果这种巧克力不能满足所有奶牛
            ans += b / a[i].first;
            //那么满足能满足的奶牛，满足完毕后肯定不能再满足其它奶牛了
            break;
            //跳出循环
        }
        //如果可以满足所有奶牛，那么全部满足
        ans += a[i].second;
        b -= a[i].first * a[i].second;
        //这里的.first .second表示调用这个结构体中第一个元素、第二个元素
    }
    write(ans);
    return 0;
}	 

