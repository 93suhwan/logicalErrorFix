#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
  if (x < y) x = y;
}
mt19937 rnd(time(0));
pair<int, int> lst;
string out(int x, int y) {
  cout << x << ' ' << y << endl;
  lst = {x, y};
  string s;
  cin >> s;
  return s;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  int t;
  cin >> t;
  while (t--) {
    int rw = 1;
    auto nw = out(1, 1);
    if (nw == "Done") continue;
    bool dd = 0;
    while (nw.substr(0, 4) == "Down") {
      rw++;
      nw = out(rw, 1);
    }
    if (nw == "Done") continue;
    int str = rw;
    int enn = 2;
    while (rw <= 8) {
      bool fuck = 0;
      for (int j = enn; j <= 8; ++j) {
        if (make_pair(rw, j) == lst) continue;
        auto ff = out(rw, j);
        if (ff == "Done") {
          dd = 1;
          break;
        }
        if (ff.substr(0, 4) == "Down") {
          auto kok = out(rw + 1, j);
          if (kok == "Done") {
            dd = 1;
            break;
          }
          fuck = 1;
          break;
        } else if (ff.substr(0, 2) == "Up") {
          j = 0;
        }
      }
      if (!fuck)
        ++rw, enn = 9 - enn;
      else
        enn = 1;
      if (dd) break;
    }
    if (dd) continue;
  }
}
