#include<bits/stdc++.h>
#define pow 4
#define size 10005
#define base 10000 
using namespace std;
typedef int ll;
struct bign{
	ll len,s[size];
	bign(){
		len=1;
		memset(s,0,sizeof(s));
	}
	bign(ll b){
		len=0;
		memset(s,0,sizeof(s));
		do s[++len]=b%base;
		while(b/=base);
	}	
	bign(const char *b){
		memset(s,0,sizeof(s));
		ll xx=strlen(b);
		len=(xx-1)/pow+1;
		for(int i=0,j=len;i<xx;i++){
			if(i&&(xx-i)%pow==0) j--;
			s[j]=s[j]*10-'0'+b[i];
		}
	}
	bign operator =(ll b){ 
		return *this=bign(b);
	}
	bign operator =(const char *b){
		return *this=bign(b);
	}
	bool operator <(const bign &b){
		if(len!=b.len) return len<b.len;
		for(int i=len;i;i--){
			if(s[i]!=b.s[i]){
				return s[i]<b.s[i];
			}	
		}
		return false;
	}
	bool operator >(const bign &b){
		if(len!=b.len) return len>b.len;
		for(int i=len;i;i--){
			if(s[i]!=b.s[i]){
				return s[i]>b.s[i];
			}
		}
		return false;
	}
	bool operator ==(const bign &b){
		return !(*this>b)&&!(*this<b);
	}
	void clean(){
		while(len>1&&!s[len])
			len--;
	}
	bign operator +(const bign &b){
		bign c;
		c.len=max(len,b.len);
		bool g=0;
		for(int i=1;i<=c.len;i++){
			c.s[i]=s[i]+b.s[i]+g;
			if(c.s[i]>=base){
				g=1;
				c.s[i]-=base;
			}
			else g=0;
		}
		if(g) c.s[++c.len]=1;
		return c;
	}
	bign operator -(const bign &b){
		bign c;
		c.len=len;
		bool g=0;
		for(int i=1;i<=len;i++){
			c.s[i]=s[i]-b.s[i]-g;
			if(c.s[i]<0){
				g=1;
				c.s[i]+=base;
			}
			else g=0;
		}
		c.clean();
		return c;
	}
	bign operator *(const bign &b){
		bign c;
		c.len=len+b.len;
		for(int i=1;i<=len;i++){
			for(int j=1;j<=b.len;j++){
				c.s[i+j-1]+=s[i]*b.s[j];
				c.s[i+j]+=c.s[i+j-1]/base;
				c.s[i+j-1]%=base;
			}
		}
		c.clean();
		return c;
	}
	bign operator /(ll b){
		bign c;
		c.len=len;
		ll g=0;
		for(int i=len;i;i--){
			g=base*g+s[i];
			c.s[i]=g/b;
			g%=b;
		}
		c.clean();
		return c;
	}
};
char s[size*pow];
istream& operator >>>(istream &in,bign &c){
  in>>s;
  c=s;
  return in;
}
ostream& operator <<<(ostream &out,const bign &c){
    out<<c.s[c.len];
    for(int i=c.len-1;i;i--){
    	out<<setfill('0')<<setw(pow)<<c.s[i];
	}
    return out;
}
int main(){
	freopen("1.in","r",stdin);
	//freopen("WA.out","w",stdout);
	bign n;
	cin>>>n;
	bign l=1,r;
	r.len=126,r.s[126]=1;
	bign mid=(l+r)>>1;
	while(!(l>r)){		
		/*cout<<l<<endl;
		cout<<r<<endl;
		cout<<mid<<endl;
		cout<<mid*mid<<endl<<"-----"<<endl;*/
		if(mid*mid>n) r=mid-1;
		else l=mid+1;
		mid=(l+r)/2;
	}
	cout<<<mid<<<endl;
	return 0;
}
