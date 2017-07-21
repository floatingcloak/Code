void Sa(int n, int m) {
	int *x = t1, *y = t2, i, p;
	for(i = 0; i < m; ++i) c[i] = 0;
	for(i = 0; i < n; ++i) ++c[x[i] = s[i]];
	for(i = 1; i < m; ++i) c[i] += c[i - 1];
	for(i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for(int k = 1; k <= n; k <<= 1) {
		p = 0;
		for(i = n - k; i < n; ++i) y[p++] = i;
		for(i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
		for(i = 0; i < m; ++i) c[i] = 0;
		for(i = 0; i < n; ++i) ++c[x[y[i]]];
		for(i = 1; i < m; ++i) c[i] += c[i - 1];
		for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] =y[i];
		swap(x, y); x[sa[0]] = 0; p = 1;
		for(i = 1; i < n; ++i) {
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p - 1 : p++;
		}
		m = p; if(p >= n) break;
	}
}

inline void Get() {
	int k = 0;
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 0, j; i < n; he[rank[i++]] = k)
		for(k = k ? k - 1 : k, j = sa[rank[i]- 1]; rank[i] != 1 && s[i + k] == s[j + k]; ++k);
}


void Sa(int n, int m) {
	int *x = t1, *y = t2, i, p;
	for(i = 0; i < m; ++i) c[i] = 0;
	for(i = 0; i < n; ++i) ++c[x[i] = s[i]];	
	for(i = 1; i < m; ++i) c[i] += c[i - 1];
	for(i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for(int k = 1; k <= n; k <<= 1) {
		p = 1;
		for(i = n - k; i < n; ++i) y[p++] = i;
		for(i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
		for(i = 0; i < m; ++i) c[i] = 0;
		for(i = 0; i < n; ++i) ++c[x[y[i]]];
		for(i = 1; i < m; ++i) c[i] += c[i - 1];
		for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x, y); x[sa[0]] = 0; p = 1;
		for(i = 1; i < n; ++i) {
			x[sa[i]] = (y[sa[i]] == y[sa[i] - 1] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p - 1 : p++;	
		} m = p; if(p >= n) break;
	}
}

void Get() {
	int k = 0;
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 0, j; i < n; he[rank[i++]] = k)
		for(k ? k - 1 : k, j = sa[rank[i] - 1]; rank[i] != 1 && s[i + k] == s[j + k]; ++k);	
}


void Sa(int n, int m) {
	int *x = t1, *y = t2, i, p;
	for(i = 0; i < m; ++i) c[i] = 0;
	for(i = 0; i < n; ++i) ++c[x[i] = s[i]];	
	for(i = 1; i < m; ++i) c[i] += c[i - 1];
	for(i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for(int k = 1; k <= n; k <<= 1) {
		p = 1;
		for(i = n - k; i < n; ++i) y[p++] = i;	
		for(i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
		for(i = 0; i < m; ++i) c[i] = 0;
		for(i = 0; i < n; ++i) ++c[x[y[i]]];
		for(i = 1; i < m; ++i) c[i] += c[i - 1];
		for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x, y); p = 1; x[sa[0]] = 0;
		for(i = 1; i < n; ++i) {
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p - 1 : p++;
	
		}m = p; if(p >= n) break;
	}
}

void Get() {
	int k = 0;
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 0, j; i < n; he[rank[i++]] = k) {
		for(k ? k - 1 : k, j = sa[rank[i] - 1]; rank[i] != 1 && sa[i + k] == sa[j + k]; ++k);
	}
}



void Sa(int n, int m) {
	int *x = t1, *y = t2, i ,p;
	for(i = 0; i < m; ++i) c[i] = 0;
	for(i = 0; i < n; ++i) ++c[x[i] = s[i]];
	for(i = 1; i < m; ++i) c[i] += c[i - 1];
	for(i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for(int k = 1; k <= n; k <<= 1) {
		p = 1;
		for(i = n - k; i < n; ++i) y[p++] = i;
		for(i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
		for(i = 0; i < m; ++i) c[i] = 0;
		for(i = 0; i < n; ++i) ++c[x[y[i]]];
		for(i = 1; i < m; ++i) c[i] += c[i - 1];
		for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x, y); p = 1; x[sa[0]] = 0;
		for(i = 1; i < n; ++i) {
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p - 1 : p++;
		} m = p; if(p >= n) break;
	}
}

void Get() {
	int k = 0;
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 0, j; i < n; he[rank[i++]] = k) {
		for(k ? k - 1 : k, j = sa[rank[i] - 1]; rank[i] != 1 && s[i + k] == s[j + k]; ++k);
	}
}



















































