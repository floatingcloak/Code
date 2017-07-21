#include <map>
#include <cstdio>

using namespace std;

int n,x;

int main() {
	scanf("%d",&n);
	int ans,cnt = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&x);
		if(cnt == 0) ans = x;
		if(ans == x) cnt++;
		else cnt--;
	}
	printf("%d\n",ans);
}
