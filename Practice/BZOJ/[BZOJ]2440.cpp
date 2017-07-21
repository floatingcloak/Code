#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void gcd(int a,int b,int &d,int &x,int &y) {
     if(!b) { d = a; x = 1; y = 0; }
     else gcd(b, a%b, d, y, x), y -= (a/b)*x;
}

int main(){
    while(scanf("%d",&n) != EOF){
        scanf("%d%d",&a1,&r1);n--;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a2,&r2);
            ExGcd(a,b,d,x,y); // ax + by = c
            if(c % d) return -1;
            else x = c / d * x % (b / d); 
        }
    }
}