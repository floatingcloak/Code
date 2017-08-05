#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int n,d,T;
int c[2000][2000];
int maxn;
int num;

int main()
{
    cin>> d; 

    cin>> n;
    for(int i=0;i<=1224;i++)
        for (int j=0;j<=1224;j++)
            c[i][j]=0;
    for(int i=1;i<=n;i++) 
	{
        int x,y,t;
        cin>> x;
        cin>> y;
        cin>> t;
        c[x][y]+=t;
    }
        
    for(int i=0;i<=1558;i++){
        for(int j=0;j<=1558;j++){
            if(i>=1&&j==0)c[i][j]+=c[i-1][j];
            if(i==0&&j>=1)c[i][j]+=c[i][j-1];
            if(i>=1&&j>=1)c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
    	}
    }
    
    int f=d*2+1;
     
    for(int i=d;i<=128+d;i++)
        for(int j=d;j<=128+d;j++){
            int l=i-f;
            int r=j-f;
			int ll=0;
            if(l>=0&&r>=0)ll=c[i][j]-c[l][j]-c[i][r]+c[l][r];
            if(l< 0&&r>=0)ll=c[i][j]-c[i][r];
            if(l>=0&&r< 0)ll=c[i][j]-c[l][j];
            if(l< 0&&r< 0)ll=c[i][j];
            if(ll==maxn) num++;
            if(ll>maxn) 
			{  
				maxn=ll; 
				num=1;
			}
        };
    printf("%d %d\n",num,maxn);   
	// for(;;);
}