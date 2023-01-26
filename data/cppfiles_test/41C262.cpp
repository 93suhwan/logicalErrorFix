#include <bits/stdc++.h>
using namespace std;
template <typename T>
void umax(T &a, const T b) {
  if (a < b) a = b;
}
template <typename T>
void umin(T &a, const T b) {
  if (a > b) a = b;
}
void solve_problem() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<vector<int>> pref;
  for (char a : {'a', 'b', 'c'}) {
    for (char b : {'a', 'b', 'c'}) {
      for (char c : {'a', 'b', 'c'}) {
        if (a != b && a != c && b != c) {
          pref.emplace_back(n + 1);
          for (int i = 0; i < n; i++) {
            char d = (i % 3 == 0 ? a : (i % 3 == 1 ? b : c));
            pref.back()[i + 1] = pref.back()[i] + (s[i] != d);
          }
        }
      }
    }
  }
  int P = (int)(pref).size();
  while (m--) {
    int L, R;
    cin >> L >> R;
    int ans = 1e9 + 7;
    for (int i = 0; i < P; ++i) {
      umin(ans, pref[i][R] - pref[i][L - 1]);
    }
    cout << ans << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.exceptions(cin.failbit);
  cin.tie(0);
  int T = 1;
  for (int tc = 0; tc < T; ++tc) {
    solve_problem();
  }
}
