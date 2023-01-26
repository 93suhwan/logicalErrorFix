#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
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
vector<mint> dp2[(1 << 23)];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  vector<vector<int>> count(n, vector<int>(26, 0));
  vector<mint> iv(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    iv[i] = mint(i).inv();
  }
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (auto ch : s) {
      count[i][ch - 'a']++;
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    if (__builtin_popcount(i) == 1) {
      for (int j = 0; j < n; j++) {
        if (i == (1 << j)) {
          dp2[i].resize(26, 0);
          for (int k = 0; k < 26; k++) {
            dp2[i][k] = count[j][k];
          }
          break;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (!((1 << j) & i)) {
        int xr = i ^ (1 << j);
        if (dp2[xr].empty()) {
          dp2[xr].resize(26, 0);
          for (int k = 0; k < 26; k++) {
            dp2[xr][k] = min(count[j][k], dp2[i][k].vl);
          }
        }
      }
    }
    dp[i] = 1;
    for (int k = 0; k < 26; k++) {
      dp[i] *= (dp2[i][k] + 1);
    }
    vector<mint>().swap(dp2[i]);
  }
  for (int i = 1; i < (1 << n); i++) {
    int cnt = __builtin_popcount(i);
    if (cnt == 1) {
      dp2[i].resize(2, 0);
    }
    long long ml = 0;
    if (cnt % 2 == 0) {
      dp[i] *= -1;
    }
    dp2[i][cnt] += dp[i];
    for (int x = 1; x < cnt; x++) {
      dp2[i][x] *= iv[cnt - x];
      dp[i] += dp2[i][x];
    }
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j))) {
        int xr = i ^ (1 << j);
        if (dp2[xr].empty()) {
          dp2[xr].resize(cnt + 2, 0);
        }
        for (int k = 1; k <= cnt; k++) {
          dp2[xr][k] += dp2[i][k];
        }
      } else {
        ml += 1 + j;
      }
    }
    ml *= cnt;
    ans ^= ml * dp[i].vl;
    vector<mint>().swap(dp2[i]);
  }
  cout << ans << '\n';
  return 0;
}
