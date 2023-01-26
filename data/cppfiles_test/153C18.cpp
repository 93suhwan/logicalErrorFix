#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int m[24][30], cur[30];
long long val[1 << 23], ans = 0;
void solve() {
  int n;
  string second;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> second;
    for (char c : second) m[i][c - 'a']++;
  }
  for (int i = 1; i < (1 << n); i++) {
    for (int j = 0; j < 26; j++) cur[j] = 1000000;
    int bits = 0;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) continue;
      bits++;
      for (int k = 0; k < 26; k++) cur[k] = min(cur[k], m[j][k]);
    }
    val[i] = 1;
    for (int j = 0; j < 26; j++) val[i] = (val[i] * (1 + cur[j])) % MOD;
    if (bits % 2 == 0) val[i] = (MOD - val[i]) % MOD;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) val[j] = (val[j] + val[j ^ (1 << i)]) % MOD;
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    long long bits = 0, t = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        bits++;
        t += j + 1;
      }
    }
    ans ^= val[i] * bits * t;
  }
  printf("%lld\n", ans);
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int tests = 1;
  while (tests--) solve();
}
