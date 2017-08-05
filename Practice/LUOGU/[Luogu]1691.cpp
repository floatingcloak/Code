#include <iostream>
#include <algorithm>

using namespace std;  

const int Maxn = 510;

int n, s;
char num[Maxn];

int main() {
    cin >> n >> num;
	sort(num, num + n);
    do {  
        for(int i = 0; i < n; ++i) printf("%c", num[i]);
		cout << endl; ++s;
    }while(next_permutation(num,num+n)); 
	cout << s << endl; 
	// for(;;);
    return 0;  
}  
