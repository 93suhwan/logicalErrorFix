#include <bits/stdc++.h>
using namespace std;
const int N = 23 + 1;
const int S = 10000 + 1;
const int C = 26 + 1;
const int M = 998244353 + 1;
int a[N], n;
int answer;
char s[N][S];
int freq[N][C], ctr[C];
int dp[(1 << N) + 1];
void read() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
}
void solve() {
  for (int i = 0, j = 0; i < n; i++, j = 0)
    while (s[i][j]) freq[i][s[i][j++] - 'a']++;
  for (int i = 1, bits_count; i < 1 << n; i++) {
    bits_count = 0;
    for (int j = 0; j < C; j++) ctr[j] = M;
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j))) continue;
      bits_count++;
      for (int k = 0; k < C; k++) ctr[k] = min(ctr[k], freq[j][k]);
    }
    dp[i] = 1;
    for (int j = 0; j < C; j++) dp[i] = dp[i] * 1ll * (ctr[j] + 1) % M;
    dp[i] = (bits_count & 1) ? dp[i] : M - dp[i];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 1 << n; j++)
      if ((j ^ (1 << i)) < j) dp[j] = (dp[j] + dp[j ^ (1 << i)]) % M;
  long long result = 0;
  for (int i = 1, k, sum; i < 1 << n; i++) {
    k = sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        k++;
        sum += j + 1;
      }
    }
    result ^= dp[i] * 1ll * sum * k;
  }
  cout << result << endl;
}
signed main() {
  int t = 1;
  while (t--) {
    read();
    solve();
  }
  return 0;
}
