#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lowbit(T x) {
  return x & -x;
}
template <typename S, typename T>
void debug(S s, T t) {
  cerr << s << " == " << t << '\n';
}
template <typename T>
void debug(T t) {
  cerr << t << '\n';
}
template <typename T>
void debug(T t[], long long st, long long ed) {
  for (long long i = st; i <= ed; ++i) {
    cerr << t[i] << " ";
  }
  cerr << '\n';
}
template <typename T>
void debug(const vector<T>& t) {
  for (long long i = 0; i < t.size(); ++i) cerr << t[i] << " ";
  cerr << '\n';
}
const long long N = 2e5 + 10;
void solve() {
  long long x, y;
  cin >> x >> y;
  if (y < x)
    cout << x + y << '\n';
  else if (x == y)
    cout << x << '\n';
  else
    cout << y - (y % x) / 2 << '\n';
}
signed main() {
  long long _;
  cin >> _;
  while (_--) solve();
  return 0;
}
