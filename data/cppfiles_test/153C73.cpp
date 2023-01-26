#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 23;
const long long mod = 998244353;
int n, cnt[maxN][26];
long long f[1 << maxN];
void solve() {
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    string s;
    cin >> s;
    for (auto &c : s) {
      cnt[i][c - 'a']++;
    }
  }
  for (int mask = 1; mask <= (int)((1 << n) - 1); ++mask) {
    int d[26] = {};
    fill(d, d + 26, 1e9);
    for (int i = 0; i < (int)(n); ++i) {
      if (mask >> i & 1) {
        for (int c = 0; c < (int)(26); ++c) {
          uin(d[c], cnt[i][c]);
        }
      }
    }
    f[mask] = 1;
    for (int c = 0; c < (int)(26); ++c) {
      f[mask] = (f[mask] * (d[c] + 1)) % mod;
    }
  }
  auto zeta = [](int n, long long f[]) {
    for (int i = 0; i < (int)(n); ++i) {
      for (int mask = 0; mask < (int)(1 << n); ++mask) {
        if (mask >> i & 1) {
          f[mask] += f[mask ^ (1 << i)];
        }
      }
    }
  };
  auto neg = [](int n, long long f[]) {
    for (int mask = 0; mask < (int)(1 << n); ++mask) {
      if (__builtin_popcount(mask) & 1) {
        f[mask] = -f[mask];
      }
    }
  };
  neg(n, f);
  zeta(n, f);
  long long ans = 0;
  for (int mask = 0; mask < (int)(1 << n); ++mask) {
    f[mask] = (((-f[mask]) % mod) + mod) % mod;
    int k = 0, s = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (mask >> i & 1) {
        k++;
        s += (i + 1);
      }
    }
    ans ^= f[mask] * k * s;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
