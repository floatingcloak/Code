#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 13;

int A,B,a[Maxn],f[Maxn][10][2][2];

int Abs(int w){return w >= 0 ? w : -w;}

int Solve(int XD){int m = 0;
	while(XD){
		a[m++] = XD % 10;
		XD /= 10;
	}
	reverse(a, a + m);//123 = 1 2 3
	memset(f,0,sizeof(f));
	f[0][0][1][1] = 1; // Ŀǰ�Ѿ�������iλ �����һλ��j ǰ���Ƿ����Ͻ�k ǰ���Ƿ�ȫ��l 
	for(int i = 0; i < m; i++){ // ���� 
		for(int j = 0; j <= 9; j++){ // ö����һλ 
			for(int k = 0; k <= 1; k++){ // ǰ���Ƿ����Ͻ�
				for(int l = 0; l <= 1; l++){ // ǰ���Ƿ�ȫ�� 
					int lim = k ? a[i] : 9; // ö�ٵ��Ͻ� 
					if(l == 1){ // ȫ��ֱ���� 
						for(int d = 0; d <= lim; d++)f[i + 1][d][k && d == lim][l && d == 0] += f[i][j][k][l];
					}
					else { // ����ȫ�յĻ���Ҫ�ж�һ�� 
						for(int d = 0; d <= lim; d++)if(Abs(d - j) >= 2)f[i + 1][d][k && d == lim][0] += f[i][j][k][l];
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 1; j++){
			for(int k = 0; k <= 1; k++)ans += f[m][i][j][k]; // ������m���������з������	
		}
	}return ans;
}

int main(){
	scanf("%d%d",&A,&B);
	printf("%d\n",Solve(B) - Solve(A - 1));
	return 0;
}
