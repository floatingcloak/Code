#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char str1[10], str2[10];

int main() {
	cin >> str1 >> str2;
	int len1 = strlen(str1), len2 = strlen(str2);
	int sum1 = 1, sum2 = 1;
	for(int i = 0; i < len1; ++i) sum1 = (sum1 * ((int)str1[i] - 64)) % 47;
	for(int i = 0; i < len2; ++i) sum2 = (sum2 * ((int)str2[i] - 64)) % 47;
	if(sum1 == sum2) puts("GO");
	else puts("STAY");
	return 0;
}
