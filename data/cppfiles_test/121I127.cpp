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
    int c0 = 0;
    for (auto it : a)
      if (it == '0') c0++;
    int c1 = 0;
    for (auto it : b)
      if (it == '0') ++c1;
    if ((c0 == n && c1 != n) || (c0 == 0 && c1 != n - 1))
      cout << "-1\n";
    else {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) ++cnt;
      }
      if (!cnt)
        cout << "-1\n";
      else
        cout << min(cnt, n - cnt) << '\n';
    }
  }
  return 0;
}
