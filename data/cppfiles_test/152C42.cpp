#include <bits/stdc++.h>
const int MAXN = 1000005;
const long long INF = (long long)1e9 + 8763;
using namespace std;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T, vector<T>, less<T>>;
struct State {
  int j, k;
};
int n, P[MAXN];
int dp[MAXN][2][2];
State from[MAXN][2][2];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> P[i];
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  dp[1][0][0] = -INF;
  from[1][0][0] = {0, 0};
  dp[1][0][1] = -INF;
  from[1][0][1] = {0, 0};
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        if (dp[i][j][k] == INF) continue;
        int x = P[i], y = dp[i][j][k];
        if (k) x *= -1;
        if (j) swap(x, y);
        assert(x > y);
        for (int t = 0; t <= 1; t++) {
          int nxt = (t ? -P[i + 1] : P[i + 1]);
          assert(nxt != x && nxt != y);
          if (nxt > x) {
            if (dp[i + 1][0][t] > y) {
              dp[i + 1][0][t] = y;
              from[i + 1][0][t] = {j, k};
            }
          } else if (nxt > y) {
            if (dp[i + 1][1][t] > x) {
              dp[i + 1][1][t] = x;
              from[i + 1][1][t] = {j, k};
            }
          }
        }
      }
    }
  }
  State ans = {-1, -1};
  for (int j = 0; j <= 1; j++) {
    for (int k = 0; k <= 1; k++) {
      if (dp[n][j][k] != INF) {
        ans = {j, k};
        break;
      }
    }
  }
  if (ans.j != -1) {
    cout << "YES\n";
    for (int i = n; i >= 1; i--) {
      if (ans.k) {
        P[i] *= -1;
      }
      ans = from[i][ans.j][ans.k];
    }
    for (int i = 1; i <= n; i++) {
      cout << P[i] << " \n"[i == n];
    }
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
