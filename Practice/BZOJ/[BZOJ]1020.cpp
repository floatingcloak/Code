#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1000000005
#define eps 1e-6
#define Make make_pair

using namespace std;

typedef pair<double,double> P;

struct node {double v[3],u[3],k,b;}e[30010];
struct nodc {double x[40],y[40];}G[40];
struct noda {double v[3],u[3],k,b;}Ge[30010];

int T,n,c,tot,cnt,m,l[40],r[40];P L;
int Q[30100];
double Res = 0.0;

bool Comp(double q,double w){
	if(fabs(q - w) <= 1e-6)return 1;
	else return 0;	
}

P CalLen(int k,double l){return Make((e[k].u[0] + l * L.first),(e[k].u[1] + l * L.second));}

P GetMid(int k){return Make((e[k].u[0] + e[k].v[0]) / 2,(e[k].u[1] + e[k].v[1]) / 2);}

P CalMag(int k){return Make((e[k].v[0] - e[k].u[0]),(e[k].v[1] - e[k].u[1]));}

double Dis(P a,P b){
	double x1 = a.first,x2 = b.first,y1 = a.second,y2 = b.second;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool OnLine(int x,P aa,int p){double x0 = aa.first,y0 = aa.second;
	double xx1 = p == 1 ? Ge[x].u[0] : e[x].u[0],xx2 = p == 1 ? Ge[x].v[0] : e[x].v[0];
	double yy1 = p == 1 ? Ge[x].u[1] : e[x].u[1],yy2 = p == 1 ? Ge[x].v[1] : e[x].v[1];
	if(yy1 > yy2){swap(yy1,yy2);swap(xx1,xx2);}
	if(xx1 == xx2 && y0 >= yy1 && y0 <= yy2 && x0 == xx1)return 1;
	double k1 = p == 1 ? Ge[x].k : e[x].k,b1 = p == 1 ? Ge[x].b : e[x].b;
	if(fabs(k1 * x0 + b1 - y0) > eps)return 0;
	if(k1 >= 0 && x0 >= xx1 && x0 <= xx2 && y0 >= yy1 && y0 <= yy2)return 1;
	if(k1 < 0 && x0 >= xx2 && x0 <= xx1 && y0 >= yy1 && y0 <= yy2)return 1;
	return 0;
}

P CalInt(int k,P a){//This Is A Mistake!!! Update 2017/3/7 11:38 About...This is Right
	//Update 2017/3/10 20:04 Oh...Why Did Not Me Judge If Point On Line???(¨s¨F¡õ¡ä)¨s¦à©ß©¥©ß
	//Update 2017/3/10 20:08 Oh Yeah It is Really Right
	double x1 = Ge[k].u[0],y1 = Ge[k].u[1],x2 = Ge[k].v[0],y2 = Ge[k].v[1];
	double x0 = a.first , y0 = a.second;
	if(x1 == x2)return Make(x1,y0);
	if(y1 == y2)return Make(x0,y1);
	double k1 = (y1 - y2) / (x1 - x2),b1 = y1 - k1 * x1;
	double k2 = -1.0 / k1,b2 = y0 - k2 * x0;
	P Temp;Temp.first = (b2 - b1) / (k1 - k2);Temp.second = k1 * Temp.first + b1;
	return Temp;
}

P QAQInt(int k,P a){
	double x1 = Ge[k].u[0],y1 = Ge[k].u[1],x2 = Ge[k].v[0],y2 = Ge[k].v[1];
	double x0 = a.first , y0 = a.second;
	if(x1 == x2){
		if(y0 >= y1 && y0 <= y2)return Make(x1,y0);
	}
	double k1 = (y1 - y2) / (x1 - x2),b1 = y1 - k1 * x1;
	double k2 = -1.0 / k1,b2 = y0 - k2 * x0;
	P Temp;Temp.first = (b2 - b1) / (k1 - k2);Temp.second = k1 * Temp.first + b1;
	if(OnLine(k,Temp,1))return Temp;
	else {
		if(Dis(a,Make(x1,y1)) < Dis(a,Make(x2,y2)))return Make(x1,y1);
		else return Make(x2,y2);	
	}
}

double CalDis(int t,P c){//Update 2017/3/10 20:14 Shit!This is A MisTake!
	double x0 = c.first,y0 = c.second;
	double x1 = Ge[t].u[0],y1 = Ge[t].u[1],x2 = Ge[t].v[0],y2 = Ge[t].v[1];
	if(x1 == x2){
		if(y0 >= y1 && y0 <= y2)return fabs(x1 - x0);
		else return min( Dis(Make(x1,y1),c) , Dis(Make(x2,y2),c) );
	}
	double k = (y1 - y2) / (x1 - x2),b = y1 - k * x1,x = c.first,y = c.second;
	P r = CalInt(t,c);
	if(OnLine(t,r,1)){return (fabs(k * x - y + b)) / (sqrt(k * k + 1.0));}
	else return min( Dis(Make(x1,y1),c) , Dis(Make(x2,y2),c) );
}

bool InG(int k,P a){double x = a.first,y = a.second;int res = 0;
	for(int i = l[k];i <= r[k];i++){
		double x1 = Ge[i].u[0],y1 = Ge[i].u[1];
		double x2 = Ge[i].v[0],y2 = Ge[i].v[1],kk = Ge[i].k,bb = Ge[i].b;
		if(y1 > y2){swap(x1,x2);swap(y1,y2);}
		if(OnLine(i,a,1))return 1;
		if(y1==y2 && y2 == y)continue;
		bool p = (kk > 0 && kk * x + bb > y) || (kk < 0 && kk * x + bb < y) || (Ge[i].u[0] == Ge[i].v[0] && Ge[i].u[0] <= x);
		if(y >= y1 && y <= y2 && y != y1 && p)res += 1;
	}
	return res % 2 == 1;
}

P CalMin(P x,P &X,double &y){//Update 2017/3/10 21:05 Again Wrong (three times)
	int kk = 0;
	for(int i = 1;i <= cnt;i++){
		P W = CalInt(i,x);
		if(CalDis(i,x) < y){
			y = CalDis(i,x);
			X = QAQInt(i,x);
		}
	}
}

P CalLineInt(int x,int w){
	double k1 = e[x].k,k2 = Ge[w].k;
	double b1 = e[x].b,b2 = Ge[w].b;
	if(e[x].u[0] == e[x].v[0]){
		P Temp;Temp.first = e[x].u[0];Temp.second = Temp.first * k2 + b2;
		return Temp;
	}
	if(Ge[w].u[0] == Ge[w].v[0]){
		P Temp;Temp.first = Ge[w].u[0];Temp.second = Temp.first * k1 + b2;	
	}
	P Temp;Temp.first = (b2 - b1) / (k1 - k2);Temp.second = Temp.first * k1 + b1;
	return Temp;
}

bool InLine(int w,int x){
	for(int i = l[w];i <= r[w];i++){
		if(Ge[i].k == e[x].k)continue;
		P Int = CalLineInt(x,i);double xx = Int.first;double yy = Int.second;
		if(OnLine(i,Int,1) && OnLine(x,Int,0)){
			return 1;
		}
	}
	return 0;
}

void CalAns(double &ans,P x){
	for(int i = 1;i <= c;i++)if(InG(i,x)){ans = 0.0;return;}
	for(int i = 1;i <= cnt;i++)ans = min(ans,CalDis(i,x));
}

int main(){
//	freopen("flightsafety.in","r",stdin);
//	freopen("flightsafety.out","w",stdout);
//	scanf("%d",&T);
//	while(T--){
		int h = 1,t = 0;
		tot = 0,cnt = 0;Res = 0.0;
	    scanf("%d%d",&c,&n);double x1,y1;
	    for(int i = 1;i <= n;i++){
	    	double x,y;scanf("%lf%lf",&x,&y);
	    	if(i != 1){
	    		e[++tot].u[0] = x1;e[tot].u[1] = y1;
	    		e[tot].v[0] = x;e[tot].v[1] = y;
	    	}x1 = x;y1 = y;
	    }
	    
	    for(int i = 1;i <= c;i++){
	    	scanf("%d",&m);
			double x1,y1;l[i] = cnt + 1;
	    	for(int j = 1;j <= m;j++){
	    		scanf("%lf%lf",&G[i].x[j],&G[i].y[j]);
	    		if(j != 1){Ge[++cnt].u[0] = x1;Ge[cnt].u[1] = y1;
	    			Ge[cnt].v[0] = G[i].x[j];Ge[cnt].v[1] = G[i].y[j];
	    		}x1 = G[i].x[j];y1 = G[i].y[j];
	    	}Ge[++cnt].u[0] = G[i].x[m];Ge[cnt].u[1] = G[i].y[m];r[i] = cnt;
	    	Ge[cnt].v[0] = G[i].x[1];Ge[cnt].v[1] = G[i].y[1];
	    }
	    
	    for(int i = 1;i <= cnt;i++){
	    	double x1 = Ge[i].u[0],y1 = Ge[i].u[1];
	    	double x2 = Ge[i].v[0],y2 = Ge[i].v[1];
	    	if(y1 > y2){swap(Ge[i].u[1],Ge[i].v[1]);swap(Ge[i].u[0],Ge[i].v[0]);}
	    	Ge[i].k = (y2 - y1) / (x2 - x1);
	    	Ge[i].b = y1 - x1 * Ge[i].k;	
	    }
	    
	    for(int i = 1;i <= tot;i++){int pd = 0;
	    	P a;a.first = e[i].u[0];a.second = e[i].u[1];
	    	P b;b.first = e[i].v[0];b.second = e[i].v[1];
	    	e[i].k = (b.second - a.second) / (b.first - a.first);
	    	e[i].b = a.second - a.first * e[i].k;
	    	for(int j = 1;j <= c;j++)if(InG(j,a) && InG(j,b) && !InLine(j,i)){pd = 1;break;}
	    	if(!pd){Q[++t] = i;}
		}
	    while(h <= t){
			int now = Q[h];
	    	P a,A;a.first = e[now].u[0],a.second = e[now].u[1];double xa = INF;
	    	P b,B;b.first = e[now].v[0],b.second = e[now].v[1];double xb = INF;
	    	for(int i = 1;i <= c;i++)if(InG(i,a)){xa = 0;A = a;break;}
	    	for(int i = 1;i <= c;i++)if(InG(i,b)){xb = 0;B = b;break;}
	    	if(xa == INF)CalMin(a,A,xa);
			if(xb == INF)CalMin(b,B,xb);
	    	double ans = 0.0;
	    	P L,R,Mid;
			L.first = a.first;L.second = a.second;
			R.first = b.first;R.second = b.second;
	    	while(Dis(L,R) > eps){
	    		Mid.first = (L.first + R.first) / 2.0;
				Mid.second = (L.second + R.second) / 2.0;
	    		if(Dis(Mid,A) > Dis(B,Mid))R = Mid;
	    		else L = Mid;
	    	}
	    	double ll = max(Dis(Mid,A),Dis(Mid,B));
			if(ll > Res + eps){
		    	P C;C.first = (a.first + b.first) / 2.0;C.second = (a.second + b.second) / 2.0;
		    	ans = INF;CalAns(ans,C);
				Res = max(ans,Res);
			    e[++tot].u[0] = e[now].u[0];e[tot].u[1] = e[now].u[1];
			    e[tot].v[0] = C.first;e[tot].v[1] = C.second;Q[++t] = tot;
			    if(t == 21000)t = 1;
			    e[++tot].u[0] = C.first;e[tot].u[1] = C.second;
			    e[tot].v[0] = e[now].v[0];e[tot].v[1] = e[now].v[1];
			    Q[++t] = tot;if(t == 21000)t = 1;
	    	}h++;if(h == 21000)h = 1;
	    }
		printf("%.2lf\n",Res);
//	}
	return 0;
}
