#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
inline int add(int x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
inline int mul(int x, int y) { return (x * 1LL * y) % MOD; }
const int N = 23;
int n, c[N][26], d[26];
long long f[1 << N];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char ch : s) ++c[i][ch - 'a'];
  }
  for (int i = 1; i < (1 << n); ++i) {
    int x = __builtin_popcount(i);
    for (int j = 0; j < 26; ++j) d[j] = INT_MAX;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        for (int k = 0; k < 26; ++k) d[k] = min(d[k], c[j][k]);
      }
    }
    f[i] = 1;
    for (int j = 0; j < 26; ++j) f[i] = mul(f[i], 1 + d[j]);
    if (!(x & 1)) f[i] = add(0, -f[i]);
  }
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < (1 << n); ++i) {
      if (i >> j & 1) f[i] = add(f[i], f[i ^ (1 << j)]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int x = 0, s = 0;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) ++x, s += j;
    }
    s += x;
    f[i] *= s * x;
    ans ^= f[i];
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
