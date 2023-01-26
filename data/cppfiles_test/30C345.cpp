#include <bits/stdc++.h>
using namespace std;
using str = string;
using B = bool;
using I = int;
template <class T>
inline void Dbg(const str& s, T&& a) {
  cerr << s << " = " << a << endl;
}
template <class T, class... Ts>
void Dbg(const str& s, T&& a, Ts&&... aa) {
  auto b = s.find(',');
  cerr << s.substr(0, b) << " = " << a << ", ", Dbg(s.substr(b + 2), aa...);
}
template <class T>
inline void Mx(T& x, T y) {
  x = x > y ? x : y;
}
template <class T>
inline void Mn(T& x, T y) {
  x = x < y ? x : y;
}
using db = double;
using pii = pair<I, I>;
void Solve();
signed main() {
  ios::sync_with_stdio(0), cin.tie(nullptr);
  Solve();
}
constexpr I M = 1e5 + 5, Inf = 0x3f3f3f3f;
using bs = bitset<M>;
using arr = array<I, M>;
void Solve() {
  I T;
  cin >> T;
  for (I kase = 1; kase <= T; ++kase) {
    I n;
    str s;
    cin >> n >> s;
    I ans = Inf;
    for (I i = 0; i < 26; ++i) {
      char c = 'a' + i;
      I l = 0, r = n - 1, cur = 0;
      while (l <= r) {
        if (s[l] == s[r])
          ++l, --r;
        else if (s[l] == c)
          ++l, ++cur;
        else if (s[r] == c)
          --r, ++cur;
        else {
          cur = Inf;
          break;
        }
      }
      Mn(ans, cur);
    }
    if (ans == Inf)
      cout << -1;
    else
      cout << ans;
    cout << '\n';
  }
}
