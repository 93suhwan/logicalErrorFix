#include <bits/stdc++.h>
using namespace std;
const int N = 20, LEN = 4e5 + 100;
string a[N];
int dp[2][1 << N], bal[1 << N], bal_s[N], min_bal[N];
vector<int> where[N][LEN * 2];
pair<int, bool> go(int i, int b, bool f) {
  int val;
  if (f) {
    val = 0;
  } else {
    int pos = where[i][-b - 1 + LEN].empty() ? INT32_MAX
                                             : where[i][-b - 1 + LEN].front();
    val =
        lower_bound(where[i][-b + LEN].begin(), where[i][-b + LEN].end(), pos) -
        where[i][-b + LEN].begin();
  }
  bool f_to = f || b + min_bal[i] < 0;
  return {val, f_to};
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int b = 0;
    for (int j = 0; j < (int)a[i].size(); j++) {
      if (a[i][j] == '(')
        b++;
      else
        b--;
      min_bal[i] = min(min_bal[i], b);
      where[i][b + LEN].push_back(j);
    }
    bal_s[i] = b;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        bal[mask] = bal[mask ^ (1 << i)] + bal_s[i];
        break;
      }
    }
    for (int f = 0; f < 2; f++) {
      for (int i = 0; i < n; i++) {
        if (((mask >> i) & 1) == 0) {
          auto [val, f_to] = go(i, bal[mask], f);
          dp[f_to][mask | (1 << i)] =
              max(dp[f_to][mask | (1 << i)], dp[f][mask] + val);
        }
      }
    }
  }
  cout << max(dp[0][(1 << n) - 1], dp[1][(1 << n) - 1]) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
