#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
//向量用来计算两条直线的关系对于精度来说比较优
//sssSSSay 
#define INF 1e11
#define eps 1e-4

using namespace std;

const int Maxn = 510;

int x[Maxn],y[Maxn],n;
double res = INF,pos;

struct node {
	double x1,x2,y1,y2,k,b;
	void Get(){
		k = x1 == x2 ? INF : (y2 - y1) / (x2 - x1);
		b = y1 - k * x1;
	}
}e[Maxn];

double Rand() {return rand() % 1000 / 1000.0;}

bool Comp(double a,double b) {
	return fabs(a - b) < eps;
}	

bool Check(double x0,double y0) {
	for(int i = 2; i <= n; ++i) {
		double x1 = x[i - 1],y1 = y[i - 1];
		double x2 = x[i],y2 = y[i];
		double x3 = x1 - x0,y3 = y1 - y0;
		double x4 = x2 - x0,y4 = y2 - y0;
		if(x3 * y4 - x4 * y3 < 0)return 0;//向量夹角 
	}
	return 1;
}

double Cal(double x) {
	double kk = 0;
	for(int i = 1; i < n; ++i) {
		if(x >= e[i].x1 && x <= e[i].x2) {
			kk = x * e[i].k + e[i].b;
			break;
		}
	}
	double l = 0,r = INF,mid = (l + r) / 2.0;
	while(r - l > 1e-5) {
		if(Check(x,mid)) r = mid;
		else l = mid;
		mid = (l + r) / 2.0;
	}
//	cout<<kk<<endl;
	mid -= kk;
	if(mid < res){
		res = mid;
		pos = x;	
	}
	return mid;
}

void Fire(double S) {
	double now = pos;
	for(;S > 0.00001;S *= 0.99) {
//		cout<<now<<endl;
		double nov = now + S * (Rand() * 2 - 1);
		if(nov < x[1] || nov > x[n]) continue;
		double temp = Cal(now) - Cal(nov);
		if(temp > 0 || exp(temp/S) > Rand()) now = nov;
	}
	for(int i = 1; i <= 1000; ++i) {
		double nov = now + S * (Rand() * 2 - 1);
		if(nov < x[1] || nov > x[n]) continue;
		Cal(nov);
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) scanf("%d",&x[i]);
	for(int i = 1; i <= n; ++i) scanf("%d",&y[i]);
	for(int i = 1; i < n; ++i) {
		e[i].x1 = (double)x[i];
		e[i].y1 = (double)y[i];
		e[i].x2 = (double)x[i + 1];
		e[i].y2 = (double)y[i + 1];
		e[i].Get();
	}
	pos = (double)(x[1] + x[n] >> 1);
	Fire((double)(x[n] - x[1]));
	printf("%.3lf\n",res);
//	cout<<pos<<endl;
	return 0;
}
