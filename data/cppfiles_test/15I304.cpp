#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long modpow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a) { return modpow(a, mod - 2); }
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n) {
  if (mf.size() > n) {
    return mf[n];
  } else {
    for (int i = mf.size(); i <= n; i++) {
      long long next = mf.back() * i % mod;
      mf.push_back(next);
      mfi.push_back(modinv(next));
    }
    return mf[n];
  }
}
long long modfactinv(int n) {
  if (mfi.size() > n) {
    return mfi[n];
  } else {
    return modinv(modfact(n));
  }
}
long long modbinom(int n, int k) {
  if (n < 0 || k < 0 || k > n) {
    return 0;
  } else {
    return modfact(n) * modfactinv(k) % mod * modfactinv(n - k) % mod;
  }
}
const int INF = 1e9;
vector<int> adj[105];
map<int, int> mp;
void dfs(int u, int p, int d) {
  mp[d]++;
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) adj[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  if (m == 2) {
    cout << n * (n - 1) / 2 << endl;
    return;
  }
  vector<long long> cnt(n + 1, 0);
  for (int rt = 0; rt < n; rt++) {
    vector<int> size(n + 1, 0), num(n + 1, 1);
    for (int u : adj[rt]) {
      mp.clear();
      dfs(u, rt, 1);
      for (auto p : mp) {
        size[p.first]++;
        num[p.first] *= p.second;
      }
    }
    for (int d = 1; d <= n; d++) {
      cnt[size[d]] += num[d];
    }
  }
  long long ans = 0;
  for (int k = m; k <= n; k++) {
    cnt[k] %= mod;
    ans += cnt[k] * modbinom(k, m);
    ans %= mod;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
