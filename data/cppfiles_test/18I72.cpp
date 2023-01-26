#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int M = 1e6 + 10;
int t, n, m, d;
int deg[N], head[N], nexts[M], ver[M], cnt = 0;
void add(int x, int y) {
	deg[y] ++;
	ver[++ cnt] = y, nexts[cnt] = head[x], head[x] = cnt;
}
bool a[N];
bool vis[N];
int dis[N];
signed main() {
	cin >> t;
	while(t --) {
		cin >> n >> d;
		vector<int> w;
		w.clear();
		for(int i = 1; i <= n; i ++)
			vis[i] = 0;
		for(int i = 0; i < n; i ++)
			cin >> a[i]; 
		for(int i = 0; i < n; i ++) {
			if(a[i]) w.push_back(i + 1);
			if(a[i] && a[(i + n - d) %n]) add(i + 1, (i + n - d) % n + 1);
		}
		queue<int> q;
		for(int i = 0; i < w.size(); i ++) {
			if(!deg[w[i]]) {
				vis[w[i]] = 1;
				q.push(w[i]);
			}
		}
		for(int i = 1; i <= n;i ++)
			dis[i] = 1;
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int i = head[x]; i; i = nexts[i]) {
				int v = ver[i];
				deg[v] --;
				dis[v] = max(dis[v], dis[x] + 1);
				if(!deg[v]) vis[v] = 1, q.push(v);
			}
		}
		int flag = 0;
		for(int i = 0; i < w.size(); i ++) {
			if(!vis[w[i]]) flag = 1;
		}
		if(flag) puts("-1");
		else {
			for(int i = 0; i < w.size(); i ++)
				flag = max(flag, dis[w[i]]);
			cout << flag << endl;
		}
	}
	return 0;
}


