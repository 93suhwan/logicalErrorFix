#include <bits/stdc++.h>
using namespace std;
const int N = 23, mod = 998244353;
int freq[N][26];
int dp[(1 << N) + 2];
int n;
void calc(int mask) {
  vector<int> v(26, 100000000);
  for (int i = 0; i < n; i++) {
    if (((1 << i) & mask) == 0) continue;
    for (int j = 0; j < 26; j++) {
      v[j] = min(v[j], freq[i][j]);
    }
  }
  int ans = 1;
  for (auto i : v) ans = (1LL * ans * (i + 1)) % mod;
  dp[mask] = ans;
  if (__builtin_popcount(mask) % 2 == 0) dp[mask] *= -1;
}
void doWork() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto j : s) freq[i][j - 'a']++;
  }
  for (int i = 1; i < (1 << n); i++) calc(i);
  for (int i = 0; i < n; ++i)
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % mod;
    }
  long long ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    int k = 0, sum = 0;
    for (int j = 0; j < n; j++) {
      if (((1 << j) & i) == 0) continue;
      k++;
      sum += j + 1;
    }
    long long cur = dp[i];
    cur *= k;
    cur *= sum;
    ans ^= cur;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    doWork();
  }
  return 0;
}
