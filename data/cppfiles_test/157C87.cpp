#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100;
const long long mod = 998244353;
long long t, n, m, k;
long long a[N];
string s;
vector<long long> pos;
long long quickpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  long long a = 1, b = 1;
  m = min(m, n - m);
  for (long long i = 1; i <= m; i++) {
    (a *= n - i + 1) %= mod;
    (b *= i) %= mod;
  }
  return a % mod * quickpow(b, mod - 2) % mod;
}
void solve() {
  cin >> s;
  s = "." + s;
  pos.clear();
  pos.push_back(0);
  for (long long i = 1; i <= n; i++) {
    if (s[i] == '1') pos.push_back(i);
  }
  pos.push_back(n + 1);
  if (k == 0 || pos.size() - 2 < k) {
    cout << 1 << '\n';
    return;
  }
  long long ans = 0;
  for (long long l = k - 1; l <= k; l++) {
    long long sum = 0;
    for (long long i = k - l; i + k + 1 < pos.size(); i++) {
      sum = (sum + C(pos[i + l + 1] - 1 - pos[i], l)) % mod;
    }
    if ((k - l) % 2 == 0)
      ans = (ans + sum) % mod;
    else
      ans = (ans - sum + mod) % mod;
  }
  cout << ans << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> k) {
    solve();
  }
  return 0;
}
