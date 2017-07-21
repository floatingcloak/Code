#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

queue <int> Q;

int n, k, ans;

int main() {
	scanf("%d%d", &n, &k);
	Q.push(n);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
//		cout << u << endl;
		int c = u - k;
		if(c & 1 == 1 || c <= 0) {
			++ans;	
		}
		else {
			int now = c >> 1;
			Q.push(now); Q.push(now + k);
		}
	}
	printf("%d\n", ans);
	return 0;
}
