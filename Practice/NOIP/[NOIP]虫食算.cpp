#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Maxn = 1001;

char s1[Maxn],s2[Maxn],s3[Maxn];
int n,m[Maxn],mx;
bool vis[Maxn];

void Dfs(int x,int y,int z){
//    cout<<x<<' '<<y<<' '<<z<<"@@";
//    for(char i='A';i<='A' + n - 1;i = i + 1)printf("%d ",m[i]);
//    printf("\n");
    for(int i=1;i<=x;i++)
    {
        int t1=m[s1[i]],t2=m[s2[i]],t3=m[s3[i]];
        if(t1==-1||t2==-1||t3==-1)continue;
        if(((t3-(t1+t2))%n+n)%n>mx)return;
    }
    if(x == 0 && y == 0){
        for(char i='A';i<='A' + n - 1;i = i + 1)printf("%d ",m[i]);    
        exit(0);
    }
    if(x == 0)return;
    if(z == 1){
        if(m[s1[x]] == -1){
            for(int i=n-1;i>=0;i--){
                if(vis[i])continue;
                vis[i] = 1;
                m[s1[x]] = i;
                Dfs(x,y,2);
                m[s1[x]] = -1;
                vis[i] = 0;
            }
        }
        else Dfs(x,y,2);
    }
    if(z == 2){
        int t1 = m[s1[x]],t2 = m[s2[x]],t3 = m[s3[x]];
        if(t2 == -1){
            for(int i=n-1;i>=0;i--){
                if(vis[i])continue;
                int sum = i + t1 + y;
                if(sum % n != t3 && t3 != -1)continue;
                if(t3==-1)
                {
                    if(vis[sum%n])continue;
                    vis[sum%n]=1;m[s3[x]]=sum%n;
                }
                vis[i]=1;m[s2[x]]=i;
                Dfs(x-1,sum/n,1);
                m[s2[x]]=-1;vis[i]=0;
                if(t3==-1)
                {
                    vis[sum%n]=0;m[s3[x]]=-1;
                }
            }
        }else {
            int sum=t1+t2+y;
            if(sum%n==t3)Dfs(x-1,sum/n,1);
            else if(t3==-1)
            {
                vis[sum%n]=1;
                m[s3[x]]=sum%n;
                Dfs(x-1,sum/n,1);
                m[s3[x]]=-1;
                vis[sum%n]=0;
            }
        }
    }
}

int main(){
    scanf("%d",&n);mx=2*n-2;mx/=n;
    memset(m,-1,sizeof(m));
    cin>>(s1+1)>>(s2+1)>>(s3+1);
    Dfs(n,0,1);
    return 0;
}