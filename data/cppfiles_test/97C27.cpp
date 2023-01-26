#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimize(0)
#pragma GCC optimization("unroll-loops")
using namespace std;
const int MAXN = 1e3 + 1, inf = 1e9 + 7;
int M = 1e9 + 7, P = 1e6 + 2;
int f[MAXN + 1], inv[MAXN + 1], inc[MAXN + 1];
int bin_pow(int a, int b, int M) {
  if (b <= 0) return 1;
  if (b % 2 == 0) {
    int x = bin_pow(a, b / 2, M);
    return x * x % M;
  } else {
    return bin_pow(a, b - 1, M) * a % M;
  }
}
int C(int n, int k) {
  if (n < 0 || k > n) return 0;
  return (f[n] * inc[k] % M * inc[n - k] % M + M) % M;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) {
  if (a < 0) return lcm(abs(a), b);
  if (b < 0) return lcm(a, abs(b));
  if (a == 0 && b == 0) return 0;
  return a / gcd(a, b) * b;
}
vector<vector<int>> g, dp;
int get(int u, int k) {
  k = min(k, (int)dp[u].size() - 1);
  return dp[u][k];
}
void dfs(int u, int p) {
  int cnt = 0;
  vector<int> to;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u);
      cnt++;
      to.push_back(v);
    }
  }
  int s = 0;
  for (int i = 0; i < (int)g.size(); ++i) {
    int tmp = 0;
    for (int v : to) {
      tmp += max((int)1, get(v, i) - i);
    }
    dp[u].push_back(tmp + s);
    if (i == 250) {
      vector<int> to_2;
      for (int v : to) {
        if (get(v, i) - i < 2)
          ++s;
        else
          to_2.push_back(v);
      }
      swap(to, to_2);
    }
    if (tmp + s == cnt) break;
  }
}
void solve() {
  int n, m;
  cin >> n;
  g.resize(n);
  dp.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  int q;
  cin >> q;
  while (q--) {
    int u, k;
    cin >> u >> k;
    --u;
    cout << get(u, k) << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  f[0] = inv[0] = f[1] = inv[1] = 1;
  for (int i = 2; i <= MAXN; ++i) {
    f[i] = f[i - 1] * i % M;
    inv[i] = ((-M / i) * inv[M % i] + M) % M;
  }
  inc[0] = 1;
  for (int i = 1; i <= MAXN; ++i) {
    inc[i] = inc[i - 1] * inv[i] % M;
  }
  int _ = 1;
  while (_--) solve();
}
