#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 5000 + 3;
vector<vector<long long>> C(N, vector<long long>(N, 0));
inline void init() {
  for (int n = 0; n < N; ++n) {
    C[n][0] = 1;
  }
  for (int n = 1; n < N; ++n) {
    for (int k = 1; k <= n; ++k) {
      C[n][k] = (C[n - 1][k] + C[n - 1][k - 1]) % MOD;
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  init();
  int n, k;
  string s;
  while (cin >> n >> k >> s) {
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      s[i] -= '0';
      pref[i + 1] = pref[i] + s[i];
    }
    long long ans = 1;
    if (pref.back() >= k) {
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          vector<int> cnt = {0, 0};
          cnt[1] = pref[j + 1] - pref[i];
          if (cnt[1] > k) {
            continue;
          }
          cnt[0] = j - i + 1 - cnt[1];
          if (cnt[s[i] ^ 1]-- == 0) {
            continue;
          }
          if (cnt[s[j] ^ 1]-- == 0) {
            continue;
          }
          int d = C[j - i - 1][cnt[0]];
          ans = (ans + d) % MOD;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
