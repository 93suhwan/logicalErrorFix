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
      if (k == 1) {
        cout << n << "\n";
        return;
      }
      i64 l = 1, r = 1e9 + 1;
      auto f = [&](i64 x) { return x * (x + 1) / 2; };
      while (l + 1 < r) {
        i64 m = (l + r) / 2;
        if (f(m) > n)
          r = m;
        else
          l = m;
      }
      if (l <= k) {
        if (l * (l + 1) / 2 < n) {
          cout << l + 1 << "\n";
        } else {
          cout << l << "\n";
        }
      } else {
        i64 m = n - f(k);
        cout << (m + k - 1) / k << "\n";
      }
    }();
  }
}
