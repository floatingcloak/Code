#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 201000;

// char str[Maxn];
string str;
int res, al, ar;

bool Compare(char a, char b) {
    if(a >= 'A' && a <= 'Z') a += 32;
    if(b >= 'A' && b <= 'Z') b += 32;
    if(a == b) return true;
    else return false;
}

bool Judge(char a) {
    int pd1 = ((a >= 'a') && (a <= 'z')), pd2 = ((a >= 'A') && (a <= 'Z'));
    if(pd1 || pd2) return false;
    else return true;
}

char s[Maxn];
string temp;

int main() {
    str += '!';
    while(cin >> (temp)) {
        str += temp;
    }
    // gets(str + 1);
    int len = strlen(str + 1);
    // for(int i = 1; i <= len; ++i) printf("%c", str[i]);
    for(int i = 1; i <= len; ++i) {
        int l = i, r = i, ans = 0;
        while(l >= 1 && r <= len && Compare(str[l], str[r])) {
            --l; ++r; ++ans;
            while(Judge(str[l]) && l >= 1) --l;
            while(Judge(str[r]) && r <= len) ++r;
        }
        ++l; --r;
        while(Judge(str[l])) ++l;
        while(Judge(str[r])) --r;
        // printf("%c %d %d\n", str[i], l, r);
        ans = ans * 2 - 1;
        if(ans > res) {
            res = ans;
            al = l; ar = r;
        }
    }
    for(int i = 1; i < len; ++i) {
        if(str[i] == str[i + 1]) {
            int l = i, r = i + 1, ans = 1;
            while(l >= 1 && r <= len && Compare(str[l], str[r])) {
                --l; ++r; ++ans;
                while(Judge(str[l]) && l >= 1) --l;
                while(Judge(str[r]) && r <= len) ++r;
            }
            ++l; --r;
            while(Judge(str[l])) ++l;
            while(Judge(str[r])) --r;
            ans = ans * 2;
            if(ans > res) {
                res = ans;
                al = l; ar = r;
            }
        }
    }
    printf("%d\n", res);
    for(int i = al; i <= ar; ++i) cout << str[i];
    puts("");
    while(1);
    return 0;
}