#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 998244353;
const long long inf = 1e18 + 5;
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << p.first << ' ' << p.second << '\n';
  return os;
}
void read() {
  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);
}
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  if (n & 1) {
    cout << "NO";
    return;
  } else {
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[i + n / 2]) {
        cout << "NO";
        return;
      }
    }
    cout << "YES";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int32_t T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
  cerr << "\nTime elapsed:" << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
