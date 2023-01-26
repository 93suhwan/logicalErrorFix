#include <bits/stdc++.h>
 
#define R register
#define ll long long
#define inf 1ll << 55
#define PII std::pair<int,int>
#define db double
 
using std::max;
using std::min;
using std::cout;
using std::cin;
using std::endl;
inline int read() {
	R int x = 0, f = 1;
	R char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1; c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
	return f * x;
}

int T, n, m, cnt, st[1010], a[1010], b[1010], nowpo, pre[1010], fail, hd[1010], tot;

struct node {
	int to, nxt;
}E[4010];

inline void adde(int u, int v) {
	E[++tot].to = v; E[tot].nxt = hd[u]; hd[u] = tot;
}
void dfs(int u, int now, int lst) {
	now = std::min(now, 1000000001);
	if (!fail) return;
	pre[u] = lst;
	for (R int i = hd[u]; i; i = E[i].nxt) {
		int v = E[i].to; 
		if (v == lst) continue;
		if (st[v] && !st[u]) {
			fail = 0;
			while (!st[u]) {
				st[u] = 1; cnt ++; u = pre[u];
			}
			nowpo = now;
			return;
		}
		else if (pre[v] && !st[u]) {
			fail = 0;
			while (!st[u]) {
				st[u] = 1; cnt ++; u = pre[u];
			}
			while (!st[v]) {
				st[v] = 1; cnt ++; v = pre[v];
			}
			nowpo = now;
			return;	
		}
		
		else if (now > a[v] && !st[v]) dfs(v, now + b[v], u);
	}
}
bool zengguang() {
	fail = 1;
	for (R int i = 1; i <= n; i ++) pre[i] = 0;
	for (R int i = 1; i <= n; i ++) {
		if (!st[i]) continue;
		dfs(i, nowpo, 0);
		if (!fail) return 1;
	}
	return 0;
} 
bool check(int force) {
	cnt = 1;
	nowpo = force;
	for (R int i = 1; i <= n; i ++) st[i] = 0;
	st[1] = 1;
	while (1) {
		if (cnt == n) return 1;	
		if (!zengguang()) return 0;
	}
}
void sol() {
	n = read(); m = read();
	for (R int i = 2; i <= n; i ++) a[i] = read();
	for (R int i = 2; i <= n; i ++) b[i] = read();
	memset(hd, 0, sizeof(hd));
	for (R int i = 1; i <= tot; i ++) E[i].to = E[i].nxt = 0;
	tot = 0; 
	for (R int i = 1; i <= m; i ++) {
		R int u = read(), v = read();
		adde(u, v); adde(v, u);
	}
	R int l = 1, r = 1e9 + 7;
	while (l < r) {
		R int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << "\n";
}
int main() {
	T = read();
	while (T --) sol();
	return 0;
}