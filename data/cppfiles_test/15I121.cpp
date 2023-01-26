#include <bits/stdc++.h>
using namespace std;
struct node {
  set<long long> st;
  node() { st = {}; }
};
const long long maxn = 100;
long long fact[maxn + 1];
vector<long long> g[maxn];
long long h[maxn];
const long long mod = 1e9 + 7;
vector<node *> all;
long long pw(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long y = pw(a, b / 2);
    return y * y % mod;
  } else {
    return pw(a, b - 1) * a % mod;
  }
}
long long C(long long n, long long k) {
  if (k > n) return 0;
  return fact[n] * pw(fact[k] * fact[n - k] % mod, mod - 2) % mod;
}
node *dfs(long long v, long long p) {
  if (p == -1)
    h[v] = 0;
  else
    h[v] = h[p] + 1;
  vector<long long> ans;
  vector<node *> gg;
  for (long long i = 0; i < g[v].size(); ++i) {
    long long to = g[v][i];
    if (to == p) continue;
    gg.push_back(dfs(to, v));
  }
  node *res = new node();
  long long id = 0;
  for (long long j = 0; j < gg.size(); ++j) {
    if (gg[id]->st.size() < gg[j]->st.size()) id = j;
  }
  if (gg.size() != 0) res = gg[id];
  res->st.insert(h[v]);
  for (long long k = 0; k < gg.size(); ++k) {
    if (k == id) continue;
    for (auto y : gg[k]->st) {
      res->st.insert(y);
    }
  }
  if (h[v] == 1) all.push_back(res);
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  fact[0] = 1;
  for (long long m = 1; m <= maxn; ++m) {
    fact[m] = fact[m - 1] * m % mod;
  }
  long long q;
  cin >> q;
  while (q--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < n; ++i) {
      g[i].clear();
    }
    for (long long m = 0; m < n - 1; ++m) {
      long long a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 % mod << "\n";
      continue;
    }
    long long ans = 0;
    for (long long j = 0; j < n; ++j) {
      all.clear();
      dfs(j, -1);
      for (long long i = 1; i < n; ++i) {
        long long kol = 0;
        for (long long l = 0; l < all.size(); ++l) {
          if (all[l]->st.count(i)) kol++;
        }
        ans = (ans + C(kol, k)) % mod;
      }
    }
    cout << ans << "\n";
  }
}
