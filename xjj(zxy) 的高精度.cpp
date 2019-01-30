#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define mset(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=x,I=y;i<=I;++i)
#define input(x) freopen(x".in","r",stdin)
#define output(x) freopen(x".out","w",stdout)
using namespace std;
typedef long long LL;
inline int read(int &r){
    r=0;bool p=1;char c=getchar();
    while(c<'0' or c>'9'){if(c=='-')p=0;c=getchar();}
    while(c>='0' and c<='9')r=10*r-'0'+c,c=getchar();
	return p?r:-r;
}
const int SIZE=10086;
const int BASE=10000;
const int POW=4;
struct bigInt{
	#define len v[0]
	LL v[SIZE];
	bigInt(){mset(v,0);len=1;}
	bigInt(LL b){mset(v,0);do v[++len]=b%BASE;while(b/=BASE);}
	bigInt(const char *b){
		mset(v,0);
		int unit=strlen(b);
		len=(unit-1)/POW+1;
		for(int i=0,j=len;i<unit;++i){
			if(i and (unit-i)%POW==0)--j;
			v[j]=v[j]*10-'0'+b[i];
		}
	}
	bool operator>(const bigInt &b)const{
		if(len>b.len)return 1;
		if(len<b.len)return 0;
		for(int i=len;i;--i){
			if(v[i]>b.v[i])return 1;
			if(v[i]<b.v[i])return 0;
		}
		return 0;
	}
	bool operator<(const bigInt &b)const{return b>(*this);}
	bool operator>=(const bigInt &b)const{return !(*this<b);}
	bool operator<=(const bigInt &b)const{return !(*this>b);}
	bool operator==(const bigInt &b)const{return (*this>=b and *this<=b);}
	bigInt operator+(const bigInt &b)const{
		bigInt r;r.len=max(len,b.len);
		bool g=0;
		rep(i,1,r.len){
			r.v[i]=v[i]+b.v[i]+g;
			if(r.v[i]>=BASE)r.v[i]-=BASE,g=1;
			else g=0;
		}
		if(g)r.v[++r.len]=1;
		return r;
	}
	bigInt operator-(const bigInt &b)const{
		bigInt r;r.len=len;
		bool g=0;
		rep(i,1,r.len){
			r.v[i]=v[i]-b.v[i]-g;
			if(r.v[i]<0)r.v[i]+=BASE,g=1;
		else g=0;
		}
		while(r.len>1 and !r.v[r.len])--r.len;
		return r;
	}
	bigInt operator*(const LL &b)const{
		bigInt r;
		if(!b)return r;
		r.len=len;
		LL g=0;
		rep(i,1,r.len){
			r.v[i]=v[i]*b+g;
			g=r.v[i]/BASE;
			r.v[i]%=BASE;
		}
		while(g)r.v[++r.len]=g%BASE,g/=BASE;
		return r;
	}
	bigInt operator*(const bigInt &b)const{
		bigInt r;r.len=len+b.len;
		rep(i,1,len)rep(j,1,b.len){
			r.v[i+j-1]+=v[i]*b.v[j];
			r.v[i+j]+=r.v[i+j-1]/BASE;
			r.v[i+j-1]%=BASE;
		}
		while(r.len>1 and !r.v[r.len])--r.len;
		return r;
	}
	bigInt operator/(const LL &b)const{
		bigInt r;r.len=len;
		LL g=0;
		for(int i=r.len;i;--i){ 
			g=g*BASE+v[i];
			r.v[i]=g/b,g%=b;
		}
		while(r.len>1 and !r.v[r.len])--r.len;
		return r;
	}
	bigInt operator/(const bigInt &b)const{
		bigInt r,g;r.len=len;
		for(int i=r.len;i;--i){
			g=g*BASE+v[i];
			while(g>=b)++r.v[i],g-=b;
		}
		while(r.len>1 and !r.v[r.len])--r.len;
		return r;
	}
	LL operator%(const LL &mod)const{
		LL r=0;
		for(int i=v[0];i;--i)r=(r*BASE+v[i])%mod;
		return r;
	}
	bigInt operator%(const bigInt &b)const{
		bigInt r,g;r.len=len;
		for(int i=r.len;i;--i){
			g=g*BASE+v[i];
			while(g>=b)++r.v[i],g-=b;
		}
		return g;
	}
	bigInt operator+=(const bigInt &b){return *this=*this+b;} 
	bigInt operator-=(const bigInt &b){return *this=*this-b;}
	bigInt operator*=(const LL &b){return *this=*this*b;}
	bigInt operator*=(const bigInt &b){return *this=*this*b;}
	bigInt operator/=(const LL &b){return *this=*this/b;}
	bigInt operator/=(const bigInt &b){return *this=*this/b;}
	bigInt operator%=(const LL &b){return *this=*this%b;}
	bigInt operator%=(const bigInt &b){return *this=*this%b;}
};
char s[SIZE*POW];
istream& operator>>(istream &in,bigInt &a){in>>s;a=s;return in;}
ostream& operator<<(ostream &out,const bigInt &a){
	out<<a.v[a.len];
	for(int i=a.len-1;i;--i)out<<setfill('0')<<setw(POW)<<a.v[i];
	return out;
}
int main(){
	
	return 0;
}
