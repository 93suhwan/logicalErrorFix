#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, fac[105];
bitset<105> a[105], c[105];
vector<int> G[105], H[105];
struct Union_Set {
  int f[105], s[105];
  void init(int n) {
    for (int i = 1; i <= n; ++i) f[i] = i, s[i] = 1;
  }
  int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
  int Merge(int x, int y) {
    int fx = getf(x), fy = getf(y);
    if (fx == fy) return 0;
    s[fx] += s[fy], s[fy] = 0;
    f[fy] = fx;
    return 1;
  }
} S;
int Solve(vector<int> &p, int k) {
  if (p.empty()) return fac[k];
  bitset<105> ban, ok, in;
  for (auto i : p) in[i] = 1;
  for (auto u : p) {
    for (auto v : G[u]) ban[v] = 1;
  }
  int rem = k, ans = 1;
  for (auto u : p) {
    if (!ban[u]) {
      if (!ok[S.getf(u)]) {
        ok[S.getf(u)] = 1, ++rem;
        if (S.s[S.getf(u)] > 1) (ans <<= 1) %= mod;
      }
    }
  }
  vector<int> z;
  for (auto u : p) {
    if (ok[S.getf(u)]) z.push_back(u), in[u] = 0;
  }
  unordered_map<bitset<105>, bitset<105> > mp;
  unordered_map<bitset<105>, vector<int> > vec;
  for (int i = 1; i <= n; ++i) {
    bitset<105> B;
    for (auto j : z) {
      if (a[j][i]) B[j] = 1;
    }
    if (B.count()) mp[B][i] = 1, --rem;
  }
  if (mp.size() >= 2 * z.size()) {
    puts("0");
    exit(0);
  }
  static int vis[105];
  function<void(int)> dfs = [&](int u) -> void {
    c[u][u] = 1;
    vis[u] = 1;
    for (auto v : H[u]) {
      if (!vis[v])
        c[v] = c[u], dfs(v);
      else {
        auto tmp = c[u] ^ c[v];
        bool ok = false;
        for (auto [B, t] : mp) {
          if ((t & tmp) == tmp) {
            ok = true;
            break;
          }
        }
        if (!ok) {
          puts("0");
          exit(0);
        }
      }
    }
  };
  for (auto u : z) {
    if (!vis[u]) dfs(u);
  }
  ans = 1LL * ans * fac[rem] % mod;
  for (auto u : p) {
    if (in[u]) {
      for (auto [B, t] : mp) {
        if ((t & a[u]) == a[u]) {
          vec[B].push_back(u);
          break;
        }
      }
    }
  }
  for (auto [B, t] : mp) {
    ans = 1LL * ans * Solve(vec[B], t.count());
  }
  return ans;
}
inline void adde(int u, int v) { H[u].push_back(v), H[v].push_back(u); }
int main() {
  n = read(), m = read();
  vector<int> all;
  for (int i = 1; i <= m; ++i) {
    all.push_back(i);
    int k = read();
    while (k--) {
      a[i][read()] = 1;
    }
  }
  S.init(m);
  for (int i = 1; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      if ((a[i] & a[j]) == a[i]) {
        G[j].push_back(i);
      } else if ((a[i] & a[j]) == a[j]) {
        G[i].push_back(j);
      } else if ((a[i] & a[j]).count())
        S.Merge(i, j), adde(i, j);
    }
  }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
  }
  printf("%d\n", Solve(all, n));
  return 0;
}
