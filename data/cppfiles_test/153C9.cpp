#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int power[24] = {0};
const int mod = 998244353;
int sgn(int x) { return (x % 2 ? 1 : -1); }
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  for (int z = 0; z < n; z++) {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    v[z] = cnt;
  }
  vector<int> f(power[n], 0);
  vector<int> popcnt(power[n], 0);
  for (int mask = 1; mask < power[n]; mask++) {
    vector<int> cnt(26, INF);
    for (int z = 0; z < n; z++) {
      if (power[z] & mask) {
        for (int i = 0; i < 26; i++) {
          cnt[i] = min(v[z][i], cnt[i]);
        }
        popcnt[mask] = 1 + popcnt[power[z] ^ mask];
      }
    }
    long long int val = 1;
    for (int i = 0; i < 26; i++) {
      val *= (long long int)(cnt[i] + 1);
      if (val >= mod) val %= mod;
    }
    val = mod + val * sgn(popcnt[mask]);
    if (val >= mod) val %= mod;
    f[mask] = val;
  }
  for (int i = 0; i < n; i++) {
    for (int mask = 1; mask < power[n]; mask++) {
      if (mask & power[i]) {
        f[mask] += f[mask ^ power[i]];
        if (f[mask] >= mod) f[mask] %= mod;
      }
    }
  }
  long long int res = 0;
  for (int mask = 1; mask < power[n]; mask++) {
    long long int c = popcnt[mask];
    {
      int sum = 0;
      for (int z = 0; z < n; z++) {
        if (power[z] & mask) {
          sum += z + 1;
        }
      }
      c *= sum;
    }
    c *= (long long int)f[mask];
    res ^= c;
  }
  cout << res << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  power[0] = 1;
  for (int j = 1; j <= 23; j++) power[j] = power[j - 1] * 2;
  while (t--) {
    solve();
  }
  return 0;
}
