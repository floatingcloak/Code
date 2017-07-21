void Link(int u,int v,int c,int w) {
	e[++tot].to = v;
	e[tot].next = h[u];
	e[tot].cap = c;
	e[tot].val = w;
	h[u] = tot;	
}

void Add(int u,int v,int c,int w) {
	Link(u,v,c,w);
	Link(v,u,0,-w);	
}

int Bfs() {
	queue <int> Q;
	for(int i = S; i <= T; ++i) {
		dis[i] = -INF; vis[i] = 0;
	}
	dis[S] = 0; Q.push(S); vis[S] = 1;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = 0;
		for(int i = h[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[v] < dis[u] + e[i].val && e[i].cap) {
				dis[v] = dis[u] + e[i].val;
				if(!vis[v]) {
					vis[v] = 1;
					Q.push(v);	
				}
			}
		}
	}
	return dis[T] != -INF;
}

int Mcmf() {
	int temp = 0;
	while(Bfs()) {
		int s = INF;
		for(int j = pre[T]; j; j = pre[e[j ^ 1].to]) s = min(s, e[j].cap);
		for(int j = pre[T]; j; j = pre[e[j ^ 1].to]) e[j].cap -= s, e[j ^ 1].cap += s;
		temp += s * dis[T];
	}
	return temp;
}
