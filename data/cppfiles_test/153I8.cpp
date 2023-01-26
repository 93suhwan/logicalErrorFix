#include <bits/stdc++.h>
using namespace std;
const int N = 23, Z = 27, mod = 998244353, k = 2e4 + 9;
int n, t, a[N][Z], dp[(1 << N)], Min[(1 << N)][Z / 2];
long long ans;
int fb(int x) {
  for (int i = 0; i < N; i++) {
    if (x & (1 << i)) {
      return i;
    }
  }
}
int Get(int mask, int x) {
  if (x & 1) return Min[mask][x / 2] % k;
  return Min[mask][x / 2] / k;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      a[i][s[j] - 'a']++;
    }
  }
  for (int i = 0; i < Z / 2; i++) {
    Min[0][i] = (k - 1) * (k + 1);
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    int x = fb(mask);
    for (int i = 0; i < Z; i++) {
      Min[mask][i / 2] += min(a[x][i], Get(mask ^ (1 << x), i));
      if (i % 2 == 0) Min[mask][i / 2] *= k;
    }
    if (__builtin_popcount(mask) & 1)
      dp[mask] = 1;
    else
      dp[mask] = -1;
    for (int i = 0; i < Z; i++)
      dp[mask] = (1ll * dp[mask] * (Get(mask, i) + 1)) % mod;
  }
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if ((mask & (1 << i)) == 0) {
        dp[mask ^ (1 << i)] = (dp[mask ^ (1 << i)] + dp[mask]) % mod;
      }
    }
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        sum += i + 1;
      }
    }
    ans ^= 1ll * dp[mask] * __builtin_popcount(mask) * sum;
  }
  cout << ans;
}
