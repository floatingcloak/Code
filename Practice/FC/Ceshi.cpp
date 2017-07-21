#include<iostream>
#include<windows.h>

using namespace std;

int main() {
    while(1) {
        system("data > test.in");
        system("1245Force < test.in > ans.out");
        system("[CODEVS]1245 < test.in > my.out");
        if(system("fc my.out ans.out")) break;
	}
    return 0;
}
