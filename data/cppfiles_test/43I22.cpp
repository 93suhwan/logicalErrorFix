#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define pii pair<int, pi>
#define f first
#define s second

const int mxn = 200001, k = __lg(mxn) + 1;
int n, q;
int a[mxn], b[mxn], h[mxn], pp[mxn], rk[mxn], d[mxn], p[k][mxn], f[k][mxn];
int ee[mxn], ea[mxn], eb[mxn], ec[mxn], ed[mxn], qq[mxn], qa[mxn], qb[mxn];
int fa[mxn], fb[mxn];
vector<int> g[mxn];

int fnd(int x){ return x == pp[x] ? x : pp[x] = fnd(pp[x]);}

void dfs(int c){
	for(int i = 1; i < k; i++){
		p[i][c] = p[i - 1][p[i - 1][c]];
		f[i][c] = max(f[i - 1][c], f[i - 1][p[i - 1][c]]);
	} 
	for(int i : g[c]){
		int x = c ^ ea[i] ^ eb[i];
		if(x != p[0][c]) d[x] = d[c] + 1, p[0][x] = c, f[0][x] = ed[i], dfs(x);
	}
}

void up(int x, int &y, int &z){ z = max(z, f[x][y]), y = p[x][y];}

int ff(int x, int y){
	int z = 0;
	if(d[x] < d[y]) swap(x, y);
	for(int i = k - 1; ~i; i--) if(d[p[i][x]] >= d[y]) up(i, x, z);
	for(int i = k - 1; ~i; i--) if(p[i][x] != p[i][y]) up(i, x, z), up(i, y, z);
	if(x != y) up(0, x, z), up(0, y, z);
	return z;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++) cin >> a[i], b[i] = pp[i] = i;
	
	for(int i = 0; i < n - 1; i++){
		cin >> ea[i] >> eb[i] >> ec[i] >> ed[i];
		ee[i] = i;
		g[ea[i]].push_back(i);
		g[eb[i]].push_back(i);
	}
	
	d[0] = -1;
	dfs(1);

	for(int i = 0; i < q; i++) cin >> qa[i] >> qb[i], qq[i] = i;
	
	sort(ee, ee + n - 1, [&](int x, int y){ return ec[x] > ec[y];});
	sort(qq, qq + q, [&](int x, int y){ return qa[x] > qa[y];});

	for(int i = 0, j = 0; i < q; i++){
		for(; j < n - 1 && ec[ee[j]] >= qa[qq[i]]; j++){
			int x = fnd(ea[ee[j]]), y = fnd(eb[ee[j]]);
			if(x != y){
				if(rk[x] < rk[y]) swap(x, y);
				rk[x] += rk[x] == rk[y], pp[y] = x;
				if(a[x] < a[y]) swap(a[x], a[y]), swap(b[x], b[y]);
				if(a[x] == a[y]) h[x] = max(h[x], ff(b[x], b[y]));
			}
		}
		int x = qq[i], y = fnd(qb[x]);
		fa[x] = a[y], fb[x] = max(h[y], ff(qb[x], b[y]));
	}
	
	for(int i = 0; i < q; i++) cout << fa[i] << " " << fb[i] << endl;
	
	return 0;
}