#include <bits/stdc++.h>
using namespace std;
const bool DEBUG = true;
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> a) {
  os << "[";
  for (int i = 0; i < a.size() - 1; i++) {
    os << a[i] << ", ";
  }
  os << a[a.size() - 1] << "]";
  return os;
}
template <typename T>
void debug(T obj) {
  if (DEBUG == true) {
    cout << obj << "\n";
  }
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      cout << i + 1 << ' ' << i + 2 << "\n";
      return;
    }
  }
  cout << -1 << ' ' << -1 << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
