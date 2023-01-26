#include <bits/stdc++.h>
using namespace std;
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  if ((int)(s.size())) {
    setIn(s + ".in"), setOut(s + ".out");
  }
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }
const int inf = 1e9 + 5;
const int N = 1e6 + 5;
int dp[N][2][2];
pair<int, int> from[N][2][2];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  for (int i = 0; i <= n; ++i) {
    for (int x = 0; x < 2; ++x)
      for (int y = 0; y < 2; ++y) dp[i][x][y] = inf;
  }
  dp[0][0][0] = dp[0][0][1] = -inf;
  for (int i = 0; i < n - 1; ++i) {
    for (int is_x = 0; is_x < 2; ++is_x) {
      for (int sg = 0; sg < 2; ++sg)
        if (dp[i][is_x][sg] != inf) {
          int x = sg ? a[i] : -a[i];
          int y = dp[i][is_x][sg];
          if (is_x) swap(x, y);
          for (int ng = 0; ng < 2; ++ng) {
            int lst = ng ? a[i + 1] : -a[i + 1];
            if (lst > x) {
              if (dp[i + 1][0][ng] > y) {
                dp[i + 1][0][ng] = y;
                from[i + 1][0][ng] = {is_x, sg};
              }
            } else if (lst > y) {
              if (dp[i + 1][1][ng] > x) {
                dp[i + 1][1][ng] = x;
                from[i + 1][1][ng] = {is_x, sg};
              }
            } else {
            }
          }
        }
    }
  }
  int is_x = -1, sg = -1;
  for (int x = 0; x < 2; ++x)
    for (int y = 0; y < 2; ++y) {
      if (dp[n - 1][x][y] != inf) {
        is_x = x, sg = y;
      }
    }
  if (sg == -1) {
    cout << "NO\n";
    return;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (!sg) a[i] *= -1;
    tie(is_x, sg) = from[i][is_x][sg];
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int TestCases = 1;
  cin >> TestCases;
  for (int TestCase = 1; TestCase <= TestCases; ++TestCase) {
    solve();
  }
  return 0;
}
