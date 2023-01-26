#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 998244353;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
bool F(vector<long long>& a, vector<long long>& b, long long c = 0) {
  bool f = true;
  for (long long i = 0; i < b.size() && c + i < a.size(); i++) {
    f &= (a[c + i] == b[i]);
  }
  return f;
}
vector<long long> g(3e5 + 7, -1);
vector<long long> w(3e5 + 7);
vector<long long> len(3e5 + 7);
vector<long long> z(3e5 + 7);
vector<long long> b(3e5 + 7);
vector<long long> c;
vector<vector<long long>> a(3e5 + 7);
vector<long long> mn(3e5 + 7);
long long dfs(long long v, long long now) {
  if (z[v]) return -1;
  if (g[v] == -1) return now;
  return dfs(g[v], now + w[v]);
}
long long pl(long long a, long long b) {
  long long ans = a + b;
  if (ans >= mod) ans -= mod;
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> h(k + 1);
  vector<vector<long long>> fir(k + 1);
  bool f = false;
  set<long long> st;
  vector<vector<pair<long long, long long>>> ow(k + 1);
  for (long long i = 0; i < n; i++) {
    long long c;
    cin >> c;
    a[i].resize(c);
    for (long long j = 0; j < c; j++) {
      cin >> a[i][j];
      h[a[i][j]]++;
      if (h[a[i][j]] > 1) {
        z[i]++;
      }
      st.insert(a[i][j]);
      ow[a[i][j]].push_back({i, j});
    }
    fir[a[i][0]].push_back(i);
    for (long long j = 0; j < c; j++) {
      h[a[i][j]]--;
    }
  }
  long long kol = k - st.size();
  for (long long i = 1; i < k + 1; i++) {
    bool fs = true;
    if (ow[i].empty()) {
      continue;
    }
    set<long long> stl, str;
    for (auto& u : ow[i]) {
      if (u.second) stl.insert(a[u.first][u.second - 1]);
      if (u.second + 1 < a[u.first].size())
        str.insert(a[u.first][u.second + 1]);
    }
    if (stl.size() > 1 || str.size() > 1) {
      for (auto& u : ow[i]) {
        z[u.first]++;
      }
    }
  }
  vector<long long> fi(k + 1, -1);
  for (long long i = 1; i < k + 1; i++) {
    vector<long long> v;
    long long ind;
    for (long long j = 0; j < fir[i].size(); j++) {
      if (v.size() < a[fir[i][j]].size()) {
        v = a[fir[i][j]];
        ind = fir[i][j];
      }
    }
    for (long long j = 0; j < fir[i].size(); j++) {
      if (!F(v, a[fir[i][j]])) {
        z[ind]++;
      }
      if (fir[i][j] != ind) {
        b[fir[i][j]]++;
      }
    }
    if (v.empty()) continue;
    fi[i] = ind;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j < a[i].size(); j++) {
      if (fi[a[i][j]] != -1) {
        if (!F(a[i], a[fi[a[i][j]]], j)) {
          z[i]++;
        }
        b[fi[a[i][j]]]++;
        if (a[fi[a[i][j]]].size() > a[i].size() - j) {
          g[i] = fi[a[i][j]];
          w[i] = a[fi[a[i][j]]].size() - (a[i].size() - j);
          break;
        }
        b[fi[a[i][j]]]++;
      }
    }
  }
  vector<long long> um(3e5 + 7);
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    if (!b[i] && !z[i]) {
      long long val = dfs(i, a[i].size());
      c.clear();
      if (val == -1) continue;
      um[val]++;
      if (um[val] == 1) {
        v.push_back(val);
      }
    }
  }
  vector<long long> dp(m + 1);
  dp[0] = 1;
  for (long long i = 1; i < m + 1; i++) {
    dp[i] = dp[i - 1] * kol % mod;
    for (auto& u : v) {
      if (i - u < 0) continue;
      dp[i] = pl(dp[i], dp[i - u] * um[u] % mod);
    }
  }
  cout << dp[m];
}
