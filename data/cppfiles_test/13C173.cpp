#include <bits/stdc++.h>
using namespace std;
constexpr bool DEBUG = 1;
template <typename T>
void _debug(const T &x) {
  cerr << "[ " << x << " ]\n ";
}
template <typename T, typename... tail_types>
inline void _debug(const T &x, tail_types... tail) {
  cerr << "[" << x << "], ";
  _debug(tail...);
}
template <typename T>
inline void bye(const T &s) {
  cout << s << "\n";
  exit(0);
}
template <typename T>
T ceil(const T &x1, const T &x2) {
  return 1 + (x1 - 1) / x2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool y = (count(s.begin(), s.end(), 'A') +
              count(s.begin(), s.end(), 'C')) == count(s.begin(), s.end(), 'B');
    cout << (y ? "YES\n" : "NO\n");
  }
}
