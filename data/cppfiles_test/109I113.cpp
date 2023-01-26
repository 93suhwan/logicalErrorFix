#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long fac[200005];
long long modpow(long long n, long long k) {
  long long s = n;
  long long ans = 1;
  for (long long i = 0; i < 60; i++) {
    if ((1LL << i) & k) {
      ans = (ans * s) % MOD;
    }
    s = (s * s) % MOD;
  }
  return ans;
}
long long inv(long long n) { return modpow(n, MOD - 2); }
long long comb(long long n, long long k) {
  if (k > n || k < 0) {
    return 0;
  }
  return (((fac[n] * inv(fac[k])) % MOD) * inv(fac[n - k])) % MOD;
}
void solve() {
  long long n;
  cin >> n;
  fac[0] = 1;
  for (long long i = 0; i < n * 2 + 3; i++) {
    fac[i + 1] = fac[i] * (i + 1);
  }
  vector<pair<long long, long long> > c;
  long long a1 = 0;
  long long a2 = 0;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    pair<long long, long long> x = {0, 0};
    if (s[0] == 'B') {
      x.first = 1;
      a1++;
    } else if (s[0] == 'W') {
      x.first = 2;
      a2++;
    }
    if (s[1] == 'B') {
      x.second = 1;
      a1++;
    } else if (s[1] == 'W') {
      x.second = 2;
      a2++;
    }
    c.push_back(x);
  }
  long long ans = comb(n * 2 - a1 - a2, n - a1);
  bool f = true;
  for (long long i = 0; i < n; i++) {
    if (c[i].first == c[i].second && c[i].first != 0) {
      f = false;
    }
  }
  if (!f) {
    cout << ans << '\n';
    return;
  }
  long long waze = 1;
  for (long long i = 0; i < n; i++) {
    if (c[i].first == 0 && c[i].second == 0) {
      waze = (waze * 2) % MOD;
    }
  }
  ans = (ans - waze + MOD) % MOD;
  bool g = true;
  bool h = true;
  for (long long i = 0; i < n; i++) {
    g &= ((c[i].first == 0 || c[i].first == 1) &&
          (c[i].second == 0 || c[i].second == 2));
    h &= ((c[i].first == 0 || c[i].first == 2) &&
          (c[i].second == 0 || c[i].second == 1));
  }
  if (g) {
    ans = (ans + 1) % MOD;
  }
  if (h) {
    ans = (ans + 1) % MOD;
  }
  cout << ans << endl;
}
void querySolve() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
