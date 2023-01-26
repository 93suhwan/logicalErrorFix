#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 5e5 + 10, M = 2 * N, mod = 998244353;
int n;
int a[N];
pair<int, int> mp[2][100010];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long res = 0;
  a[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    for (int l = 1, r; l <= a[i]; l = r + 1) {
      r = a[i] / (a[i] / l);
      mp[i & 1][a[i] / l] = {0, 0};
    }
    mp[i & 1][a[i]] = {1, 0};
    for (int l = 1, r; l <= a[i + 1]; l = r + 1) {
      r = a[i + 1] / (a[i + 1] / l);
      int val = (a[i + 1] / l);
      pair<int, int> &it = mp[(i + 1) & 1][a[i + 1] / l];
      if (it.first == 0) continue;
      int k = (a[i] + val - 1) / val;
      int val1 = a[i] / k;
      mp[i & 1][val1].second =
          (mp[i & 1][val1].second + (long long)it.first * (k - 1) + it.second) %
          mod;
      mp[i & 1][val1].first = (mp[i & 1][val1].first + it.first) % mod;
    }
    for (int l = 1, r; l <= a[i]; l = r + 1) {
      r = a[i] / (a[i] / l);
      pair<int, int> &it = mp[i & 1][a[i] / l];
      if (it.first == 0) continue;
      res += it.second;
      if (res >= mod) res %= mod;
    }
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
