#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long N = 1e2 + 5;
long long freq[N], n, k;
vector<long long> v[N];
void dfs(long long z, long long p, long long d = 1) {
  freq[d]++;
  for (long long x : v[z])
    if (x ^ p) dfs(x, z, d + 1);
}
void test_case() {
  cin >> n >> k;
  for (long long i = 1; i < n + 1; i++) v[i].clear();
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << "\n";
    return;
  }
  long long ans = 0;
  for (long long center = 1; center < n + 1; center++) {
    vector<vector<long long>> cnt(n + 1);
    for (long long x : v[center]) {
      memset(freq, 0, sizeof freq);
      dfs(x, center);
      for (long long j = 0; j < n; j++) {
        if (freq[j]) cnt[j].push_back(freq[j]);
      }
    }
    for (long long dep = 0; dep < n; dep++) {
      vector<long long> dp(k + 1);
      dp[0] = 1;
      for (long long x : cnt[dep]) {
        for (long long j = k - 1; j >= 0; j--) {
          dp[j + 1] = (dp[j + 1] + dp[j] * x) % 1000000007;
        }
      }
      ans = (ans + dp[k]) % 1000000007;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    test_case();
  }
  return 0;
}
