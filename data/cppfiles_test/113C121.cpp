#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;
using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using ld = long double;
const int N = 8e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ld eps = 1e-18;
const i64 INF = 0x3f3f3f3f3f3f3f3f;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
void file() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}
i64 bin_exp(i64 a, i64 p) {
  i64 res;
  for (res = 1; p; p >>= 1) {
    if (p & 1) res = res * a;
    a = a * a;
  }
  return res;
}
i64 p1, p2, x1, x2;
void Solve() {
  cin >> x1 >> p1 >> x2 >> p2;
  tie(p1, p2) = make_pair(p1 - min(p1, p2), p2 - min(p1, p2));
  if (!p1) {
    if ((i64)log10(x1) > p2 + (i64)log10(x2)) {
      cout << ">" << '\n';
    } else if ((i64)log10(x1) < p2 + (i64)log10(x2)) {
      cout << "<" << '\n';
    } else {
      if (x1 > x2 * bin_exp(10, p2)) {
        cout << ">" << '\n';
      } else if (x1 < x2 * bin_exp(10, p2)) {
        cout << "<" << '\n';
      } else {
        cout << "=" << '\n';
      }
    }
  } else {
    if ((i64)log10(x1) + p1 > (i64)log10(x2)) {
      cout << ">" << '\n';
    } else if ((i64)log10(x1) + p1 < (i64)log10(x2)) {
      cout << "<" << '\n';
    } else {
      if (x1 * bin_exp(10, p1) > x2) {
        cout << ">" << '\n';
      } else if (x1 * bin_exp(10, p1) < x2) {
        cout << "<" << '\n';
      } else {
        cout << "=" << '\n';
      }
    }
  }
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
}
