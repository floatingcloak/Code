#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
long long x,y;
long long n,b;
vector < pair < long long, long long > > a;
//vector�������ֻ࣬���������������ڲ�ȷ�����ݴ�С������£�vector���ܿ��Խ�ʡ�ܶ�ռ�
//pair�ͽṹ���ֻ࣬����������д�������������������ȵȣ���ֻ����������������Ƽ�дpair
long long ans;
#define C getchar()

inline void read(long long &s){
    s=0; int t=1,k=C;
    for (;k<'0'||k>'9';k=C) if (k=='-') t=-1;//�жϸ������� 
    for (;k>='0'&&k<='9';k=C) s=(s<<1)+(s<<3)+(k^48);//<<1����<<3���൱��*10������λ������ٶȽϿ죬^48Ҳ�൱��-��0����ͬ���Ͽ졣 
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
	 //��a�����в���һ��Ԫ����ĩβ��{x, y}��ʾһ��pair�͵�������һ��Ԫ����x���ڶ�����y
    for(long long i = 0; i < n; i++) {
    //vector�����һ�����±�Ϊ0
  if(b / a[i].first < a[i].second) {
        //��������ɿ�����������������ţ
            ans += b / a[i].first;
            //��ô�������������ţ��������Ϻ�϶�����������������ţ��
            break;
            //����ѭ��
        }
        //�����������������ţ����ôȫ������
        ans += a[i].second;
        b -= a[i].first * a[i].second;
        //�����.first .second��ʾ��������ṹ���е�һ��Ԫ�ء��ڶ���Ԫ��
    }
    write(ans);
    return 0;
}	 

