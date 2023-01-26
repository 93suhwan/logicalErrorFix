#include <bits/stdc++.h>
using namespace std;
int n, k, sum, root;
int a[200005], son[200005], f[200005], pp[200005];
vector<pair<int, int>> g[200005];
long long ans, num[2][200005], v[2][200005];
int lowbit(int x) { return x & -x; }
void add(long long v[], int x, long long y) {
  for (int i = x; i < 200005; i += lowbit(i)) {
    v[i] = (v[i] + y) % 1000000007;
  }
}
long long get(long long v[], int x) {
  long long res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    res = (res + v[i]) % 1000000007;
  }
  return res;
}
void getroot(int x, int fa) {
  son[x] = 1, f[x] = 0;
  for (auto p : g[x]) {
    int y = p.first;
    if (!pp[y] && y != fa) {
      getroot(y, x);
      son[x] += son[y];
      f[x] = max(f[x], son[y]);
    }
  }
  f[x] = max(f[x], sum - son[x]);
  if (f[x] < f[root]) root = x;
}
void dfs(int x, int fa, int rcol, int col, int nu, long long sum, int tp) {
  sum = (sum + a[x]) % 1000000007;
  if (tp == 0) {
    if (k >= nu) {
      long long cnt = get(num[rcol], k - nu + 1);
      long long now = get(v[rcol], k - nu + 1);
      ans = (ans + cnt * sum) % 1000000007;
      ans = (ans + now) % 1000000007;
    }
    if (k >= nu + 1) {
      long long cnt = get(num[rcol ^ 1], k - nu);
      long long now = get(v[rcol ^ 1], k - nu);
      ans = (ans + cnt * sum) % 1000000007;
      ans = (ans + now) % 1000000007;
    }
    if (nu <= k) ans = (ans + sum) % 1000000007;
  } else if (tp == 1) {
    add(num[rcol], nu + 1, 1);
    add(v[rcol], nu + 1, sum);
  } else {
    add(num[rcol], nu + 1, 1000000007 - 1);
    add(v[rcol], nu + 1, 1000000007 - sum);
  }
  for (auto p : g[x]) {
    int y = p.first, w = p.second;
    if (pp[y] || y == fa) continue;
    int nnu = nu;
    if (w != col) nnu++;
    dfs(y, x, rcol, w, nnu, sum, tp);
  }
}
void work(int x) {
  pp[x] = 1;
  for (auto p : g[x]) {
    int y = p.first, w = p.second;
    if (!pp[y]) {
      dfs(y, x, w, w, 0, a[x], 0);
      dfs(y, x, w, w, 0, 0, 1);
    }
  }
  for (auto p : g[x]) {
    int y = p.first, w = p.second;
    if (!pp[y]) {
      dfs(y, x, w, w, 0, 0, -1);
    }
  }
  for (auto p : g[x]) {
    int y = p.first;
    if (!pp[y]) {
      root = 0, sum = son[y];
      getroot(y, 0);
      work(root);
    }
  }
}
int main() {
  int u, v, x;
  scanf("%d%d", &n, &k);
  f[0] = sum = n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> x;
    g[u].push_back(make_pair(v, x));
    g[v].push_back(make_pair(u, x));
  }
  getroot(1, 0);
  work(root);
  for (int i = 1; i <= n; i++) {
    ans = (ans + a[i]) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
