#include <bits/stdc++.h>
using namespace std;
constexpr int kN = 1e6 + 10;
int dp[kN][2][2];
pair<int, int> prefix[kN][2][2];
void Solve() {
  constexpr int kInf = 1e9;
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) dp[i][j][k] = kInf;
    }
  }
  dp[0][0][0] = dp[0][0][1] = -kInf;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++)
        if (dp[i][j][k] != kInf) {
          int x = k == 0 ? p[i] : -p[i];
          int y = dp[i][j][k];
          if (x < y) swap(x, y);
          for (int o = 0; o < 2; o++) {
            int new_x = o == 0 ? p[i + 1] : -p[i + 1];
            if (new_x > x) {
              if (dp[i + 1][0][o] > y) {
                dp[i + 1][0][o] = y;
                prefix[i + 1][0][o] = make_pair(j, k);
              }
            } else if (new_x > y) {
              if (dp[i + 1][1][o] > x) {
                dp[i + 1][1][o] = x;
                prefix[i + 1][1][o] = make_pair(j, k);
              }
            }
          }
        }
    }
  }
  int nj = -1, nk = -1;
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 2; k++) {
      if (dp[n - 1][j][k] != kInf) nj = j, nk = k;
    }
  }
  if (nj == -1 && nk == -1) {
    cout << "NO\n";
    return;
  }
  vector<int> a(n);
  for (int i = n - 1; i >= 0; i--) {
    a[i] = nk == 0 ? p[i] : -p[i];
    tie(nj, nk) = prefix[i][nj][nk];
  }
  cout << "YES\n";
  for (auto x : a) cout << x << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
