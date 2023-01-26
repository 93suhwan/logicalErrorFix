#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const long long INF = 1e9 + 10;
long long MOD = 998244353;
long double EPS = 1e-12;
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long t, n, a[MAXN];
vector<long long> poses[MAXN];
long long dp1[MAXN], dp2[MAXN];
long long sum(long long x, long long y) { return (x + y) % MOD; }
int main() {
  fastIO();
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n; i++) {
      poses[i].clear();
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      poses[a[i]].push_back(i);
    }
    fill(dp1, dp1 + n, 0);
    fill(dp2, dp2 + n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int pos = lower_bound(poses[a[i]].begin(), poses[a[i]].end(), i) -
                poses[a[i]].begin();
      if (pos > 0) {
        dp1[i] = dp1[poses[a[i]][pos - 1]];
        dp2[i] = dp2[poses[a[i]][pos - 1]];
      }
      if (a[i] > 0) {
        int pos_prev =
            lower_bound(poses[a[i] - 1].begin(), poses[a[i] - 1].end(), i) -
            poses[a[i] - 1].begin() - 1;
        if (pos_prev >= 0) {
          dp1[i] = sum(dp1[i], dp1[poses[a[i] - 1][pos_prev]]);
        }
      } else {
        dp1[i] = sum(dp1[i], 1);
      }
      if (a[i] > 1) {
        int pos_prev =
            lower_bound(poses[a[i] - 2].begin(), poses[a[i] - 2].end(), i) -
            poses[a[i] - 2].begin() - 1;
        if (pos_prev >= 0) {
          dp2[i] = sum(dp2[i], dp1[poses[a[i] - 2][pos_prev]]);
        }
      } else if (a[i] == 1) {
        dp2[i] = sum(dp2[i], 1);
      }
      if (pos > 0) {
        dp1[i] = sum(dp1[i], dp1[poses[a[i]][pos - 1]]);
        dp2[i] = sum(dp2[i], dp2[poses[a[i]][pos - 1]]);
      }
      if (pos == poses[a[i]].size() - 1) {
        ans = sum(ans, dp1[i]);
        ans = sum(ans, dp2[i]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
