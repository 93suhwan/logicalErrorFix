#include <bits/stdc++.h>
using namespace std;
template <class T, class G>
ostream &operator<<(ostream &os, const pair<T, G> &para) {
  os << para.first << " " << para.second;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (const T &el : vec) os << el << " ";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  for (const T &el : vec) os << el << " ";
  return os;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  const int INF = 1e9;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int> > dp(n + 1, vector<int>(6000, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      for (int j = 0; j < 6000; j++) {
        if (dp[i][j] <= INF) {
          if (j + a < 6000) {
            int len = dp[i][j];
            if (len >= j + a) {
              dp[i + 1][j + a] = min(dp[i + 1][j + a], len);
            } else {
              dp[i + 1][j + a] = j + a;
            }
          }
          if (j - a >= 0) {
            dp[i + 1][j - a] = min(dp[i + 1][j - a], dp[i][j]);
          } else {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + a - j);
          }
        }
      }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
  }
  return 0;
}
