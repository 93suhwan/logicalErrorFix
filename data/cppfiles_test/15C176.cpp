#include <bits/stdc++.h>
using namespace std;
const int INF = (is_same<int, long long>::value ? 1e18 + 666 : 1e9 + 666);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
inline int bpow(long long a, long long b, int mod) {
  int res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = int((1ll * a * res) % mod);
      res %= mod;
    }
    a *= a;
    a %= mod;
  }
  return res;
}
void UseFiles(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void run();
signed main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  run();
}
void solve();
void run() {
  int n;
  cin >> n;
  while (n-- > 0) {
    solve();
  }
}
void solve() {
  constexpr int mod = 1e9 + 7;
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (k == 2) {
    cout << (n * (n - 1) >> 1) << endl;
    return;
  }
  function<vector<int>(int, int)> dfs = [&g, &dfs](int v, int p) {
    vector<int> res;
    for (auto &x : g[v]) {
      if (x == p) continue;
      vector<int> ret = dfs(x, v);
      if (((int)(ret).size()) > ((int)(res).size())) {
        swap(ret, res);
      }
      for (int i = 1; i <= ((int)(ret).size()); ++i) {
        res[((int)(res).size()) - i] += ret[((int)(ret).size()) - i];
      }
    }
    res.push_back(1);
    return res;
  };
  int ans = 0;
  for (int center = 0; center < n; ++center) {
    if (((int)(g[center]).size()) < k) continue;
    vector<vector<int>> dverts;
    for (auto &v : g[center]) {
      dverts.push_back(dfs(v, center));
      reverse(dverts.back().begin(), dverts.back().end());
    }
    for (int i = 0;; ++i) {
      vector<int> dp(k + 1, 0);
      dp[0] = 1;
      for (auto &x : dverts) {
        if (((int)(x).size()) <= i) continue;
        for (int j = k; j > 0; --j) {
          dp[j] += int(1ll * dp[j - 1] * x[i] % mod);
          if (dp[j] >= mod) {
            dp[j] -= mod;
          }
        }
      }
      if (dp[k] == 0) break;
      ans += dp[k];
      if (ans >= mod) {
        ans -= mod;
      }
    }
  }
  cout << ans << endl;
}
