#include <bits/stdc++.h>
using namespace std;
int n, d[23][26], inf = int(1e9) + 7;
int f[1 << 23], dp[1 << 23], sa[1 << 23], le[1 << 23];
vector<int> g[1 << 23];
long long mod = 998244353;
long long mul(long long x, long long y) { return (x * y) % mod; }
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) d[i][int(s[j] - 97)]++;
  }
  for (int msk = 1; msk < (1 << n); msk++) {
    g[msk].assign(__builtin_popcount(msk) + 1, 0);
    int x = msk, t = 0, cntMin[26];
    for (int i = 0; i < 26; i++) cntMin[i] = inf;
    while (x > 0) {
      if (x % 2 == 1) {
        sa[msk] += t + 1;
        for (int i = 0; i < 26; i++) cntMin[i] = min(cntMin[i], d[t][i]);
      }
      x >>= 1;
      t++;
    }
    le[msk] = t - 1;
    long long val = 1;
    for (int i = 0; i < 26; i++) val = mul(val, long long(1 + cntMin[i]));
    f[msk] = val;
  }
  for (int msk = 1; msk < (1 << n); msk++) {
    int bit_cnt = __builtin_popcount(msk);
    if (bit_cnt == 1) {
      continue;
    }
    if (bit_cnt == 2) {
      g[msk][2] = f[msk];
      g[msk][1] = f[msk];
    } else {
      if (bit_cnt % 2 == 1)
        g[msk][bit_cnt] = (mod - f[msk]) % mod;
      else
        g[msk][bit_cnt] = f[msk];
      int p = le[msk];
      for (int k = bit_cnt - 1; k >= 1; k--) {
        while ((msk >> p) % 2 == 0) p--;
        int msk1 = (1 << p) ^ msk;
        g[msk][k] = (long long(g[msk1][k]) + long long(g[msk][k + 1])) % mod;
        p--;
      }
    }
  }
  long long curVal = 0;
  for (int msk = 1; msk < (1 << n); msk++) {
    int bit_cnt = __builtin_popcount(msk);
    if (bit_cnt == 1) {
      dp[msk] = f[msk];
    }
    if (bit_cnt == 2) {
      int fb = __builtin_ctz(msk);
      int msk1 = (1 << fb) ^ msk;
      long long val = (long long(dp[msk1]) + long long(dp[1 << fb]) + mod -
                       long long(f[msk])) %
                      mod;
      dp[msk] = val;
    }
    if (bit_cnt > 2) {
      int fb = __builtin_ctz(msk);
      int msk1 = (1 << fb) ^ msk;
      long long val = (long long(dp[msk1]) + long long(f[1 << fb]) +
                       (mod - long long(g[msk][1]))) %
                      mod;
      dp[msk] = val;
    }
    long long u = long long(dp[msk]) * long long(bit_cnt) * long long(sa[msk]);
    curVal ^= u;
  }
  cout << curVal << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();
  solve();
  cout << double(clock() - start) / double(CLOCKS_PER_SEC) << endl;
  return 0;
}
