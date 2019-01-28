#include<bits/stdc++.h>
#define C getchar()
inline void read(int &s){
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
    putchar('\n');
}
int a,b;
int main(){
	read(a);
    read(b);
    write(a);
    write(b);
	}
