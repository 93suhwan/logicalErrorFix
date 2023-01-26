#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const int maxv = 1e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const long long inf64 = 1e18 + 10;
const long long mod = 998244353;
long long f[maxn], inv[maxn];
long long add(long long first, long long second) {
  return ((first + second) % mod + mod) % mod;
}
long long mul(long long first, long long second) {
  return (first * second) % mod;
}
inline long long qpow(long long first, long long n) {
  long long ret = 1ll;
  while (n) {
    if (n % 2) ret = mul(ret, first);
    first = mul(first, first);
    n >>= 1;
  }
  return ret;
}
long long C(int n, int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return mul(f[n], mul(inv[n - r], inv[r]));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  f[0] = 1;
  inv[0] = qpow(f[0], mod - 2);
  for (int i = 1; i < maxn; ++i) {
    f[i] = mul(f[i - 1], i);
    inv[i] = qpow(f[i], mod - 2);
  }
  t = 1;
  while (t--) {
    int N;
    cin >> N;
    vector<vector<int>> cnt(2, vector<int>(3, 0));
    vector<string> a;
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      a.push_back(s);
      for (int j = 0; j < 2; ++j) {
        if (s[j] == 'W') ++cnt[j][0];
        if (s[j] == 'B') ++cnt[j][1];
        if (s[j] == '?') ++cnt[j][2];
      }
    }
    int nw = cnt[0][0] + cnt[1][0];
    int nb = cnt[0][1] + cnt[1][1];
    if (nw > N || nb > N) {
      cout << 0 << endl;
      continue;
    }
    long long ans = C(2 * N - nw - nb, N - nw);
    std::cerr << "ans" << '=' << ans << std::endl;
    std::cerr << "nw" << '=' << nw << std::endl;
    std::cerr << "nb" << '=' << nb << std::endl;
    long long bad = 1;
    for (string s : a) {
      if (s[0] == s[1] && s[0] != '?') {
        bad = 0;
        break;
      }
      long long v = 0;
      if (s[0] == '?') ++v;
      if (s[1] == '?') ++v;
      if (v == 0) continue;
      bad = mul(bad, v);
    }
    std::cerr << "bad" << '=' << bad << std::endl;
    ans = add(ans, -bad);
    long long good = 1;
    for (string s : a) {
      if (s[0] == s[1] && s[0] != '?') {
        good = 0;
        break;
      }
      if (s[0] == 'B' || s[1] == 'W') {
        good = 0;
        break;
      }
    }
    ans = add(ans, good);
    good = 1;
    for (string s : a) {
      if (s[0] == s[1] && s[0] != '?') {
        good = 0;
        break;
      }
      if (s[0] == 'W' || s[1] == 'B') {
        good = 0;
        break;
      }
    }
    ans = add(ans, good);
    cout << ans << endl;
  }
}
