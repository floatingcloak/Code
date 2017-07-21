#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
//Kill Ant!!!
//     ---sssSSSay
#define INF 100000007
#define Make make_pair

using namespace std;

const int Maxn = 11100;

typedef pair<double,double> P;

vector <int> Ant;

struct node {int hp,le,age,x,y,px,py,inhp;}ant[Maxn];
struct noda {int x,y;}tur[Maxn];

bool vis[100][100];//Update 2017/3/15 11:27 Shit!!!This is Bool???No It is Int(╯‵□′)╯︵┻━┻ 
int n,m,s,d,r,T,Judge,SumAnt,NumAnt,map[100][100],cnt;
int dx[5] = {0,0,1,0,-1};
int dy[5] = {0,1,0,-1,0};

int Dis(int x1,int y1,int x2,int y2){return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));}

P CalInt(int x1,int y1,int x2,int y2,int x0,int y0){
	if(x1 == x2)return Make((double)x1,(double)y0);
	if(y1 == y2)return Make((double)x0,(double)y1);
	double k1 = (double)(y1 - y2) / (double)(x1 - x2),b1 = (double)y1 - k1 * (double)x1;
	double k2 = -1.0 / k1,b2 = (double)y0 - k2 * (double)x0;
	P Temp;Temp.first = (b2 - b1) / (k1 - k2);Temp.second = k1 * Temp.first + b1;
	return Temp;
}

double CalDis(int x1,int y1,int x2,int y2,int x0,int y0){
	double k = (double)(y1 - y2) / (double)(x1 - x2),b = (double)y1 - (double)k * x1,x = (double)x0,y = (double)y0;
	return (fabs(k * x - y + b)) / (sqrt(k * k + 1.0));
}

bool BeHit2(int x1,int y1,int x2,int y2,int x0,int y0){//检查 
	if(x1 == x0 && y1 == y0)return true;
	P w = CalInt(x1,y1,x2,y2,x0,y0);
	if(x1 == x2){
		if(y0 >= min(y1,y2) && y0 <= max(y1,y2))return fabs((double)x0 - (double)x1) <= 0.5;
		else return false;	
	}
	if(y1 == y2){
		if(x0 >= min(x1,x2) && x0 <= max(x1,x2))return fabs((double)y0 - (double)y1) <= 0.5;
		else return false;	
	}
	double k = (double)(y1 - y2) / (double)(x1 - x2);
	if(x0 >= min(x1,x2) && x0 <= max(x1,x2) && y0 >= min(y1,y2) && y0 <= max(y1,y2)){
		return CalDis(x1,y1,x2,y2,x0,y0) <= 0.5;
	}
	else return false;
}

int main(){
	freopen("antbuster_ex.in","r",stdin);
	freopen("antbuster_ex.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&s,&d,&r);
	for(int i = 1;i <= s;++i){
		scanf("%d%d",&tur[i].x,&tur[i].y);
		vis[tur[i].x][tur[i].y] = 1;	
	}
	scanf("%d",&T);int Over = 0,S = 0;
	while(T--){int GameOver = 0;++S;
		if(Ant.size() < 6 && !vis[0][0]){//如果少于5只且0，0可以放就放一只 
			vis[0][0] = 1;
			ant[++SumAnt].x = ant[SumAnt].y = 0;ant[SumAnt].le = (SumAnt - 1)/ 6 + 1;
			ant[SumAnt].px = ant[SumAnt].py = 0;ant[SumAnt].hp = 4.0 * pow(1.1,ant[SumAnt].le);
			ant[SumAnt].inhp = ant[SumAnt].hp;
			ant[SumAnt].age = 1;Ant.push_back(SumAnt);
		}
		int tem = Ant.size();
		for(int i = 0;i < tem;++i){//留下信息素 
			int v = Ant[i];
			if(Judge == v) map[ant[v].x][ant[v].y] += 5;
			else map[ant[v].x][ant[v].y] += 2;
		}
		for(int i = 0;i < tem;++i){//给每一只蚂蚁确定走的方向 
			int v = Ant[i],k = -1,Max = -1;
			for(int j = 1;j <= 4;++j){
				int xx = ant[v].x + dx[j],yy = ant[v].y + dy[j];
				if(xx >= 0 && xx <= n && yy >= 0 && yy <= m && !vis[xx][yy] && 
				(xx != ant[v].px || yy != ant[v].py)){
					if(map[xx][yy] > Max){Max = map[xx][yy];k = j;}
				}
			}
			if(k != -1){//如果有一个地方可以走 
				if(ant[v].age % 5 == 0){//特殊地，如果时间是5的倍数就逆时针转 
					for(int j = 1;j <= 4;++j){
						--k;if(k == 0)k = 4;
						int xx = ant[v].x + dx[k],yy = ant[v].y + dy[k];
						if(xx >= 0 && xx <= n && yy >= 0 && yy <= m && !vis[xx][yy] && ((xx != ant[v].px || yy != ant[v].py) || (ant[v].x == ant[v].px && ant[v].y == ant[v].py))){
							break;
						}
					} 
				}//转到一个地方 
				int xx = ant[v].x + dx[k],yy = ant[v].y + dy[k];
				vis[xx][yy] = 1;vis[ant[v].x][ant[v].y] = 0;
				ant[v].px = ant[v].x;ant[v].py = ant[v].y;
				ant[v].x = xx;ant[v].y = yy;
			}
			else {//如果没有 
				ant[v].px = ant[v].x;ant[v].py = ant[v].y;	
			}
		} 
		for(int i = 0;i < tem;++i){int v = Ant[i];
			if(!Judge && ant[v].x == n && ant[v].y == m){//检查是否背上蛋糕
				int St = 4.0 * pow(1.1,ant[v].le);
				Judge = v;ant[v].hp = ant[v].hp + St / 2;
				if(ant[v].hp > St)ant[v].hp = St;
			}
		}
		//s是坦克的数量
		for(int i = 1;i <= s;++i){//Update 2017/3/15 10:19 Clearly There Is Mistake
			//Update 2017/3/15 10:39 Approve In R
			int nx = tur[i].x,ny = tur[i].y,tar = -INF,Min = INF,kk = -1;
			for(int j = 0;j < tem;++j){//Update 2017/3/15 17:07 After DeBug I Know This is Wrong
				int v = Ant[j],xx = ant[v].x,yy = ant[v].y;
				int dis = Dis(nx,ny,xx,yy);
				if(dis <= r * r) {//如果炮塔可以打到这个蚂蚁 
					if(Judge != 0 && Judge == v){//检查是否有扛着蛋糕的蚂蚁 
						tar = Judge;
						break;
					}
					if(dis < Min){//没有的话找最近的 
						tar = v;
						Min = dis;
						kk = j;
					}
				}
			}
			if(tar != -INF){//找到了一个目标 
				int xx = ant[tar].x,yy = ant[tar].y;
				for(int j = 0;j < tem;++j){
					int v = Ant[j];
					if(BeHit2(xx,yy,nx,ny,ant[v].x,ant[v].y) && Dis(nx,ny,ant[v].x,ant[v].y) <= r * r){//检查能够被打到的 
						ant[v].hp -= d;//Update 2017/3/15 17:18 Oh!!!All Tur Must Attach The Same Time\(≧▽≦)/ 
					}
				}
			}
		}
		for(int i = 0;i < tem;++i){int v = Ant[i];
			if(ant[v].hp < 0){//消除死掉的蚂蚁 
				vis[ant[v].x][ant[v].y] = 0;
				Ant.erase(Ant.begin() + i);//Update 2017/3/15 11:20 Boom ShaKaLaKa!!!!!
				tem = Ant.size();//Update 2017/3/15 11:24 Should CalIt Again
				if(Judge == v)Judge = 0; --i;
			}
		}
		for(int i = 0;i < tem;++i){
			int v = Ant[i];
			if(Judge == v && ant[v].x == 0 && ant[v].y == 0){GameOver = 1;break;}
		}if(GameOver == 1){Over = 1;break;}//结束的标志 
		for(int i = 0;i <= n;++i){
			for(int j = 0;j <= m;++j)if(map[i][j] >= 1)--map[i][j];	//信息素减一 
		}
		for(int i = 0;i < tem;++i){
			int v = Ant[i];++ant[v].age;//年龄加一 
		}
	}
	
	if(Over == 1)printf("Game over after %d seconds\n",S);
	else puts("The game is going on\n");
	int t = Ant.size();printf("%d\n",t);
	for(int i = 0;i < t;++i){int v = Ant[i];
		printf("%d %d %d %d %d\n",ant[v].age - 1,ant[v].le,ant[v].hp,ant[v].x,ant[v].y);
	}
	return 0;
}
