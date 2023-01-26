#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
void solve() {
  int n, k;
  cin >> n >> k;
  constexpr int INF = 1e9;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    a[i] = i - a[i] >= 0 ? i - a[i] : INF;
  }
  int ans = INF;
  for (int i = 0; i < n; i++) {
    if (a[i] == INF) continue;
    vector<int> dp{i};
    for (int j = i + 1; j < n; j++) {
      if (a[j] == INF) continue;
      if (a[j] - a[dp.back()] < j - dp.back() && a[j] >= a[dp.back()]) {
        dp.push_back(j);
      } else {
        int L = 0, R = dp.size();
        while (L < R) {
          int mid = (L + R) / 2;
          if (a[dp[mid]] > a[j]) {
            R = mid;
          } else {
            L = mid + 1;
          }
        }
        if (R < dp.size()) {
          dp[R] = j;
        }
      }
    }
    if (dp.size() >= k) {
      ans = min(ans, a[dp[k - 1]]);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
