#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
void debug() { cerr << '\n'; }
template <typename T, typename... Ts>
void debug(T x, Ts... y) {
  cerr << "\033[31m" << x << "\033[0m";
  if (sizeof...(y) > 0) cerr << ' ';
  debug(y...);
}
template <typename T>
void debug(const T& a, int l, int r, char c) {
  for (int i = l; i <= r; ++i)
    cerr << "\033[31m" << a[i] << "\033[0m" << (i == r ? '\n' : c);
}
template <typename T>
void debug(vector<T> a) {
  for (int i = 0; i < (int)a.size(); ++i)
    cerr << "\033[31m" << a[i] << "\033[31m"
         << " \n"[i == ((int)a.size() - 1)];
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int c1 = 0, c0 = 0;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        if (a[i] == '1')
          ++c1;
        else
          ++c0;
      }
    }
    if (c1 == c0) ans = min(ans, c1 + c0);
    c1 = 0, c0 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == b[i]) {
        if (a[i] == '0')
          ++c1;
        else
          ++c0;
      }
    }
    if (c1 == c0 - 1) ans = min(ans, c1 + c0);
    if (ans == 0x3f3f3f3f)
      cout << "-1\n";
    else
      cout << ans << '\n';
  }
  return 0;
}
