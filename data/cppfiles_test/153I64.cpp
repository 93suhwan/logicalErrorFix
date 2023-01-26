#include <bits/stdc++.h>
using namespace std;
const int N = 23, Z = 26, mod = 998244353;
int n, t, a[N][Z], dp[(1 << N)], Min[(1 << N)][Z];
long long ans;
int fb(int x) {
  for (int i = 0; i < N; i++) {
    if (x & (1 << i)) {
      return i;
    }
  }
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
  for (int i = 0; i < Z; i++) {
    Min[0][i] = (1 << N);
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    int x = fb(mask);
    for (int i = 0; i < Z; i++)
      Min[mask][i] = min(a[x][i], Min[mask ^ (1 << x)][i]);
    if (__builtin_popcount(mask) & 1)
      dp[mask] = 1;
    else
      dp[mask] = -1;
    for (int i = 0; i < Z; i++)
      dp[mask] = (1ll * dp[mask] * (Min[mask][i] + 1)) % mod;
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
