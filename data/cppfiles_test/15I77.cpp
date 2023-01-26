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
void solve() {
  int n, m;
  cin >> n >> m;
  int d[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      d[i][j] = (i == j ? 0 : INF);
    }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    d[u][v] = d[v][u] = 1;
  }
  if (m == 2) {
    cout << n * (n - 1) / 2 << endl;
    return;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  vector<long long> cnt(n + 1);
  for (int mid = 0; mid < n; mid++) {
    map<int, int> make_pair;
    for (int i = 0; i < n; i++) {
      if (i == mid) continue;
      make_pair[d[i][mid]]++;
    }
    for (auto p : make_pair) {
      cnt[p.second]++;
    }
  }
  long long ans = 0;
  for (int i = m; i <= n; i++) {
    cnt[i] %= mod;
    ans += cnt[i] * modbinom(i, m);
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
