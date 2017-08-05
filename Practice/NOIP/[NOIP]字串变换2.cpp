#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct node {string str;int step;};

queue <node> Q;

map <string, bool> hs;

int n = 1;
string a[10], b[10], str1, str;

int main() {
	// freopen("string.in", "r", stdin);
	// freopen("string.out", "w", stdout);
    cin >> str >> str1;
    Q.push((node){str, 0}); hs[str] = 1;
    while(cin >> a[n] >> b[n]){ ++n;} n--;
    while(!Q.empty() && Q.front().step < 10){
        string temp = Q.front().str;
		int s = Q.front().step; Q.pop();
        for(int k = 1; k <= n; k++){
            int len = temp.size();
            for(int i = 0;i < len; i++){
                if(temp.compare(i, a[k].size(), a[k]) == 0){
					string ww = temp;
                    string ss = ww.replace(i, a[k].size(), b[k]);
                    if(!hs[ss]) {
						Q.push((node){ss, s + 1});
						hs[ss] = 1;
					}
                    if(ss == str1){
                        cout << s + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    printf("NO ANSWER!");
	return 0;
}
