#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 2e5 + 5;
string a, s;
set<long long> g;
long long c[N], n, k, num[N], tot, L[N], R[N], ok[N], tin[N], tout[N], tree[N],
    vis[N], f[N], h[N];
void add(long long x, long long v) {
  while (x <= n + 1) {
    tree[x] += v;
    x += x & (-x);
  }
}
long long query(long long x) {
  long long res = 0;
  while (x) {
    res += tree[x];
    x -= x & (-x);
  }
  return res;
}
void work(long long u, long long dp) {
  tin[u] = ++tot;
  if (L[u]) work(L[u], dp + 1);
  if (R[u]) work(R[u], dp + 1);
  tout[u] = tot;
  add(tin[u], 1);
  add(tout[u] + 1, -1);
}
void dfs(long long u) {
  if (L[u]) dfs(L[u]);
  num[++tot] = u;
  a += s[u];
  h[u] = tot;
  if (R[u]) dfs(R[u]);
}
void get(long long u, long long pre) {
  g.insert(h[u]);
  pre += c[h[u]];
  vector<long long> out;
  while (g.size()) {
    long long w = *g.rbegin();
    if (w > h[u])
      g.erase(w), pre -= c[w], out.push_back(w);
    else
      break;
  }
  if (pre == g.size()) ok[u] = 1;
  if (L[u]) get(L[u], pre);
  if (R[u]) get(R[u], pre);
  if (ok[u])
    g.clear();
  else {
    for (auto i : out) g.insert(i), pre += c[i];
    g.erase(h[u]);
    pre -= c[h[u]];
  }
}
void solve(long long u) {
  if (L[u]) solve(L[u]);
  if (ok[u] && !vis[u]) {
    long long v = query(tin[u]);
    if (v <= k) {
      k -= v;
      long long x = u;
      while (x > 0 && !vis[x]) {
        add(tin[x], -1);
        add(tout[x] + 1, 1);
        vis[x] = 1;
        x = f[x];
      }
    }
  }
  if (R[u]) solve(R[u]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> s;
  s = " " + s;
  for (long long i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
    if (L[i]) f[L[i]] = i;
    if (R[i]) f[R[i]] = i;
  }
  dfs(1);
  a = " " + a;
  tot = 0;
  work(1, 0);
  for (long long i = 1; i <= n; i++) {
    long long x = i;
    while (x <= n && a[i] == a[x]) x++;
    if (x > n) break;
    if (a[x] > a[i]) {
      for (long long j = i; j < x; j++) c[j] = 1;
    }
    i = x - 1;
  }
  get(1, 0);
  solve(1);
  for (long long i = 1; i <= n; i++) {
    if (vis[num[i]]) cout << a[i];
    cout << a[i];
  }
  cout << endl;
}
