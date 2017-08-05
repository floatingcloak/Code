#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn=2000001;

struct node {string str;int step;}point[Maxn];

int n=1,head=1,tail=1;
string a[7],b[7],str1;

int main()
{
    cin>>point[head].str>>str1;
    while(cin>>a[n]>>b[n]){++n;}n--;
    while(head<=tail&&point[head].step<10){
        for(int k=1;k<=n;k++){
            int len=point[head].str.size();
            for(int i=0;i< len;i++){
                if(point[head].str.compare(i,a[k].size(),a[k])==0){
                    tail++;
                    point[tail].step=point[head].step+1;
                    point[tail].str=point[head].str;
                    point[tail].str.replace(i,a[k].size(),b[k]);
                    if(point[tail].str==str1){
                        cout<<point[tail].step;
                        return 0;
                    }
                }
            }
        }
        head++;
    }
    printf("NO ANSWER!");
}