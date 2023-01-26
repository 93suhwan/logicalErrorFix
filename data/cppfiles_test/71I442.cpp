#include <bits/stdc++.h>
using namespace std;
int cases(1), t;
const int64_t Mod = 1e9 + 7, Mod1 = 998244353;
template <typename T>
T Power(T n, T k) {
  T x = 1;
  while (k) {
    if (k & 1) x *= n;
    n *= n;
    k >>= 1;
  }
  return x;
}
template <typename T>
T Power(T n, T k, T M) {
  n %= M;
  T res = 1;
  while (k) {
    if (k & 1) res = res * n % M;
    n = n * n % M;
    k >>= 1;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  for (cin >> t; cases <= t; cases++) {
    string s;
    long long k;
    cin >> s >> k;
    if (k == 1) {
      char c = s[0];
      for (long long i = 0; i < (long long)s.size(); i++) {
        cout << c;
      }
      cout << '\n';
    } else {
      vector<long long> cnt(10);
      for (auto e : s) cnt[e - '0']++;
      long long cn = 0;
      for (long long i = 0; i < (long long)cnt.size(); i++) {
        cn += cnt[i] > 0;
      }
      if (cn <= 2) {
        cout << s << '\n';
        continue;
      }
      char c = s[0];
      bool valid = 0;
      char d;
      for (long long i = 1; i < (long long)s.size(); i++) {
        if (!valid && s[i] != c && s[i] != '9') {
          s[i] = s[i] + 1;
          d = min(c, s[i]);
          valid = 1;
          continue;
        }
        if (valid) s[i] = d;
      }
      cout << s << '\n';
    }
  }
  return 0;
}
