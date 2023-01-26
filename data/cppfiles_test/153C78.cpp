#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(T arg, Ts &...args) {
  cout << arg << ' ';
  err(args...);
}
const int N = 1 << 24;
const long long mod = 998244353;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
long long rng(long long l, long long r) {
  uniform_int_distribution<long long> uni(l, r);
  return uni(mt);
}
string s[24];
int cnt[24][26];
long long g[N];
long long f[N];
void FWTOR(long long *a, int n) {
  for (int k = 2; k <= n; k <<= 1)
    for (int i = 0; i < n; i += k)
      for (int j = i; j < i + (k >> 1); j++)
        a[j + (k >> 1)] = (a[j + (k >> 1)] + a[j]) % mod;
}
void IFWTAND(long long *a, int n) {
  for (int k = n; k > 1; k >>= 1)
    for (int i = 0; i < n; i += k)
      for (int j = i; j < i + (k >> 1); j++)
        a[j] = (a[j] - a[j + (k >> 1)] + mod) % mod;
}
void run(int tCase) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (char ch : s[i]) {
      cnt[i][ch - 'a']++;
    }
  }
  int all = (1 << n) - 1;
  for (int mask = 0; mask < 1 << n; ++mask) {
    int mi[26];
    memset(mi, 0x3f, sizeof mi);
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        for (int j = 0; j < 26; ++j) {
          mi[j] = min(mi[j], cnt[i][j]);
        }
      }
    }
    g[mask] = 1;
    for (int j : mi) {
      g[mask] = g[mask] * (j + 1) % mod;
    }
  }
  IFWTAND(g, 1 << n);
  long long sum = 0;
  for (int i = 0; i < 1 << n; ++i) {
    sum = (sum + g[i]) % mod;
  }
  FWTOR(g, 1 << n);
  for (int i = 0; i < 1 << n; ++i) {
    f[i] = (sum - g[all ^ i] + mod) % mod;
  }
  long long ans = 0;
  for (int i = 0; i < 1 << n; ++i) {
    int c = 0, s = 0;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        c++;
        s += j + 1;
      }
    }
    ans ^= f[i] * c * s;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    run(t);
  }
  return 0;
}
