#include<bits/stdc++.h>
#define C getchar()
inline void read(int &s){
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
    putchar('\n');
}
int a,b;
int main(){
	read(a);
    read(b);
    write(a);
    write(b);
	}
