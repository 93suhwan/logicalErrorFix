#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
const int MOD = 998244353;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long f[(1 << n)];
  long long g[(1 << n)];
  for (int i = 0; i < (1 << n); i++) {
    f[i] = g[i] = 0;
  }
  long long oc[n][26];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      oc[i][j] = 0;
    }
    for (char c : v[i]) {
      oc[i][c - 'a']++;
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    vector<long long> min_oc;
    min_oc.assign(26, 1e9);
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        for (int k = 0; k < 26; k++) {
          min_oc[k] = min(min_oc[k], oc[j][k]);
        }
      }
    }
    long long ans = 1;
    for (int j : min_oc) {
      ans *= (j + 1);
    }
    f[i] = ans * pow(-1, __builtin_popcount(i) + 1);
    if (f[i] < 0) {
      f[i] = MOD + f[i];
    }
    f[i] %= MOD;
  }
  for (int i = 0; i < (1 << n); ++i) {
    g[i] = f[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) {
        g[mask] += g[mask ^ (1 << i)];
        g[mask] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    long long res = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        res += __builtin_popcount(i) * (j + 1);
      }
    }
    ans ^= (res * g[i]);
  }
  cout << ans << '\n';
}
