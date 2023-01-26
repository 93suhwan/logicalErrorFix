#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
vector<T> make_unique(vector<T> a) {
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  return a;
}
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 0; i < (int)(n); i++) cin >> a[i + 1];
    ++n;
    vector<vector<int> > dp(k + 1, vector<int>(n));
    for (int i = 0; i < (int)(k + 1); i++)
      for (int j = 0; j < (int)(n); j++) {
        if (i == 0) {
          dp[i][j] = 0;
          continue;
        }
        dp[i][j] = INF;
        for (int k = (int)(j + 1); k < ((int)n); k++) {
          int cost = a[j] - a[k] + k - j;
          if (k < n && cost < 0) continue;
          dp[i][j] = min(dp[i][j], cost + dp[i - 1][k]);
        }
      }
    auto ans = dp[k][0];
    if (ans >= INF) ans = -1;
    cout << ans << endl;
  }
  return 0;
}
