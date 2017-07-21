void Insert(){
	int len = strlen(s),u = 0;
	for(int i = 0;i < len;i++){int v = s[i] - 64;
		if(ch[u][v] == 0)ch[u][v] = ++tot;
		u = ch[u][v];
	}vis[u] = 1;
}

void Build(){
	for(int i = 1;i <= 26;i++)if(ch[0][i] > 0)Q.push(ch[0][i]);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		vis[u] |= vis[f[u]];
		for(int i = 1;i <= 26;i++){
			int v = ch[u][i];
			if(v > 0){
				f[v] = ch[f[u]][i];
				Q.push(v);
			}
			else ch[u][i] = ch[f[u]][i];
		}
	}
}
