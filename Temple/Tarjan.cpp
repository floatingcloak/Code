


void Tarjan(int u) {
	dfn[u] = ++tim; low[u] = tim;
	ins[u] = 1; s[++top] = u;
	for(int i = h[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] = low[u]) {
		int t = 0; ++cnt;
		while(t != u) {
			t = s[top--];
			a[cnt][++sum[cnt]] = t;
			bel[t] = cnt;
			ins[t] = 0;
		}
	}
}