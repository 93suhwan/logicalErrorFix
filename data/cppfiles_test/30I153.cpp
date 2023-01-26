#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lg(long long x) { return __builtin_clzll(1ll) - __builtin_clzll(x); }
long long vlg(long long x) { return 1ll << lg(x); }
void google() {
  static long long _gtest_ = 1;
  cout << "Case #" << _gtest_++ << ": ";
}
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = n + 5;
  for (char c = 'a'; c <= 'z'; c++) {
    long long cnt = 0;
    vector<long long> v;
    string s2;
    for (long long i = 0; i < n; i++) {
      if (s[i] != c) {
        s2 += s[i];
        v.push_back(cnt);
        cnt = 0;
      } else
        cnt++;
    }
    v.push_back(cnt);
    string s3 = s2;
    reverse((s3).begin(), (s3).end());
    if (s3 == s2) {
      long long cnt = (long long)((s2).size());
      long long m = (long long)((v).size());
      for (long long i = 0; i < m / 2; i++) {
        cnt += 2 * min(v[i], v[m - i - 1]);
      }
      if (m % 2) {
        cnt += v[m / 2];
        if (v[m / 2] % 2) cnt--;
      }
      ans = min(ans, n - cnt);
    }
  }
  if (ans == n + 5) ans = -1;
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
