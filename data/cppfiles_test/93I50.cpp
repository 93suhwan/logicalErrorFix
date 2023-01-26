#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
template <class T = i32>
using V = vector<T>;
template <class T1, class T2>
using P = pair<T1, T2>;
template <class T>
void read(T& a) {
  cin >> a;
}
template <class T1, class... T2>
void read(T1& a, T2&... b) {
  cin >> a;
  read(b...);
}
const long double pi = 3.14159265358979323846;
const char* SYSTEM_COLORS[] = {"\x1b[32m", "\u001b[31m"};
i32 color_ptr = 0;
void solve();
i32 main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(15);
  solve();
  return 0;
}
void solve() {
  i32 TT;
  read(TT);
  while (TT--) {
    [&]() {
      i64 n, k;
      read(n, k);
      n--;
      i64 ans = 0;
      for (int tm = 1; n > 0; ++tm) {
        if (tm >= k) {
          ans += (n + k - 1) / k;
          n = 0;
        } else {
          ans++;
          n = max((i64)0, n - tm);
        }
      }
      cout << ans << "\n";
    }();
  }
}
