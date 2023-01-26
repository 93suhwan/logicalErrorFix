#include <bits/stdc++.h>
using namespace std;
int n, ds[25][27], inf = 1e9, mod = 998244353;
string s[23];
long long f[(1 << 23)], dp[(1 << 23)];
void input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
}
long long mul(long long x, long long y) { return (x * y) % mod; }
void solve() {
  input();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].length(); j++) ds[i][int(s[i][j] - 97)]++;
  }
  for (int msk = 1; msk < (1 << n); msk++) {
    int x = msk, t = 0, cntMin[26];
    for (int i = 0; i < 26; i++) cntMin[i] = inf;
    while (x > 0) {
      if (x % 2 == 1) {
        for (int j = 0; j < 26; j++) cntMin[j] = min(cntMin[j], ds[t][j]);
      }
      x >>= 1;
      t++;
    }
    long long val = 1;
    for (int i = 0; i < 26; i++) val = mul(val, long long(cntMin[i] + 1));
    f[msk] = val;
  }
  long long curVal = 0;
  for (int i = 0; i < n; i++) {
    long long val = 1;
    for (int j = 0; j < 26; j++) val = mul(val, (1 + ds[i][j]));
    dp[1 << i] = val;
    curVal ^= (dp[1 << i] * (i + 1));
  }
  for (int msk = 1; msk < (1 << n); msk++) {
    int bit_cnt = __builtin_popcount(msk);
    if (bit_cnt == 1) continue;
    int fb = __builtin_ctz(msk);
    int msk1 = msk ^ (1 << fb), x = msk, t = 0, tt = 0;
    dp[msk] = ((dp[msk1] + dp[1 << fb]) % mod + mod - f[msk]) % mod;
    while (x > 0) {
      if (x % 2 == 1) tt += t + 1;
      x >>= 1;
      t++;
    }
    curVal ^= long long(dp[msk]) * long long(tt * bit_cnt);
  }
  cout << curVal << endl;
}
int main() {
  solve();
  return 0;
}
