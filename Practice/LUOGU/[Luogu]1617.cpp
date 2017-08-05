#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;



int main() {
	hs[1] = "one"; hs[2] = "two"; hs[3] = "three"; hs[4] = "four"; hs[5] = "five"; hs[6] = "six"; hs[7] = "seven"; hs[8] = "eight"; hs[9] = "nine";
	hs1[1][0] = "ten";
	scanf("%d", &n);
	while(n) {
		b[++t] = n % 10;
		n /= 10;
	}
	int a = b[4] * 10 + b[3];
	int c = b[2] * 10 + b[1];
	if(b[4]) {
		cout << hs[b[4]] << "thousand ";
	}
	if(b[3]) {
		cout << hs[b[3]] << "hundred ";
	}
	if()
}