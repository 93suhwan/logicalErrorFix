#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
pair<long long, long long> extended_gcd(long long a, long long b) {
  pair<long long, long long> aa = {1, 0}, bb = {0, 1};
  while (b) {
    aa.first -= bb.first * (a / b);
    aa.second -= bb.second * (a / b);
    a %= b;
    swap(a, b);
    swap(aa, bb);
  }
  return aa;
}
pair<long long, long long> temp;
struct mint {
  int vl;
  mint() { vl = 0; }
  mint(long long v) {
    if (v < 0) {
      v += ((-v + mod - 1) / mod) * mod;
    }
    vl = (int)(v % mod);
  }
  mint operator+(mint oth) { return mint((long long)vl + oth.vl); }
  mint operator-(mint oth) { return mint((long long)vl - oth.vl); }
  mint operator*(mint oth) { return mint((long long)vl * oth.vl); }
  mint powr(long long k) {
    if (k == 0) {
      return mint(1);
    } else if (k % 2) {
      return (*this) * powr(k - 1);
    } else {
      mint tmp = powr(k / 2);
      return tmp * tmp;
    }
  }
  mint inv() {
    temp = extended_gcd(vl, mod);
    return mint(temp.first);
  }
  mint operator/(mint oth) { return (*this) * oth.inv(); }
  void operator+=(mint oth) { (*this) = (*this) + oth; }
  void operator-=(mint oth) { (*this) = (*this) - oth; }
  void operator*=(mint oth) { (*this) = (*this) * oth; }
  void operator/=(mint oth) { (*this) = (*this) / oth; }
};
ostream& operator<<(ostream& os, const mint& m) {
  os << m.vl;
  return os;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<mint> fact(n + 1, mint(1)), inv(n + 1, mint(1));
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * mint(i);
    inv[i] = fact[i].inv();
  }
  auto choose = [&](int n, int k) -> mint {
    if (n < k || (n < 0 && k != 0) || k < 0) {
      return 0;
    } else if (k == 0) {
      return 1;
    } else {
      return fact[n] * inv[n - k] * inv[k];
    }
  };
  vector<vector<int>> occ((1 << n), vector<int>(26, 0));
  vector<mint> dp1((1 << n), 1);
  vector<vector<mint>> dp2((1 << n), vector<mint>(n + 1, 0));
  vector<mint> dp((1 << n), 0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto ch : s) {
      occ[(1 << i)][ch - 'a']++;
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    int j = i & -i;
    if (j != i) {
      for (int k = 0; k < 26; k++) {
        occ[i][k] = min(occ[i ^ j][k], occ[j][k]);
      }
    }
    for (int k = 0; k < 26; k++) {
      dp1[i] *= (1 + occ[i][k]);
    }
    int cnt = __builtin_popcount(i);
    long long ml = 0;
    for (int k = 0; k < n; k++) {
      if (i & (1 << k)) {
        ml += k + 1;
        for (int x = 1; x < cnt; x++) {
          dp2[i][x] += dp2[i ^ (1 << k)][x];
        }
      }
    }
    ml *= cnt;
    dp2[i][cnt] += dp1[i] * (cnt % 2 ? 1 : -1);
    dp[i] += dp1[i] * (cnt % 2 ? 1 : -1);
    for (int x = 1; x < cnt; x++) {
      dp[i] += dp2[i][x] / choose(cnt - 1, x);
    }
    ans ^= ml * dp[i].vl;
  }
  cout << ans << '\n';
  return 0;
}
