#include<cstdio>
#include<algorithm>

using namespace std;

int n, c, pd = 1, week;

struct point{
	int v,b;
} num[21];

int comp(const point &a, const point &b) {return a.v > b.v;}

int main() {
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i++) scanf("%d%d", &num[i].v, &num[i].b);
    sort(num + 1, num + n + 1, comp);
    while(pd)
    {
        int tot = c; pd = 0;
        for(int i = 1; i <= n; i++) while(tot >= num[i].v && num[i].b) tot -= num[i].v, num[i].b--;
        for(int i = n; i >= 1; i--) while(tot > 0 && num[i].b) tot -= num[i].v, num[i].b--;
        if(tot <= 0){ week++; pd = 1;}
    }
    printf("%d\n", week);
    return 0;
}