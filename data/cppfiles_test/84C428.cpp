#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
T min_(T a, T b) {
  return a > b ? b : a;
}
template <typename T, typename... Ts>
T min_(T first, Ts... last) {
  return min_(first, min_(last...));
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <class T, class S>
std::ostream& operator<<(std::ostream& os, const std::pair<T, S>& t) {
  os << "(" << t.first << ", " << t.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last) out << ", ";
  }
  out << "]";
  return out;
}
void solve() {
  int n, s;
  cin >> n >> s;
  n -= (n + 1) / 2 - 1;
  cout << s / n << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
