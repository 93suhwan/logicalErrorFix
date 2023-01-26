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
mint dp[(1 << 23)];
int cdp[(1 << 23)];
int lg[(1 << 23)];
int cnt[(1 << 23)];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  vector<vector<int>> count(n, vector<int>(26, 0));
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (auto ch : s) {
      count[i][ch - 'a']++;
    }
    lg[(1 << i)] = i;
  }
  cdp[0] = 1000000;
  dp[0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    cnt[i] = __builtin_popcount(i);
    dp[i] = (cnt[i] % 2 ? 1 : -1);
  }
  for (int j = 0; j < 26; j++) {
    for (int i = 1; i < (1 << n); i++) {
      int k = i & -i;
      cdp[i] = min(cdp[i ^ k], count[lg[k]][j]);
      dp[i] *= (cdp[i] + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (mask & (1 << i)) {
        dp[mask] += dp[mask ^ (1 << i)];
      }
      if (i == n - 1) {
        long long ml = 0;
        for (int j = 0; j < n; j++) {
          if (mask & (1 << j)) {
            ml += 1 + j;
          }
        }
        ml *= cnt[mask];
        ans ^= ml * dp[mask].vl;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
