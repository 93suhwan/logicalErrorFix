#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;
int n, k, sum, root;
int a[N], son[N], f[N], pp[N];
vector<pair<int, int> > g[N];
long long ans;
long long num[2][N], v[2][N];
inline int lowbit(int x) { return x & -x; }
void add(long long v[], int x, long long y) {
  for (int i = x; i < N; i += lowbit(i)) {
    v[i] = (v[i] + y) % mod;
  }
}
long long get(long long v[], int x) {
  long long res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    res = (res + v[i]) % mod;
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
void dfs(int x, int fa, int col, int nu, long long sum, int tp) {
  sum = (sum + a[x]) % mod;
  if (tp == 0) {
    if (k >= nu) {
      long long cnt = get(num[col], k - nu + 1);
      long long acc = get(v[col], k - nu + 1);
      ans = (ans + cnt * sum) % mod;
      ans = (ans + acc) % mod;
    }
    if (k >= nu + 1) {
      long long cnt = get(num[col ^ 1], k - nu);
      long long acc = get(v[col ^ 1], k - nu);
      ans = (ans + cnt * sum) % mod;
      ans = (ans + acc) % mod;
    }
    if (nu <= k) ans = (ans + sum) % mod;
  } else if (tp == 1) {
    add(num[col], nu + 1, 1);
    add(v[col], nu + 1, sum);
  } else {
    add(num[col], nu + 1, mod - 1);
    add(v[col], nu + 1, mod - sum);
  }
  for (auto p : g[x]) {
    int y = p.first, w = p.second;
    if (pp[y] || y == fa) continue;
    int nnu = nu;
    if (w != col) nnu++;
    dfs(y, x, w, nnu, sum, tp);
  }
}
void work(int x) {
  pp[x] = 1;
  for (auto p : g[x]) {
    int y = p.first, w = p.second;
    if (!pp[y]) {
      dfs(y, x, w, 0, a[x], 0);
      dfs(y, x, w, 0, 0, 1);
    }
  }
  for (auto p : g[x]) {
    int y = p.first, w = p.second;
    if (!pp[y]) {
      dfs(y, x, w, 0, 0, -1);
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
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  f[0] = sum = n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back(make_pair(y, w));
    g[y].push_back(make_pair(x, w));
  }
  getroot(1, 0);
  work(root);
  for (int i = 1; i <= n; i++) {
    ans = (ans + a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
