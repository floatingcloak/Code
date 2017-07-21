#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;



int main() {
	freopen("J.out", "w", stdout);
	srand(time(0));
	int T = 1000;
	printf("%d\n", T);
	while(T--) {
		int n = rand() % 100 + 50;
		printf("%d\n", n);
		for(int i = 1; i <= n; ++i) {
			printf("%d ", rand() * rand());
		}
		puts("");
	}
	return 0;
}
