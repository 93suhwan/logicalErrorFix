#include <bits/stdc++.h>
namespace opal {
using namespace std;
void print() { cout << "\n"; }
template <typename first_type, typename... Args>
void print(first_type f, Args... args) {
  cout << f;
  print(args...);
}
void _print() { cout << ""; }
template <typename first_type, typename... Args>
void _print(first_type f, Args... args) {
  cout << f;
  _print(args...);
}
void ios_base() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void setprecision(int x) { cout << std::setprecision(x) << fixed; }
void read(string s) { freopen(s.c_str(), "r", stdin); }
void write(string s) { freopen(s.c_str(), "w", stdout); }
}  // namespace opal
using namespace opal;
int32_t main() {
  opal::ios_base();
  long long _;
  cin >> _;
  while (_--) {
    string s;
    cin >> s;
    long long Answer = 0;
    bool k = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0' && !k) {
        k = 1;
        Answer++;
      }
      if (s[i] == '1') {
        k = 0;
      }
    }
    cout << min(2LL, Answer) << '\n';
  }
  return 0;
}
